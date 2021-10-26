/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower_ll.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 18:31:19 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/25 18:45:15 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_lower_ll(long long n)
{
	unsigned long long	x;

	x = n;
	if (x >= 16)
	{
		ft_putnbr_hex_lower_ll(x / 16);
		ft_putnbr_hex_lower_ll(x % 16);
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
	return (x);
}
