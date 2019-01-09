# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmasson <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 16:57:19 by pmasson           #+#    #+#              #
#    Updated: 2018/12/11 14:05:45 by etlagors         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf_srcs/ft_display_printf.c\
	  ft_printf_srcs/ft_flag_options_c.c\
	  ft_printf_srcs/ft_flag_options_d.c\
	  ft_printf_srcs/ft_flag_options_o.c\
	  ft_printf_srcs/ft_flag_options_p.c\
	  ft_printf_srcs/ft_flag_options_s.c\
	  ft_printf_srcs/ft_flag_options_x.c\
	  ft_printf_srcs/ft_flag_options_xx.c\
	  ft_printf_srcs/ft_flag_printf.c\
	  ft_printf_srcs/ft_lst_printf.c\
	  ft_printf_srcs/ft_printf.c\
	  ft_printf_srcs/ft_printf_2.c\
	  ft_printf_srcs/ft_printf_address.c\
	  ft_printf_srcs/ft_printf_int.c\
	  ft_printf_srcs/ft_printf_string.c\
	  ft_printf_srcs/ft_printf_uchar.c\
	  ft_printf_srcs/ft_printf_uint2.c\
	  ft_printf_srcs/ft_printf_uint3.c\
	  ft_printf_srcs/ft_printf_uint4.c\
	  ft_printf_srcs/ft_printf_double.c\
	  ft_printf_srcs/ft_flag_options_f.c\
	  ft_printf_srcs/ft_printf_lftoa_no_signe.c\
	  ft_printf_srcs/ft_flag_options_u.c\
	  ft_printf_srcs/ft_printf_percentage.c\
	  ft_printf_srcs/ft_printf_uint1.c\
	  libft/ft_putchar.c libft/ft_strlen.c libft/ft_strcmp.c libft/ft_strdup.c\
	  libft/ft_putstr.c libft/ft_putendl.c libft/ft_itoa.c libft/ft_putnbr.c\
	  libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c\
	  libft/ft_putnbr_fd.c libft/ft_memset.c libft/ft_bzero.c libft/ft_strcpy.c\
	  libft/ft_memcpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c\
	  libft/ft_strncpy.c libft/ft_strcat.c libft/ft_strncat.c\
	  libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strrchr.c\
	  libft/ft_strstr.c libft/ft_strnstr.c\
	  libft/ft_strncmp.c libft/ft_atoi.c libft/ft_islower.c libft/ft_isupper.c\
	  libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c\
	  libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c\
	  libft/ft_tolower.c libft/ft_memalloc.c\
	  libft/ft_memdel.c libft/ft_strnew.c libft/ft_strdel.c libft/ft_strclr.c\
	  libft/ft_striter.c libft/ft_striteri.c libft/ft_strmap.c\
	  libft/ft_strmapi.c libft/ft_strequ.c libft/ft_strnequ.c\
	  libft/ft_strsub.c libft/ft_strjoin.c\
	  libft/ft_strtrim.c libft/ft_strsplit.c libft/ft_print_table.c\
	  libft/ft_memccpy.c libft/ft_lstnew.c libft/ft_lstdelone.c\
	  libft/ft_lstdel.c libft/ft_lstadd.c\
	  libft/ft_lstiter.c libft/ft_lstmap.c libft/ft_convert_base.c\
	  libft/ft_lstappend.c libft/ft_abs.c libft/ft_ltoa.c\
	  libft/ft_lltoa_no_signe.c libft/ft_ulltoa.c

OBJS = $(SRC:%.c=%.o)

HEADER = includes/

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADER) $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $< -I$(HEADER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re fclean clean
