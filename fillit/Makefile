# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etlagors <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:23:33 by etlagors          #+#    #+#              #
#    Updated: 2018/11/21 11:20:46 by pmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fillit

SRC =	fillit_srcs/ft_backtrack_fillit.c\
		fillit_srcs/ft_create_pieces.c\
		fillit_srcs/ft_check_global.c\
		fillit_srcs/ft_get_file.c\
		fillit_srcs/ft_check_pieces.c\
		fillit_srcs/ft_carre.c\
		fillit_srcs/fillit.c\
		fillit_srcs/ft_free_tab.c
OBJS = $(SRC:%.c=%.o)		

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

HEADER = fillit_srcs/fillit.h

all: $(NAME)

$(NAME): $(LIB) $(HEADER) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -I libft/ -I fillit_srcs/ -L libft/ -lft

$(LIB):
	make -C libft/

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I libft/ -I fillit_srcs/ 

clean:
	rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all
