/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_magic_paths.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:28 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:53:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		lem_in_init_paths(t_path *paths, int max_paths)
{
	int i;

	i = 0;
	while (i < max_paths)
	{
		if (!(paths[i].occupants = (int *)malloc(sizeof(int) * paths[i].steps)))
			return (ft_msg_int(2, "Abort, failed malloc.\n", -2));
		ft_bzero(paths[i].occupants, sizeof(int) * paths[i].steps);
		if (!(paths[i].path = (int *)malloc(sizeof(int) * paths[i].steps)))
		{
			free(paths[i].occupants);
			return (ft_msg_int(2, "Abort, failed malloc.\n", -2));
		}
		ft_bzero(paths[i].path, sizeof(int) * paths[i].steps);
		i++;
	}
	return (0);
}

static	void	lem_in_fill_paths(t_lem_in_data *data, char **matrix,
					t_path *paths, int max_paths)
{
	int i;
	int	j;
	int	start_room;
	int	room;

	i = 0;
	start_room = 0;
	while (i < max_paths)
	{
		while (!(matrix[data->start][start_room] == 7))
			start_room++;
		paths[i].path[0] = start_room;
		j = 1;
		while (j < paths[i].steps)
		{
			room = 0;
			while (!(matrix[paths[i].path[j - 1]][room] == 7))
				room++;
			paths[i].path[j] = room;
			j++;
		}
		start_room++;
		i++;
	}
}

int				lem_in_magic_paths(t_lem_in_data *data, char **matrix,
					t_path *paths, int max_paths)
{
	int		i;
	int		j;
	t_path	tmp;

	if (lem_in_init_paths(paths, max_paths) == -2)
		return (-2);
	lem_in_fill_paths(data, matrix, paths, max_paths);
	i = max_paths;
	while (i > 0)
	{
		j = 0;
		while (j + 1 < i)
		{
			if (paths[j + 1].steps < paths[j].steps)
			{
				tmp = paths[j + 1];
				paths[j + 1] = paths[j];
				paths[j] = tmp;
			}
			j++;
		}
		i--;
	}
	return (0);
}
