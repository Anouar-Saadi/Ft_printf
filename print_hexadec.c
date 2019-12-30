/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:39:16 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/24 15:11:17 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nlen(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static char		*convert_hex(unsigned int nbr)
{
	char	re;
	int		i;
	char	*hex;

	i = ft_nlen(nbr);
	if (!(hex = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	hex[i--] = '\0';
	if (nbr == 0)
		hex[i] = '0';
	while (nbr != 0)
	{
		re = nbr % 16;
		if (re < 10)
			hex[i] = 48 + re;
		else
			hex[i] = 87 + re;
		nbr = nbr / 16;
		i--;
	}
	return (hex);
}

static char		*ft_tooupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

static void		calcul_flags_hexa(t_var *var)
{
	var->lennbr = ft_nlen(var->hexadec);
	if (var->point == 1 && var->zeros == 0 && var->hexadec == 0)
		var->lennbr = 0;
	var->zeros = (var->zeros > var->lennbr) ? var->zeros - var->lennbr : 0;
	var->width = (var->width > var->zeros + var->lennbr) ?
		var->width - var->zeros - var->lennbr : 0;
}

void			print_hexadec(va_list args, t_var *var, char c)
{
	var->hexadec = va_arg(args, unsigned int);
	calcul_flags_hexa(var);
	if (var->minus == 0)
		print_width(var);
	if (var->zeros > 0)
		print_zeros(var);
	if (var->lennbr > 0)
	{
		var->tmp = convert_hex(var->hexadec);
		if (c == 'X')
			var->tmp = ft_tooupper(var->tmp);
		ft_putstr_fd(var->tmp, 1, var);
		free(var->tmp);
	}
	if (var->minus == 1)
		print_width(var);
}
