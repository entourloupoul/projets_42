/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 21:40:35 by erli              #+#    #+#             */
/*   Updated: 2019/02/11 17:24:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "mlxadd.h"
# include "libft.h"
# include <stdlib.h>

# define WIDTH 2160
# define HEIGHT 1240
# define BORDER 100
# define ROOM_RAD 18
# define B_SIZE 16364
# define HIST_SIZE 100
# define START_COLOUR (1 << 3)
# define END_COLOUR (1 << 4)
# define ROOM_COLOUR (1 << 6)
# define VI_OPT_COORD(x) ((x & 1) == 1)
# define VI_PLAY_FORWARD(x) ((x & 1) == 1)
# define VI_PLAY_BACKWARD(x) (((x >> 1) & 1) == 1)
# define VI_PLAY_AUTO(x) (((x >> 2) & 1) == 1)
# define VI_PHER_BLANK(data, i, j) ((data->matrix[i][j] >> 1) == 0)

typedef struct	s_ant
{
	int				id;
	int				location;
	char			moved;
	struct s_ant	*next;
}				t_ant;

typedef	struct	s_room
{
	char	*name;
	int		x;
	int		y;
	int		occupants;
}				t_room;

typedef struct	s_parse
{
	char			*name;
	int				size;
	int				x;
	int				y;
	int				n_buff;
	int				state;
	struct s_parse	*next;
}				t_parse;

typedef	struct	s_file
{
	char			*buff;
	int				size;
	struct s_file	*next;
}				t_file;

typedef	struct	s_visu_data
{
	int		n_ant;
	int		n_room;
	int		endroom;
	int		start;
	int		end;
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	int		options;
	char	*history[HIST_SIZE];
	int		cursor;
	char	play_param;
	t_file	*file;
	t_room	*anthill;
	int		**matrix;
	t_ant	*ants;
	int		*pioneers;
	int		current_pheromon;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		bpp;
	int		bypp;
	int		size_line;
	int		nb_line;
	int		endian;
	char	*img_str;
}				t_visu_data;

t_visu_data		*visu_init_data(void);
int				visu_init_visu(t_visu_data *data);
int				visu_atoi(char *str, int *d);
int				visu_create_anthill_matrix(t_visu_data *data,
					t_parse *rooms);
int				visu_fill_file(char *line, t_file **file);
void			visu_free_data(t_visu_data **data);
void			visu_free_parse(t_parse **rooms);
int				visu_get_options(int argc, char **argv, t_visu_data *data);
t_visu_data		*visu_parse(int argc, char **argv);
int				visu_parse_get_ants(char *line, t_visu_data *data);
int				visu_parse_get_links(char *line, t_visu_data *data,
					int tr1, int tr2);
int				visu_parse_get_rooms(char *line, t_visu_data *data,
					t_parse **rooms, t_file *file);
int				visu_parse_edit_new_room(char *line, t_visu_data *data,
					t_parse *new, int len);
int				visu_check_room_coord(t_visu_data *data, t_parse *rooms,
					t_parse *new);
void			visu_print_data(t_visu_data *data);
int				visu_get_instructions(t_visu_data *data);
int				visu_rec_search(t_room *anthill, char *name, int i, int j);
int				visu_do_instructions(t_visu_data *data, char *line);
int				visu_reverse_instruction(t_visu_data *data, int ant_id,
					int orig, int dest);
int				visu_manage_ants(t_visu_data *data, char *line, int ant_id,
					int len);
void			visu_remap(t_visu_data *data);
void			visu_pixel_put(t_visu_data *data, int x, int y, int z);
void			visu_draw_line(t_visu_data *data, t_pixcoord *a, t_pixcoord *b);
void			visu_draw_circle(t_visu_data *data, t_pixcoord *pix);
void			visu_draw_pop(t_visu_data *data, t_pixcoord *pix, int i);
void			visu_draw_ant(t_visu_data *data, t_pixcoord *pix);
void			visu_draw_anthill(t_visu_data *data);
int				visu_manage_room_pop(t_visu_data *data, int orig, int dest);
void			visu_check_room_pop(t_visu_data *data);

#endif
