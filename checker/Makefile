# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:28:09 by amarchal          #+#    #+#              #
#    Updated: 2022/01/17 13:43:08 by amarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

LIB = ../libft/libft.a

SRCS =	checker.c				\
		checker_utils.c 		\
		get_next_line.c			\
		get_next_line_utils.c	\
		rotate_checker.c		\
		rotate_two_checker.c	\
		switch_push_checker.c

HDRS = 	./checker.h				

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@
all: libft $(NAME)

libft:
	make -C ../libft

$(NAME): $(OBJS) $(LIB)
		$(CC) $(OBJS) $(LIB) -o $(NAME)
		
clean:
		rm -rf $(OBJS)
		make clean -C ../libft

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(LIB)

re:		fclean all

.PHONY:	all clean fclean re libft
