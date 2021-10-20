# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 17:53:50 by lfchouch          #+#    #+#              #
#    Updated: 2021/10/15 20:07:29 by lfchouch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a

SRC =	server.c					\
		client.c					\
		main.c						\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

INCDIR = includes

$(NAME) : $(OBJ)

%.o: %.c
				$(CC) $(CFLAGS) -I./$(INCDIR) -c $< -o $@

clean :
				rm -rf $(OBJ)

fclean : clean
				rm -rf $(NAME)

re : fclean all

.PHONY : fclean clean all re
