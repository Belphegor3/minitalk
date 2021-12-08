# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 21:49:20 by lfchouch          #+#    #+#              #
#    Updated: 2021/10/26 06:05:44 by lfchouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

SRC_S = server.c		\

SRC_C = client.c		\

OBJ_S = $(SRC_S:.c=.o)

OBJ_C = $(SRC_C:.c=.o)

CC = gcc

CFLAGS = -Werror -Wall -Wextra

INCLUDE		= -I./include/

PATH_PRINTF = ft_printf

PRINTF = libftprintf.a

all : $(NAME)

$(NAME):  %: %.o ${PATH_PRINTF}/$(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ 

${PATH_PRINTF}/$(PRINTF) : 
	make -C $(@D)

clean :
	rm -rf $(OBJ_S) $(OBJ_C)
	make fclean -C $(PATH_PRINTF)

fclean :	clean
	rm -rf $(NAME)

re :		fclean all

.PHONY :	all re clean fclean
