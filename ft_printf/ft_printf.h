/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:39:45 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/14 22:14:25 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putnbr(int n);
int		ft_putnbr_hex_lower_ll(long long n);
void	ft_putnbr_unsigned_int(int n);
void	ft_putnbr_hex_lower(int n);
void	ft_putnbr_hex_upper(int n);
void	ft_putstr(const char *str);
int		ft_putchar(int c);
int		ft_printf(const char *format, ...);

#endif
