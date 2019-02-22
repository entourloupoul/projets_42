/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_test_opti.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:20:13 by erli              #+#    #+#             */
/*   Updated: 2019/02/09 17:04:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	lem_in_set_map_coord(t_mapcoord *map, int x, int y, int z)
{
	map->mx = x;
	map->my = y;
	map->mz = z;
}

static	int		lem_in_draw_graph_lines(t_lem_in_data *data, int *tab,
					int n_paths)
{
	double		a;
	double		b;
	int			i;
	t_mapcoord	map[2];
	static	int	colour = 0;

	lem_in_set_map_coord(map, 1, tab[0], colour);
	a = 1.0;
	b = (double)(tab[0] - 1);
	i = 0;
	map[1].mx = (n_paths == 1 ? 0 : 1 + tab[1] - tab[0]);
	while (i + 1 < n_paths && data->n_ant > map[1].mx)
	{
		map[1].my = tab[i];
		lem_in_draw_graph(data, map[0], map[1]);
		lem_in_set_map_coord(map, map[1].mx, map[1].my, colour);
		b = map[1].mx / (a * (a + 1.0)) + b;
		a += 1.0;
		map[1].mx += (tab[i + 1] - tab[i]) * a;
		i++;
	}
	lem_in_set_map_coord(map + 1, data->n_ant,
		(int)(data->n_ant / a + b), colour++);
	lem_in_draw_graph(data, map[0], map[1]);
	return (map[1].my);
}

static	int		lem_in_eval_steps(t_lem_in_data *data, int *tab, int n_paths)
{
	double		a;
	double		b;
	int			i;
	int			limit;

	if (n_paths == 1)
		return (data->n_ant + tab[0] - 1);
	a = 1.0;
	b = (double)(tab[0] - 1);
	i = 0;
	limit = 1 + tab[1] - tab[0];
	while (i + 1 < n_paths && data->n_ant > limit)
	{
		b = limit / (a * (a + 1.0)) + b;
		a += 1.0;
		limit += (tab[i + 1] - tab[i]) * a;
		i++;
	}
	return ((int)(data->n_ant / a + b));
}

int				lem_in_test_opti(t_lem_in_data *data, int n_paths,
					int *old_is_better)
{
	int			steps_old[n_paths - 1];
	int			steps_new[n_paths];
	int			n_steps;
	int			n_steps_new;

	lem_in_get_steps(data, data->matrix_old, steps_old, n_paths - 1);
	lem_in_get_steps(data, data->matrix, steps_new, n_paths);
	ft_merge_sort_tab(steps_old, steps_old, n_paths - 1);
	ft_merge_sort_tab(steps_new, steps_new, n_paths);
	n_steps = lem_in_eval_steps(data, steps_old, n_paths - 1);
	n_steps_new = lem_in_eval_steps(data, steps_new, n_paths);
	if (n_paths == 2)
		data->max_steps = n_steps;
	if (LI_OPT_GRAPH(data->options))
	{
		lem_in_draw_graph_lines(data, steps_old, n_paths - 1);
		lem_in_draw_graph_lines(data, steps_new, n_paths);
	}
	if (n_steps > n_steps_new)
		return (n_steps_new);
	*old_is_better = 1;
	return (n_steps);
}
