/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_sec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <asaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 14:19:36 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/29 12:38:53 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_precision(va_list args, t_var *var, const char *format)
{
	var->point = 1;
	format++;
	if (*format == '*')
	{
		var->prec = va_arg(args, int);
		if (var->zeros && var->prec >= 0)
			var->width = var->zeros;
		if (var->prec >= 0)
			var->zeros = var->prec;
		if (var->zeros < 0 && var->me_zeros)
		{
			var->zeros = var->prec;
			var->prec = 0;
			var->point = 0;
		}
		format++;
	}
	else
	{
		var->width = (var->zeros) ? var->zeros : var->width;
		var->zeros = ft_atoi(format);
	}
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}
