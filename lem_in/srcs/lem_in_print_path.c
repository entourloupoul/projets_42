/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:53:27 by erli              #+#    #+#             */
/*   Updated: 2019/02/06 17:11:21 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	lem_in_get_n_ants(int *ants, int total, int *limits,
					int max_paths)
{
	int j;

	ft_bzero(ants, sizeof(int) * max_paths);
	while (total > 0)
	{
		j = max_paths - 1;
		while (j >= 0 && total > 0)
		{
			if (total >= limits[j])
			{
				total--;
				ants[j]++;
			}
			j--;
		}
	}
}

static	void	lem_in_print_route(t_lem_in_data *data, t_path *path,
					int ants)
{
	int j;

	ft_putstr("Number of steps : \x1B[33m");
	ft_putnbr(path->steps);
	ft_putstr("\x1B[0m\nNumber of ants : \x1B[33m");
	ft_putnbr(ants);
	ft_putstr("\x1B[0m\n[");
	ft_putstr((data->anthill)[data->start]);
	ft_putstr(" -> ");
	j = 0;
	while (j < path->steps)
	{
		ft_putstr((data->anthill)[(path->path)[j]]);
		if (j < path->steps - 1)
			ft_putstr(" -> ");
		j++;
	}
	ft_putstr("]\n\n");
}

void			lem_in_print_path(t_lem_in_data *data, t_path *paths,
					int *limits, int max_paths)
{
	int	i;
	int	ants[max_paths];

	if (!(LI_OPT_PATHS(data->options)))
		return ;
	ft_putstr("========== Paths used ==========\n");
	if (paths == 0)
	{
		ft_putstr("list is empty\n");
		return ;
	}
	lem_in_get_n_ants(ants, data->n_ant, limits, max_paths);
	i = 0;
	while (i < max_paths)
	{
		lem_in_print_route(data, paths + i, ants[i]);
		i++;
	}
}
