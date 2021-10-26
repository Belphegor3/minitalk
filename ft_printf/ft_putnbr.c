/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:08:07 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/14 21:34:32 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	unsigned int	x;

	x = n;
	if (n < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}
