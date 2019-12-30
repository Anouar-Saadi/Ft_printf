/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:21:57 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/25 15:40:52 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long nbr, int fd, t_var *var)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd, var);
		nbr = nbr * -1;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd, var);
		ft_putnbr_fd((nbr % 10), fd, var);
	}
	else
		ft_putchar_fd(nbr + '0', fd, var);
}
