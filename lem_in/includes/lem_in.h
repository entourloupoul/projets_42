/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:01:23 by erli              #+#    #+#             */
/*   Updated: 2019/02/11 17:23:40 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "mlxadd.h"
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"

# include <sys/time.h>

# define WIDTH 1080
# define HEIGHT 720
# define GRAPH_BORDER 50
# define B_SIZE 16364
# define OUTPUT_PATH "lem_in_output.txt"
# define LI_CONNECTED(data, i, j) ((data->matrix)[i][j] & 1) == 1
# define LI_FLOW(data, i, j) (((data->matrix)[i][j] >> 1) & 1) == 1
# define LI_POS_FLOW(data, i, j) (((data->matrix)[i][j] >> 2) & 1) == 1
# define LI_FLOW_CAPPED(data, i, j) (((data->matrix)[i][j] >> 1) & 3) == 3
# define LI_OPT_OUT(x) ((x & 1) == 1)
# define LI_OPT_STEPS(x) (((x >> 1) & 1) == 1)
# define LI_OPT_GRAPH(x) (((x >> 2) & 1) == 1)
# define LI_OPT_PATHS(x) (((x >> 3) & 1) == 1)

typedef	struct	s_file
{
	char			*buff;
	int				size;
	struct s_file	*next;
}				t_file;

typedef	struct	s_parse
{
	char			*name;
	int				size;
	int				n_buff;
	int				state;
	struct s_parse	*next;
}				t_parse;

typedef struct	s_lem_in_data
{
	int			n_ant;
	int			start;
	int			end;
	t_file		*file;
	int			n_room;
	int			endroom;
	int			options;
	int			max_paths;
	int			fd;
	int			failed_malloc;
	char		**anthill;
	int			*reached;
	char		**matrix;
	char		**matrix_old;
	int			*limits;
	char		*buf;
	int			buf_cursor;

	void		*mlx_ptr;
	void		*win_ptr;
	int			max_steps;
}				t_lem_in_data;

typedef	struct	s_path
{
	int				path_id;
	int				*path;
	int				*occupants;
	int				steps;
	struct s_path	*next;
	struct s_path	*previous;
}				t_path;

void			lem_in_manage_output(t_lem_in_data *data);
t_path			*lem_in_create_path(t_lem_in_data *data, int room_id,
					int *n_path, t_path *dup);
void			lem_in_path_add(t_path **list, t_path *path);
void			lem_in_rm_path(t_path **list, int path_id);
void			lem_in_del_list(t_path **list);
void			lem_in_trim_path(t_lem_in_data *data, t_path **list);
int				lem_in_next_room(t_lem_in_data *data, t_path *path, int n_room,
					int *index);
t_path			*lem_in_bfs_path(t_lem_in_data *data, int max_steps);
int				lem_in_manage_node(t_lem_in_data *data, t_path **list,
					t_path **bubble, int *n_path);
void			lem_in_add_flow(t_lem_in_data *data, int src, int dest);
int				lem_in_algo(t_lem_in_data *data);
void			lem_in_get_steps(t_lem_in_data *data, char **matrix,
					int *tab, int n_path);
int				lem_in_test_opti(t_lem_in_data *data, int n_paths,
					int *oldisbet);
void			lem_in_draw_graph(t_lem_in_data *data, t_mapcoord a,
					t_mapcoord b);
void			lem_in_draw_grad(t_lem_in_data *data);
int				lem_in_send_ants(t_lem_in_data *data, int max_paths, int mode);
int				lem_in_magic_paths(t_lem_in_data *data, char **matrix,
					t_path *paths, int max_paths);
void			lem_in_print(t_lem_in_data *data, int ant_id, int room,
					int end_of_line);
int				lem_in_key(int key, void *arg);
int				lem_in_close(void *arg);
void			lem_in_print_data(t_lem_in_data *data);
t_lem_in_data	*lem_in_parse(int argc, char **argv, int tr);
int				lem_in_fill_file(char *line, t_file **file);
int				lem_in_parse_get_rooms(char *line, t_lem_in_data *data,
					t_parse **rooms, t_file *file);
int				lem_in_atoi(char *str, int *d);
int				lem_in_create_anthill_matrix(t_lem_in_data *data,
					t_parse *rooms);
int				lem_in_parse_get_ants(char *line, t_lem_in_data *data);
int				lem_in_parse_get_links(char *line, t_lem_in_data *data, int tr1,
					int tr2);
int				lem_in_get_options(int argc, char **argv, t_lem_in_data *data);
void			lem_in_free_rooms(t_parse **rooms);
void			lem_in_print_total_step(t_lem_in_data *data, int steps);
void			lem_in_print_path(t_lem_in_data *data, t_path *path,
					int *limits, int max_paths);
void			lem_in_unload_ants(t_lem_in_data *data, t_path *path);
void			lem_in_print_file(t_lem_in_data *data);
void			lem_in_free_data(t_lem_in_data **data);
void			lem_in_free_path(t_path *path, int mode);
int				lem_in_init_reached(t_lem_in_data *data);
void			lem_in_reset_reached(t_lem_in_data *data);
int				lem_in_parse_edit_new_room(char *line, t_lem_in_data *data,
					t_parse *new, int len);
#endif
