/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_manage_node.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 09:56:17 by erli              #+#    #+#             */
/*   Updated: 2019/02/09 16:50:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int		lem_in_do_fork(t_lem_in_data *data, t_path **bubble,
						int *n_path, int *index)
{
	int		next_id;
	int		room;
	t_path	*elem;

	room = ((*bubble)->path)[(*bubble)->steps - 2];
	next_id = lem_in_next_room(data, *bubble, room, index);
	while (next_id != -1)
	{
		if (!(elem = lem_in_create_path(data, next_id, n_path, *bubble)))
			return (ft_msg_int(2, "Failed malloc.\n", -2));
		lem_in_path_add(bubble, elem);
		if (next_id == data->end)
			return (1);
		next_id = lem_in_next_room(data, *bubble, room, index);
	}
	return (0);
}

int				lem_in_manage_node(t_lem_in_data *data, t_path **list,
							t_path **bubble, int *n_path)
{
	int		index;
	int		next_id;
	int		room;
	t_path	*next;

	index = 0;
	room = ((*bubble)->path)[(*bubble)->steps - 1];
	next_id = lem_in_next_room(data, *bubble, room, &index);
	if (next_id != -1)
	{
		((*bubble)->path)[(*bubble)->steps] = next_id;
		(*bubble)->steps += 1;
		if (next_id == data->end)
			return (1);
		return (lem_in_do_fork(data, bubble, n_path, &index));
	}
	else
	{
		next = (*bubble)->next;
		lem_in_rm_path(list, (*bubble)->path_id);
		(*bubble) = next;
	}
	return (0);
}
