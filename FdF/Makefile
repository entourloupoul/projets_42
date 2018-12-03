# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmasson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 11:35:49 by pmasson           #+#    #+#              #
#    Updated: 2018/11/30 18:03:37 by pmasson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf_srcs/ft_calc_mat.c\
	  fdf_srcs/ft_convert_base_fdf.c\
	  fdf_srcs/ft_correct_file.c\
	  fdf_srcs/ft_create_matrice.c\
	  fdf_srcs/ft_fdf_get_file.c\
	  fdf_srcs/ft_free_fn.c\
	  fdf_srcs/ft_free_fn2.c\
	  fdf_srcs/ft_iso_proj.c\
	  fdf_srcs/ft_mat_first_proj.c\
	  fdf_srcs/ft_paral_proj.c\
	  fdf_srcs/ft_put_seg_image.c\
	  fdf_srcs/ft_tab_length.c\
	  fdf_srcs/ft_trace_seg_image.c\
	  fdf_srcs/main.c\
	  fdf_srcs/ft_deal_key.c\
	  fdf_srcs/ft_destroy.c\
	  fdf_srcs/ft_putstr_inf.c\
	  get_next_line/get_next_line.c

OBJ = $(SRC:%.c=%.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra -fsanitize=address

LIBFT = libft/libft.a

LIBMLX = minilibx_macos/libmlx.a

HEADER = fdf_srcs/fdf.h

FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(LIBMLX) $(HEADER) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I libft/includes -I fdf_srcs/ -I get_next_line/ -I minilibx_macos/ -L libft/ -lft -L minilibx_macos/ -lmlx $(FRAMEWORK)

$(LIBFT):
	make -C libft/

$(LIBMLX):
	make -C minilibx_macos/

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I libft/includes -I fdf_srcs/ -I get_next_line/ -I minilibx_macos

clean:
	rm -f $(OBJ)
	make -C libft/ clean
	make -C minilibx_macos/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	rm -f $(LIBMLX)

re: fclean all
