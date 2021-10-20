/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 21:05:02 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/20 22:23:42 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

static int	server_pid;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

/*void	handle_sigint()
{
	static int	i;

	if (i < 2)
		printf("non non non trou du cul tu peux pas faire ca 💩 (essaye crtl + z)\n");
	else if (i == 4)
		printf("eh oh frerot crtl z je te rappel");
	else
	{
		printf("ATTEND...\nATTEND JTE DIS\n");
		sleep(1);
		printf("MAIS PUTAIN MAIS ARRETE DE SPAM TU VOIS BIEN QUE CA FONCTIONNE PAS!!!!!!\n");
	}
	i++;
}

void	handle_sigtstp()
{
	static int	i;

	if (i == 0)
		printf("le pire c'est que t'y as cru trou du cul 😈\n");
	else if (i == 1)
		printf("Sois pas con ca fonctionnera pas...\n");
	else if (i == 8)
		printf("T'es un acharné toi.......\n");
	else
		printf("Arrete de te faire du mal pour rien.......\n");
	i++;
}*/

void	handle_sigsegv()
{
	kill(0, 19);
}
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_display(char *display, char next_char)
{
	char	*joined;
	int		i;

	joined = malloc(ft_strlen(display) + 2);
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (display[i] != '\0' && display)
	{
		joined[i] = display[i];
		i++;
	}
	joined[i] = next_char;
	if (next_char != '\0' && next_char)
		joined[i + 1] = '\0';
	else
		joined[i] = '\0';
	return (joined);
}

char	*message_display(char *display, char next_char)
{
	display = ft_strjoin_display(display, next_char);
	if (!next_char)
	{
		ft_putstr(display);
		ft_putchar('\n');
		if (display)
		{
			free(display);
			display = NULL;
		}
	}
	return (display);
}

void	handle_message_display(int bin)
{
	static char	*final_display;
	static int	i;
	static char	next_final_display_char;

	next_final_display_char &= (bin << i++);
	if (i == 7)
	{
		final_display = message_display(final_display, next_final_display_char);
		i = 0;
		next_final_display_char = 0;
	}
}

void	server_display(void)
{
	server_pid = getpid();
	printf("\033[1;3;33m-----------------------------\033[0m\n");
	printf("\033[1;3;33m-----------SERVEUR-----------\033[0m\n");
	printf("\033[1;3;33m-----------------------------\033[0m\n");
	printf("\e[1;33m-\e[0m\e[1;36m           %d\e[0m\e[1;33m           -\e[0m\n", server_pid);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		printf("\e[1;5;31mDon't put any argument\e[0m\n");
		return (0);
	}
	server_display();
	//signal(SIGTSTP, &handle_sigtstp);
	//signal(SIGINT, &handle_sigint);
	signal(SIGSEGV, &handle_sigsegv);
	while (1)
	{
		signal(SIGUSR1, &handle_message_display);
		signal(SIGUSR2, &handle_message_display);
		pause();

	}
	return 0;
}
