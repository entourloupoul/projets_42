# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmasson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/09 09:08:27 by pmasson           #+#    #+#              #
#    Updated: 2019/01/25 17:53:50 by pmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap 

SRC1 = srcs/checker.c srcs/ft_push_swap_create_stack.c\
	   srcs/ft_push_swap_do_command.c srcs/push_swap_get_next_line.c\
	   srcs/ft_push_swap_free1.c srcs/push_swap_create_window.c\
	   srcs/push_swap_display.c srcs/push_swap_checker_normal.c\
	   srcs/push_swap_checker_visual.c srcs/push_swap_visual_command.c\
	   srcs/push_swap_destroy_window.c srcs/push_swap_display_check.c

SRC2 = srcs/push_swap.c srcs/ft_push_swap_create_stack.c\
	   srcs/push_swap_create_command.c srcs/ft_push_swap_do_command.c\
	   srcs/push_swap_write_do.c srcs/push_swap_med_sort.c\
	   srcs/push_swap_med2.c srcs/push_swap_med_tob.c\
	   srcs/push_swap_med_sort2.c srcs/push_swap_med_sort_zero.c

OBJS1 = $(SRC1:%.c=%.o)

OBJS2 = $(SRC2:%.c=%.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a

FRAMEWORK = -framework OpenGL -framework AppKit

HEADER = includes/push_swap.h includes/push_swap_get_next_line.h

all: $(NAME1) $(NAME2)

$(NAME1): $(LIB) $(LIBMLX) $(HEADER) $(OBJS1)
	$(CC) $(FLAGS) $(OBJS1) -o $(NAME1) -I libft/includes/ -I includes/	-I minilibx_macos/ -L libft/ -lft -L minilibx_macos/ -lmlx $(FRAMEWORK)

$(NAME2): $(LIB) $(HEADER) $(OBJS2)
	$(CC) $(FLAGS) $(OBJS2) -o $(NAME2) -I libft/includes/ -I includes/ -L libft/ -lft

$(LIB):
	make -C libft/

$(LIBMLX):
	make -C minilibx_macos/

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I libft/includes/ -I includes/

clean:
	rm -f $(OBJS1)
	rm -f $(OBJS2)
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)
	rm -f $(LIB)
	rm -f $(LIBMLX)

re: fclean all
