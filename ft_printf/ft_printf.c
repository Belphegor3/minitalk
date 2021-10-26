/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:32:48 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/14 21:34:01 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_part_one(const char format, va_list ap)
{
	unsigned char	c;
	char			*s;
	int				d;

	if (format == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		ft_putchar(c);
	}
	if (format == 's')
	{
		s = (char *)va_arg(ap, char *);
		if (s == NULL)
			s = "(null)";
		ft_putstr(s);
	}
	if (format == 'd' || format == 'i')
	{
		d = (unsigned int)va_arg(ap, int);
		ft_putnbr(d);
	}
}

void	ft_parse_part_two(const char format, va_list ap)
{
	int	hex;
	int	hex_upper;
	int	u;

	if (format == 'u')
	{
		u = (unsigned int)va_arg(ap, int);
		ft_putnbr_unsigned_int(u);
	}
	if (format == 'x')
	{
		hex = (unsigned int)va_arg(ap, int);
		ft_putnbr_hex_lower(hex);
	}
	if (format == 'X')
	{
		hex_upper = (unsigned int)va_arg(ap, int);
		ft_putnbr_hex_upper(hex_upper);
	}
	if (format == '%')
		ft_putchar('%');
}

void	ft_parse_part_three(const char format, va_list ap)
{
	unsigned long	addr;

	if (format == 'p')
	{
		addr = (unsigned long)va_arg(ap, void *);
		ft_putchar('0');
		ft_putchar('x');
		ft_putnbr_hex_lower_ll(addr);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list			ap;
	int				i;

	i = -1;
	va_start(ap, format);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			ft_parse_part_one(format[i], ap);
			ft_parse_part_two(format[i], ap);
			ft_parse_part_three(format[i], ap);
		}
		else
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (ft_putchar(256));
}
