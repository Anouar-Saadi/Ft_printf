/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:03:22 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/27 12:00:26 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flag_width(t_var *var, const char *format)
{
	var->width = ft_atoi(format);
	var->minus = 0;
	if (var->width < 0)
	{
		var->minus = 1;
		var->width = var->width * -1;
	}
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}

char	*check_flag_zero(t_var *var, const char *format)
{
	var->j = 0;
	var->zeros = ft_atoi(format);
	var->me_zeros = var->zeros;
	while (ft_isdigit(*format))
		format++;
	return ((char*)format);
}

char	*check_flag_minus(t_var *var, const char *format)
{
	var->width = ft_atoi(format);
	format++;
	var->minus = 0;
	if (var->width < 0)
	{
		var->minus = 1;
		var->width = var->width * -1;
	}
	while (ft_isdigit(*format))
		format++;
	return ((char *)format);
}

char	*check_flag_star(va_list args, t_var *var, const char *format)
{
	var->star = va_arg(args, int);
	var->width = var->star;
	var->minus = 0;
	if (*(format - 1) == '-')
	{
		var->minus = 1;
		var->width *= -1;
	}
	if (var->width < 0)
	{
		var->minus = 1;
		var->width *= -1;
	}
	if (*(format - 1) == '0' && var->star > 0 && var->point == 0)
	{
		var->zeros = var->width;
		var->me_zeros = var->zeros;
		var->width = 0;
	}
	format++;
	return ((char*)format);
}

char	*check_flag(va_list args, t_var *var, const char *format)
{
	if (*format == '0')
		format = check_flag_zero(var, format);
	if (*format > '0' && *format <= '9')
		format = check_flag_width(var, format);
	if (*format == '-')
		format = check_flag_minus(var, format);
	if (*format == '*')
		format = check_flag_star(args, var, format);
	if (*format == '.')
		format = check_precision(args, var, format);
	return ((char*)format);
}
