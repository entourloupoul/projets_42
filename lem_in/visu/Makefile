#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 14:34:35 by erli              #+#    #+#              #
#    Updated: 2019/02/11 17:34:18 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		../visualizer

SRCSDIR		=		./srcs
OBJSDIR		=		./objs

SRCS		=		main.c				visu_parse.c		visu_get_options.c		\
					visu_free_data.c	visu_fill_file.c	visu_parse_get_ants.c	\
					visu_atoi.c		visu_parse_get_rooms.c	visu_parse_get_links.c	\
					visu_create_anthill_matrix.c			visu_print_data.c		\
					visu_parse_edit_new_room.c				visu_free_parse.c		\
					visu_check_room_coord.c					visu_init_data.c		\
					visu_init_visu.c						visu_get_instructions.c	\
															visu_rec_search.c		\
					visu_do_instructions.c					visu_manage_ants.c		\
					visu_draw_anthill.c	visu_remap.c		visu_draw_line.c		\
					visu_pixel_put.c	visu_draw_circle.c	visu_draw_ant.c			\
					visu_reverse_instruction.c				visu_manage_room_pop.c	\
					visu_check_room_pop.c					visu_draw_pop.c			\
																					\
					mlx_str_to_colour.c

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc -g

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/ -I ../libft/includes/

RM			=		rm -f

FRAMEWORK	=		-framework OpenGL -framework AppKit

LIB			=		../libft/libft.a

LIBMLX		=		../minilibx_macos/libmlx.a

all			:		$(NAME)

$(NAME)		:		$(OBJS) $(LIB) $(LIBMLX) includes/visu.h
					$(CC) $(CFLAG) $(INCL) $(OBJS) $(LIB) $(LIBMLX) $(FRAMEWORK) \
					-o $(NAME)

$(LIB)		:		
					make -C ../libft/

$(LIBMLX)	:
					make -C ../minilibx_macos/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/visu.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		
					@make fclean
					@make all

delsav		:
					$(RM) *~
					$(RM) */*~
					$(RM) \#*\#
					$(RM) */\#*\#

reset		:		
					@make fclean
					@make delsav
					@rm -Rf objs

.PHONY		:		clean fclean re delsav reset
