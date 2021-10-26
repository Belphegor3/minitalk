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

NAME1 = server

NAME2 = client

SRC_S = server.c		\

SRC_C = client.c		\

OBJ_S = $(SRC_S.c=.o)

OBJ_C = $(SRC_C.c=.o)

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Werror -Wall -Wextra

INCLUDE		= -I./include/

PATH_PRINTF = ft_printf

PRINTF = libftprintf.a

%.o :		%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

all : $(NAME1) $(NAME2)

$(NAME1) : $(OBJ) $(OBJ_S)
	make -C $(PATH_PRINTF)
	cp $(PATH_PRINTF)/$(PRINTF) $(NAME1)
	$(CC) $(SRC_S) -o $(NAME1) $(OBJ) $(OBJ_S) $(PATH_PRINTF)/$(PRINTF)

$(NAME2) : $(OBJ) $(OBJ_C)
	cp $(PATH_PRINTF)/$(PRINTF) $(NAME2)
	$(CC) $(SRC_C) -o $(NAME2) $(OBJ) $(OBJ_C) $(PATH_PRINTF)/$(PRINTF)

clean :
	rm -rf $(OBJ_S) $(OBJ_C) $(OBJ)
	make clean -C $(PATH_PRINTF)

fclean :	clean
	rm -rf $(NAME1) $(NAME2)

re :		fclean all

.Phony :	all re clean fclean
