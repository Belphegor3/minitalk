/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 00:37:21 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/14 21:34:15 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex_lower(int n)
{
	long	x;

	x = n;
	if (n < 0)
		x = (2 * 2147483648) + n;
	if (x >= 16)
	{
		ft_putnbr_hex_lower(x / 16);
		ft_putnbr_hex_lower(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar(x + '0');
		if (x > 9 && x <= 15)
		{
			x = x - 10;
			ft_putchar(x + 'a');
		}
	}
}
