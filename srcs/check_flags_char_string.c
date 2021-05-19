/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_char_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 13:26:05 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 16:50:57 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*check_flag_zero_str(t_var *var, const char *format)
{
	var->zeros = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}

char		*check_precision_str(va_list args, t_var *var, const char *format)
{
	var->point = 1;
	format++;
	if (*format == '*')
	{
		var->prec = va_arg(args, int);
		format++;
	}
	else
		var->prec = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}

char		*check_flag_str(va_list args, t_var *var, const char *format)
{
	if (*format == '0')
		format = check_flag_zero_str(var, format);
	if (*format > '0' && *format <= '9')
		format = check_flag_width(var, format);
	if (*format == '-')
		format = check_flag_minus(var, format);
	if (*format == '*')
		format = check_flag_star(args, var, format);
	if (*format == '.')
		format = check_precision_str(args, var, format);
	return ((char*)format);
}
