/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_bfs_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:19:10 by erli              #+#    #+#             */
/*   Updated: 2019/02/09 17:12:55 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_path	*lem_in_manage_found(t_lem_in_data *data, t_path **list,
					int found)
{
	if (found == -2)
	{
		lem_in_del_list(list);
		data->failed_malloc = 1;
		return (ft_msg_ptr(2, "A malloc has failed in manage_found.\n", 0));
	}
	else if (found == 1)
	{
		lem_in_trim_path(data, list);
		return (*list);
	}
	else if (found == -1)
		lem_in_del_list(list);
	return (NULL);
}

static	int		lem_in_init_paths(t_lem_in_data *data, t_path **list,
						int *n_path)
{
	t_path	*elem;
	int		next;
	int		index;

	index = 0;
	next = lem_in_next_room(data, *list, data->start, &index);
	while (next != -1)
	{
		elem = lem_in_create_path(data, next, n_path, NULL);
		if (elem == 0)
			return (ft_msg_int(2, "Failed malloc.\n", -2));
		lem_in_path_add(list, elem);
		if (next == data->end)
			return (1);
		next = lem_in_next_room(data, *list, data->start, &index);
	}
	return (0);
}

t_path			*lem_in_bfs_path(t_lem_in_data *data, int max_steps)
{
	t_path	*list;
	t_path	*bubble;
	int		n_path;
	int		found;
	int		n_steps;

	list = 0;
	n_path = 0;
	found = lem_in_init_paths(data, &list, &n_path);
	n_steps = 1;
	while (found == 0 && n_steps <= max_steps)
	{
		bubble = list;
		while (found == 0 && bubble != 0)
		{
			if (bubble->steps > n_steps)
				bubble = bubble->next;
			else
				found = lem_in_manage_node(data, &list, &bubble, &n_path);
		}
		n_steps++;
		if (list == 0 || n_steps > max_steps)
			found = -1;
	}
	return (lem_in_manage_found(data, &list, found));
}
