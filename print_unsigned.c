/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 17:35:22 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/23 19:06:05 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_unsi_len(unsigned int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void		calcul_flags_uns(t_var *var)
{
	var->lennbr = ft_unsi_len(var->unsign);
	if (var->point == 1 && var->zeros == 0 && var->unsign == 0)
		var->lennbr = 0;
	var->zeros = (var->zeros > var->lennbr) ? var->zeros - var->lennbr : 0;
	var->width = (var->width > var->zeros + var->lennbr) ?
		var->width - var->zeros - var->lennbr : 0;
}

void			print_unsigned(va_list args, t_var *var)
{
	var->unsign = va_arg(args, unsigned int);
	calcul_flags_uns(var);
	if (var->minus == 0)
		print_width(var);
	if (var->zeros > 0)
		print_zeros(var);
	if (var->lennbr > 0)
		ft_putnbrunsigned(var->unsign, 1, var);
	if (var->minus == 1)
		print_width(var);
}
