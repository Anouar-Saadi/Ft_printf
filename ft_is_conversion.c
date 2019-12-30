/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 15:05:54 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 15:24:37 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_args(va_list args, t_var *var, const char *format)
{
	if (*format == '%')
		print_percentage(var);
	if (*format == 'd' || *format == 'i')
		print_dec_int(args, var);
	if (*format == 'c')
		print_char(args, var);
	if (*format == 's')
		print_string(args, var);
	if (*format == 'x' || *format == 'X')
		print_hexadec(args, var, *format);
	if (*format == 'u')
		print_unsigned(args, var);
	if (*format == 'p')
		print_address(args, var);
}
