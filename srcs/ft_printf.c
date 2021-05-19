/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <asaadi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 14:15:15 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/29 19:51:59 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_flags(va_list args, t_var *var, const char *format)
{
	while (*format != 'd' && *format != 'i' && *format != 's' && *format != 'c'
			&& *format != 'p' && *format != 'u' && *format != 'x'
			&& *format != 'X' && *format != '%')
	{
		var->j = 0;
		while (format[var->j] == '*' || ft_isdigit(format[var->j]) ||
				format[var->j] == '.' || format[var->j] == '-')
			var->j++;
		if (format[var->j] == 's' || format[var->j] == 'c'
				|| format[var->j] == '%')
			format = check_flag_str(args, var, format);
		else
			format = check_flag(args, var, format);
	}
	return ((char*)format);
}

int		ft_printf_sec(va_list args, const char *format)
{
	t_var	var;

	var.count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			var.width = 0;
			var.zeros = 0;
			var.point = 0;
			var.prec = 0;
			var.me_zeros = 0;
			var.minus = 0;
			format++;
			format = check_flags(args, &var, format);
			ft_conversion_args(args, &var, format);
		}
		else
			ft_putchar_fd(*format, 1, &var);
		format++;
	}
	return (var.count);
}

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		res;

	va_start(args, format);
	res = ft_printf_sec(args, format);
	va_end(args);
	return (res);
}
