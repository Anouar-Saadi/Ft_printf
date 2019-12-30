/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:10:42 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 15:27:26 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calcul_flags_percen(t_var *var)
{
	var->width = (var->width) ? var->width - 1 : 0;
	var->zeros = (var->zeros) ? var->zeros - 1 : 0;
}

void		print_percentage(t_var *var)
{
	calcul_flags_percen(var);
	if (var->minus == 0)
		print_width(var);
	if (var->zeros)
		print_zeros(var);
	ft_putchar_fd('%', 1, var);
	if (var->minus == 1)
		print_width(var);
}
