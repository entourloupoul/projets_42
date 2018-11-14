# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmasson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/14 14:39:35 by pmasson           #+#    #+#              #
#    Updated: 2018/11/14 14:39:41 by pmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJS = $(patsubst %.c,%.o,$(wildcard ft_*.c))
HEADER = libft.h
CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
