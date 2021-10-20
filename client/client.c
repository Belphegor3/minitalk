/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:41:29 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/20 18:06:47 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../minitalk.h"

extern int	server_pid;
/*void	handle_sigusr1(void)
{
	;
}

void	handle_sigusr2(void)
{
	;
}*/

void	client_display(char *display, pid_t server_pid)
{
	int		i;
	char	c;

	i = 0;
	while (display[i])
	{
		i = 0;
		c = display[i];
		while (i < 8)
		{
			if (c & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			c >>= 1;
			i++;
			usleep(500);
		}
		display++;
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
	//client_pid = getpid();
	printf("%d\n", ft_atoi(av[1]));
	printf("%d\n", server_pid);
	write(1, "1", 1);
	if (ac != 3 || ft_isnum(av[1]) == IS_NOT_NUM || ft_atoi(av[1]) != server_pid)
	{
		if (ft_atoi(av[1]) != server_pid)
		{
			printf("\e[1;5;31mWrong PID\e[0m\n");
			exit(4);
		}
		if (av[1][0] == '+')
		{
			printf("\e[1;31mDon't put '+' on your PID, would you");
			printf(" write \"+2\" instead of \"2\"? No I don't think so!\e[0m\n");
		}
		else
		{
			printf("\e[1;31m./client takes server PID and the message");
			printf(" that you want to send as parameters\e[0m\n");
		}
		return (0);
	}
	//server_pid = ft_atoi(av[1]);
	write(1, "1", 1);
	client_display(av[2], ft_atoi(av[1]));
	client_display(0, server_pid);
	return (0);
}
