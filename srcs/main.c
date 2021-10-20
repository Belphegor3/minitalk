/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 18:56:38 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/14 18:31:41 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction sa;
	sa.sa_handler = &handle_sigtstp;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	serveur();
	int x;
	x = getpid();
	//aff_msg();
	//scanf("%d", &x);
	//aff_msg();
	printf("---------------------server---------------------          ---------------------client---------------------\n\n");
	printf("-                    %d                     -          -                    %d                     -\n", x, x);
	printf("-                    %d                     -          -                    %d                     -\n", x, x);
	printf("-                    %d                     -          -                    %d                     -\n", x, x);
	printf("-                    %d                     -          -                    %d                     -\n", x, x);
	scanf("%d", &x);
}
