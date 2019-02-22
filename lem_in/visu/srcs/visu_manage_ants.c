/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_manage_ants.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 16:02:12 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:30:57 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_search_ant(t_ant **ant, int ant_id)
{
	if (*ant == 0)
		return (-1);
	while (*ant != 0)
	{
		if ((*ant)->id == ant_id)
			return (1);
		*ant = (*ant)->next;
	}
	return (-1);
}

static	void	visu_manage_pheromon(t_visu_data *data, int ant_id,
					int origin, int dest)
{
	int	pheromon;

	if (VI_PHER_BLANK(data, origin, dest) && data->pioneers[ant_id - 1] == 0)
	{
		pheromon = (1 << (data->current_pheromon % 16));
		(data->current_pheromon)++;
		(data->matrix)[origin][dest] = (1 | (pheromon << 1));
		(data->matrix)[dest][origin] = (1 | (pheromon << 1));
		data->pioneers[ant_id - 1] = pheromon;
	}
	else if (VI_PHER_BLANK(data, origin, dest))
	{
		(data->matrix)[origin][dest] = (1 | (data->pioneers[ant_id - 1] << 1));
		(data->matrix)[dest][origin] = (1 | (data->pioneers[ant_id - 1] << 1));
	}
	else if (((data->matrix)[origin][dest] >> 1)
		== data->pioneers[ant_id - 1])
	{
		(data->matrix)[origin][dest] = 1;
		(data->matrix)[dest][origin] = 1;
	}
}

static	int		visu_add_ant(t_visu_data *data, int ant_id, int room_id,
					int origin)
{
	t_ant	*elem;
	t_ant	*bubble;
	int		ret;

	if (((data->matrix)[origin][room_id] & 1) != 1)
		return (ft_msg_int(2, "Illegal move, tunnel does not exist\n", -1));
	if (!(elem = (t_ant *)malloc(sizeof(t_ant))))
		return (ft_msg_int(2, "Failed malloc int add ant\n", -2));
	elem->id = ant_id;
	elem->location = room_id;
	elem->moved = 1;
	elem->next = NULL;
	if (data->ants == 0)
		data->ants = elem;
	else
	{
		bubble = data->ants;
		while (bubble->next != 0)
			bubble = bubble->next;
		bubble->next = elem;
	}
	visu_manage_pheromon(data, ant_id, origin, room_id);
	ret = visu_reverse_instruction(data, ant_id, origin, room_id);
	return (ret < 0 ? ret : visu_manage_room_pop(data, origin, room_id));
}

static	int		visu_move_ant(t_visu_data *data, t_ant *ant, int room_id)
{
	if (((data->matrix)[ant->location][room_id] & 1) != 1)
		return (ft_msg_int(2, "Illegal move, tunnel does not exist\n", -1));
	if (ant->moved == 1)
		return (ft_msg_int(2, "Can't move ant more than once/turn.\n", -1));
	visu_manage_pheromon(data, ant->id, ant->location, room_id);
	if (visu_reverse_instruction(data, ant->id, ant->location, room_id) < 0)
		return (-1);
	if (visu_manage_room_pop(data, ant->location, room_id) < 0)
		return (-1);
	ant->location = room_id;
	ant->moved = 1;
	return (1);
}

int				visu_manage_ants(t_visu_data *data, char *line, int ant_id,
					int len)
{
	char	room_name[len + 1];
	int		i;
	int		room_id;
	t_ant	*ant;

	i = 0;
	ant = data->ants;
	while (line[i] != ' ' && line[i] != '\0')
	{
		room_name[i] = line[i];
		i++;
	}
	room_name[i] = '\0';
	room_id = visu_rec_search(data->anthill, room_name, 0, data->n_room - 1);
	if (room_id < 0)
		return (ft_msg_int(2, "Room does not exist.\n", -1));
	if (visu_search_ant(&ant, ant_id) < 0)
		return (visu_add_ant(data, ant_id, room_id,
			(VI_PLAY_FORWARD(data->play_param) ? data->start : data->end)));
	else
		visu_move_ant(data, ant, room_id);
	return (1);
}
