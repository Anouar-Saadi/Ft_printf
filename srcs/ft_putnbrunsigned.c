/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrunsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:57:52 by asaadi            #+#    #+#             */
/*   Updated: 2019/12/19 15:27:31 by asaadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrunsigned(unsigned int n, int fd, t_var *var)
{
	long int nbr;

	nbr = n;
	if (nbr > 9)
	{
		ft_putnbrunsigned((nbr / 10), fd, var);
		ft_putnbrunsigned((nbr % 10), fd, var);
	}
	else if (nbr >= 0 && nbr <= 9)
		ft_putchar_fd(nbr + '0', fd, var);
}
