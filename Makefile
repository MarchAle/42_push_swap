# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/23 12:28:09 by amarchal          #+#    #+#              #
#    Updated: 2022/01/17 17:50:25 by amarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = ./libft/libft.a

SRCS =	./SRCS/insertsort.c			\
		./SRCS/medians.c			\
		./SRCS/optimization.c		\
		./SRCS/push_swap.c			\
		./SRCS/push_swap_utils.c	\
		./SRCS/push_to_b.c			\
		./SRCS/quicksort.c			\
		./SRCS/rotate.c				\
		./SRCS/small_dataset.c		\
		./SRCS/switch_push.c

HDRS = 	./INCLUDES/push_swap.h

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

%.o : %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@
all: libft $(NAME) checker

libft:
	make -C ./libft

checker:
	make -C ./checker

$(NAME): $(OBJS) $(LIB)
		$(CC) $(OBJS) $(LIB) -o $(NAME)

clean:
		rm -rf $(OBJS)
		make clean -C ./libft
		make clean -C ./checker

fclean:	clean
		rm -rf $(NAME)
		rm -rf $(LIB)
		rm -rf ./checker/checker

re:		fclean all

.PHONY:	all clean fclean re libft checker
