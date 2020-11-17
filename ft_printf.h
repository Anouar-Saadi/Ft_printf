/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:32:40 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 15:17:39 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

# include <stdarg.h>

# include <stdlib.h>

# include <stdio.h>

typedef	struct	s_var
{
	char				character;
	char				*str;
	char				*tmp;
	int					width;
	int					zeros;
	int					me_zeros;
	int					star;
	int					point;
	int					prec;
	int					lennbr;
	int					lenstr;
	int					minus;
	long				dec_int;
	unsigned int		hexadec;
	int					count;
	unsigned int		unsign;
	unsigned long long	address;
	int					j;
}				t_var;

int				ft_printf(const char *par, ...);

void			ft_putnbrunsigned(unsigned int n, int fd, t_var *var);

int				ft_nbrlen(int n);

void			print_dec_int(va_list args, t_var *var);

void			print_char(va_list args, t_var *var);

void			print_string(va_list args, t_var *var);

void			print_hexadec(va_list args, t_var *var, char c);

void			print_unsigned(va_list args, t_var *var);

void			print_address(va_list args, t_var *var);

void			print_percentage(t_var *var);

void			print_width(t_var *var);

void			print_zeros(t_var *var);

char			*check_flag_zero(t_var *var, const char *format);

char			*check_flag_zero_str(t_var *var, const char *format);

char			*check_flag_width(t_var *var, const char *format);

char			*check_flag_minus(t_var *var, const char *format);

char			*check_flag_star(va_list args, t_var *var, const char *format);

char			*check_flag(va_list args, t_var *var, const char *format);

char			*check_flag_str(va_list args, t_var *var, const char *format);

char			*check_precision(va_list args, t_var *var, const char *format);

char			*check_precision_str(va_list args, t_var *var,
		const char *format);

void			ft_conversion_args(va_list args, t_var *var,
		const char *format);

void			ft_putchar_fd(char c, int fd, t_var *var);

void			ft_putstr_fd(char *s, int fd, t_var *var);

void			ft_putnbr_fd(long nbr, int fd, t_var *var);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strdup(const char *s1);

int				ft_isdigit(int c);

int				ft_atoi(const char *s);

size_t			ft_strlen(const char *s);

#endif
