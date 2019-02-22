#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erli <erli@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/08 14:34:35 by erli              #+#    #+#              #
#    Updated: 2019/02/11 17:36:06 by erli             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=		lem_in

SRCSDIR		=		./srcs
OBJSDIR		=		./objs

SRCS		=		main.c				lem_in_add_flow.c		lem_in_algo.c		\
					lem_in_atoi.c		lem_in_bfs_path.c		lem_in_create_path.c\
					lem_in_del_list.c	lem_in_draw_graph.c		lem_in_fill_file.c	\
					lem_in_get_steps.c	lem_in_magic_paths.c	lem_in_manage_node.c\
					lem_in_next_room.c	lem_in_parse.c			lem_in_path_add.c	\
					lem_in_parse_get_links.c	lem_in_parse_get_rooms.c			\
					lem_in_print.c		lem_in_print_data.c		lem_in_rm_path.c	\
					lem_in_send_ants.c	lem_in_test_opti.c		lem_in_trim_path.c	\
					lem_in_get_options.c	lem_in_free.c		lem_in_print_path.c	\
					lem_in_parse_get_ants.c		lem_in_print_total_step.c			\
					lem_in_create_anthill_matrix.c			lem_in_free_path.c		\
					lem_in_print_file.c	lem_in_close.c			lem_in_key.c		\
					lem_in_draw_grad.c	lem_in_unload_ants.c						\
					lem_in_manage_output.c				lem_in_init_reached.c		\
					lem_in_reset_reached.c	lem_in_parse_edit_new_room.c			\
					mlx_line_put.c		mlx_str_to_colour.c	

OBJS		=		$(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))

CC			=		gcc -g

CFLAG		=		-Wall -Werror -Wextra

INCL		=		-I includes/ -I libft/includes/

RM			=		rm -f

FRAMEWORK	=		-framework OpenGL -framework AppKit

LIB			=		libft/libft.a

LIBMLX		=		minilibx_macos/libmlx.a

all			:		$(NAME) visu

$(NAME)		:		$(OBJS) $(LIB) $(LIBMLX) includes/lem_in.h
					$(CC) $(CFLAG) $(INCL) $(OBJS) $(LIB) $(LIBMLX) $(FRAMEWORK) \
					-o $(NAME)

visu		:		
					make -C visu/
$(LIB)		:		
					make -C libft/

$(LIBMLX)	:
					make -C minilibx_macos/

$(OBJSDIR)/%.o	:	$(SRCSDIR)/%.c includes/lem_in.h
					@mkdir -p $(OBJSDIR)
					$(CC) -c $(CFLAG) $(INCL) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)
					$(RM) visualizer

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
					@make -C libft reset
					@make -C minilibx_macos clean
					@make -C visu reset
					@rm -Rf objs

.PHONY		:		clean fclean re delsav reset visu
