/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:56:11 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:35:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		lem_in_count_channel(t_lem_in_data *data, int room_id)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < data->n_room)
	{
		if ((data->matrix)[room_id][i] == 1)
			count++;
		i++;
	}
	return (count);
}

static	void	lem_in_add_path_flow(t_lem_in_data *data, t_path *path,
					int *j)
{
	int	i;

	i = 0;
	while (i < data->n_room)
	{
		ft_memcpy((data->matrix_old)[i], (data->matrix)[i], data->n_room);
		i++;
	}
	i = 0;
	lem_in_add_flow(data, data->start, (path->path)[0]);
	while (i + 1 < path->steps)
	{
		lem_in_add_flow(data, (path->path)[i], (path->path)[i + 1]);
		i++;
	}
	*j += 1;
}

static	int		lem_in_draw_paths(t_lem_in_data *data, int max_paths,
	int current_num_steps)
{
	int		i;
	t_path	*shortest_path;
	int		old_is_better;

	old_is_better = 0;
	i = 0;
	while (i < max_paths && old_is_better == 0)
	{
		shortest_path = lem_in_bfs_path(data, current_num_steps);
		lem_in_reset_reached(data);
		if (shortest_path == 0)
			max_paths = i;
		else
			lem_in_add_path_flow(data, shortest_path, &i);
		lem_in_unload_ants(data, shortest_path);
		if (i > 1 && shortest_path != 0)
			current_num_steps = lem_in_test_opti(data, i, &old_is_better);
		if (shortest_path != 0)
			lem_in_free_path(shortest_path, 0);
	}
	if (data->failed_malloc == 1 || i == 0)
		return (-1);
	lem_in_print_file(data);
	return (lem_in_send_ants(data,
			(old_is_better == 1 ? i - 1 : max_paths), old_is_better));
}

static	int		lem_in_hook(void *arg)
{
	t_lem_in_data	*data;
	int				ret;

	if (arg == 0)
		return (0);
	data = (t_lem_in_data *)arg;
	if (data->max_paths > 0)
	{
		ret = lem_in_draw_paths(data, data->max_paths, 1000);
		if (ret == -1)
		{
			lem_in_free_data(&data);
			exit(0);
		}
		else
			data->max_paths = -1;
		lem_in_draw_grad(data);
	}
	return (0);
}

int				lem_in_algo(t_lem_in_data *data)
{
	int		start_out;
	int		end_in;

	data->failed_malloc = 0;
	data->win_ptr = 0;
	start_out = lem_in_count_channel(data, data->start);
	end_in = lem_in_count_channel(data, data->end);
	data->max_paths = (start_out < end_in ? start_out : end_in);
	if (data->max_paths > 0 && LI_OPT_GRAPH(data->options))
	{
		if (!(data->mlx_ptr = mlx_init()))
			return (ft_msg_int(2, "Failed to init X-server\n", -1));
		if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
				"Optimisation graph")))
			return (ft_msg_int(2, "Failed to create window\n", -1));
		mlx_loop_hook(data->mlx_ptr, &lem_in_hook, data);
		mlx_hook(data->win_ptr, 17, (1L << 17), &lem_in_close, (void *)NULL);
		mlx_hook(data->win_ptr, 2, (1L << 0), &lem_in_key, data);
		mlx_loop(data->mlx_ptr);
	}
	else if (data->max_paths == 0
		|| lem_in_draw_paths(data, data->max_paths, 1000) == -1)
		return (-1);
	return (0);
}
