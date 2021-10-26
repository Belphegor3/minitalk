/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:50:37 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/18 16:50:31 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	static int	count;
	int			ret;

	if (c == 256)
	{
		ret = count;
		count = 0;
		return (ret);
	}
	count++;
	write(1, (char *)&c, 1);
	return (count);
}
