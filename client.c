/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:41:29 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/26 06:00:51 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef IS_NUM
# define IS_NUM 0
#endif
#ifndef IS_NOT_NUM
# define IS_NOT_NUM 1
#endif

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	client_display(char *display, int server_pid, int i, int bit_shifting)
{
	while (++i <= ft_strlen(display))
	{
		bit_shifting = -1;
		while (++bit_shifting < 8)
		{
			if (display[i] & 0x80 >> bit_shifting)
			{
				if (kill(server_pid, SIGUSR1) == -1)
				{
					write(1, "Wrong PID\n", 10);
					exit(3);
				}
			}
			else
			{
				if (kill(server_pid, SIGUSR2) == -1)
				{
					write(1, "Wrong PID\n", 10);
					exit(4);
				}
			}
			usleep(100);
		}
	}
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	while (i[num])
	{
		if (!(num[i] >= 48 && num[i] <= 57))
			return (IS_NOT_NUM);
		i++;
	}
	return (IS_NUM);
}

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		  || nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
	}
	return (num * neg);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		write(1, "./client takes server PID and the message", 42);
		write(1, " that you want to send as parameters\n", 37);
		exit(1);
	}
	if (ac == 3 && ft_isnum(av[1]) == IS_NOT_NUM)
	{
		if (av[1][0] == '+')
		{
			write(1, "Don't put '+' on your PID, would you", 37);
			write(1, " write \"+2\" instead of \"2\"? No I don't think so!\n", 50);
		}
		else if (av[1][0] == '-')
			write(1, "PID isn't negative!\n", 20);
		else
			write(1, "PID is an integer!\n", 19);
		exit(2);
	}
	client_display(av[2], ft_atoi(av[1]), -1, -1);
	return (0);
}
