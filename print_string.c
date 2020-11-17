/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 17:17:03 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 16:50:40 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		calcul_flags_str(t_var *var)
{
	var->lenstr = ft_strlen(var->str);
	if (var->prec < var->lenstr && var->point)
		var->str = ft_substr(var->str, 0, var->prec);
	else if (var->prec < var->lenstr && var->point)
		var->str = ft_substr(var->str, 0, var->prec);
	var->zeros = (var->zeros) ? var->zeros - ft_strlen(var->str) : 0;
	var->width = (var->width) ? var->width - ft_strlen(var->str) : 0;
}

void			print_string(va_list args, t_var *var)
{
	var->str = va_arg(args, char *);
	if (!var->str)
		var->str = "(null)";
	calcul_flags_str(var);
	if (var->minus == 0)
		print_width(var);
	if (var->zeros)
		print_zeros(var);
	ft_putstr_fd(var->str, 1, var);
	if (var->minus == 1)
		print_width(var);
	if (var->lenstr != (int)ft_strlen(var->str))
		free(var->str);
}
