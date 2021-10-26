/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:05:02 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/26 05:59:02 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf/ft_printf.h"

char	ft_convert_bin_to_char(char *display)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (display[7] == '1')
		res += 1;
	if (display[6] == '1')
		res += 2;
	if (display[5] == '1')
		res += 4;
	if (display[4] == '1')
		res += 8;
	if (display[3] == '1')
		res += 16;
	if (display[2] == '1')
		res += 32;
	if (display[1] == '1')
		res += 64;
	if (display[0] == '1')
		res += 128;
	return (res);
}

void	handle_message_display(int sigusr)
{
	static char	display[8];
	static int	nb_bit = 1;
	static int	i = 0;
	static char	buf[10001];
	static int	j = 0;

	if (sigusr == SIGUSR1)
		display[i] = '1';
	if (sigusr == SIGUSR2)
		display[i] = '0';
	i++;
	if (nb_bit % 8 == 0)
	{
		buf[j++] = ft_convert_bin_to_char(display);
		i = -1;
		while (++i < 8)
			if (display[i] != '0')
				break ;
		if (i == 8)
			ft_printf("%s\n", buf);
		if (i == 8)
			j = 0;
		i = 0;
	}
	nb_bit++;
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		ft_printf("Don't put any argument\n");
		return (0);
	}
	ft_printf("-----------------------------\n");
	ft_printf("-----------SERVEUR-----------\n");
	ft_printf("-----------------------------\n");
	ft_printf("-           ");
	ft_printf("%d", getpid());
	ft_printf("           -\n");
	signal(SIGUSR1, handle_message_display);
	signal(SIGUSR2, handle_message_display);
	while (1)
		pause();
	return (0);
}
