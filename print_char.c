/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:39:44 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 14:13:39 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calcul_flags_char(t_var *var)
{
	var->width = (var->width) ? var->width - 1 : 0;
	var->zeros = (var->zeros) ? var->zeros - 1 : 0;
}

void		print_char(va_list args, t_var *var)
{
	var->character = va_arg(args, int);
	calcul_flags_char(var);
	if (var->minus == 0)
		print_width(var);
	if (var->zeros)
		print_zeros(var);
	ft_putchar_fd(var->character, 1, var);
	if (var->minus == 1)
		print_width(var);
}
