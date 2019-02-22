/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_create_anthill_matrix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:53:02 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/08 18:27:22 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int	visu_create_matrix(t_visu_data *data)
{
	int	i;

	if (!(data->matrix = (int **)malloc(sizeof(int *) * data->n_room)))
		return (ft_msg_int(2, "Abort, failed malloc matrix", -2));
	i = 0;
	while (i < data->n_room)
	{
		if (!(data->matrix[i] = (int *)malloc(sizeof(int) * data->n_room)))
			return (ft_msg_int(2, "Abort, failed malloc matrix", -2));
		ft_bzero(data->matrix[i], sizeof(int) * data->n_room);
		i++;
	}
	return (0);
}

static	int	visu_copy_from_room(t_visu_data *data, t_parse *room, int i)
{
	char	*name;
	int		j;

	if (!(name = (char *)malloc(room->size + 1)))
		return (-2);
	j = 0;
	while (j < room->size)
	{
		name[j] = room->name[j];
		j++;
	}
	name[j] = '\0';
	data->anthill[i].name = name;
	data->anthill[i].x = room->x;
	data->anthill[i].y = room->y;
	data->anthill[i].occupants = 0;
	return (0);
}

int			visu_create_anthill_matrix(t_visu_data *data, t_parse *rooms)
{
	int		i;
	t_parse	*tmp;

	i = 0;
	data->endroom = 1;
	if (data->start != 2 || data->end != 2)
		return (ft_msg_int(2, "Abort, no end or no start", -2));
	if (!(data->anthill = (t_room *)malloc(sizeof(t_room) * data->n_room)))
		return (ft_msg_int(2, "Abort, failed malloc create anthill", -2));
	tmp = rooms;
	i = 0;
	while (tmp != NULL)
	{
		if (visu_copy_from_room(data, tmp, i) == -2)
			return (ft_msg_int(2, "Abort, failed malloc create anthill", -2));
		if (tmp->state != 0)
		{
			data->start = tmp->state == 1 ? i : data->start;
			data->end = tmp->state == 2 ? i : data->end;
		}
		i++;
		tmp = tmp->next;
	}
	data->anthill[data->start].occupants = data->n_ant;
	return (visu_create_matrix(data));
}
