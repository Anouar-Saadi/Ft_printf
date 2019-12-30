/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 10:37:33 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/28 16:33:49 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_nlen_add(unsigned long long n)
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

static char		*convert_hex_add(unsigned long long nbr)
{
	char	re;
	int		i;
	char	*hex;

	i = ft_nlen_add(nbr);
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

static char		*ft_print_add(unsigned long long n, t_var *var)
{
	char *tmp;
	char *add;

	if (var->point == 0 || n != 0)
		tmp = convert_hex_add(n);
	else
		tmp = ft_strdup("");
	add = ft_strjoin("0x", tmp);
	return (add);
}

void			print_address(va_list args, t_var *var)
{
	var->address = va_arg(args, unsigned long long);
	var->tmp = ft_print_add(var->address, var);
	var->lenstr = ft_strlen(var->tmp);
	var->width = (var->width > var->lenstr) ? var->width - var->lenstr : 0;
	if (var->minus == 0)
		print_width(var);
	ft_putstr_fd(var->tmp, 1, var);
	if (var->minus == 1)
		print_width(var);
	free(var->tmp);
}
