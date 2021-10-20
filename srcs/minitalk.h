/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:03:00 by lfchouch          #+#    #+#             */
/*   Updated: 2021/10/20 18:51:42 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# ifndef IS_NUM
#  define IS_NUM 0
# endif
# ifndef IS_NOT_NUM
#  define IS_NOT_NUM 1
# endif

void	aff_msg();
void	handle_sigtstp();
void	serveur();
void	handle_sigusr1();
void	handle_sigusr2();
void	client();
int		ft_putnbr(char *str);
int		ft_strlen(char *str);
int		ft_server_pid();

#endif
