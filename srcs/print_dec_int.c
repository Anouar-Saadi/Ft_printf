/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 15:03:57 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 14:11:50 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		calcul_flags_dec(t_var *var)
{
	var->lennbr = ft_nbrlen(var->dec_int);
	if (var->point == 1 && var->zeros == 0 && var->dec_int == 0)
		var->lennbr = 0;
	if (var->dec_int < 0 && var->point == 0)
		var->lennbr++;
	var->zeros = (var->zeros > var->lennbr) ? var->zeros - var->lennbr : 0;
	if (var->dec_int < 0 && var->point == 1)
		var->lennbr++;
	var->width = (var->width > var->zeros + var->lennbr) ?
		var->width - var->zeros - var->lennbr : 0;
}

void			print_width(t_var *var)
{
	int i;

	i = var->width;
	while (i > 0)
	{
		ft_putchar_fd(' ', 1, var);
		i--;
	}
}

void			print_zeros(t_var *var)
{
	int i;

	i = var->zeros;
	while (i > 0)
	{
		ft_putchar_fd('0', 1, var);
		i--;
	}
}

void			print_dec_int(va_list args, t_var *var)
{
	var->dec_int = (long)va_arg(args, int);
	calcul_flags_dec(var);
	if (var->minus == 0)
		print_width(var);
	if (var->dec_int < 0)
	{
		var->dec_int = -var->dec_int;
		ft_putchar_fd('-', 1, var);
	}
	if (var->zeros > 0)
		print_zeros(var);
	if (var->lennbr > 0)
		ft_putnbr_fd(var->dec_int, 1, var);
	if (var->minus == 1)
		print_width(var);
}
