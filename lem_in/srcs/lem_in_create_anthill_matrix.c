/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_create_anthill_matrix.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:53:02 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 14:15:15 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	lem_in_create_matrix(t_lem_in_data *data)
{
	int	i;

	if (!(data->matrix = (char **)malloc(sizeof(char *) * (data->n_room + 1))))
		return (ft_msg_int(2, "Abort, failed malloc matrix\n", -2));
	if (!(data->matrix_old = (char **)malloc(sizeof(char *)	\
					* (data->n_room + 1))))
		return (ft_msg_int(2, "Abort, failed malloc matrix\n", -2));
	i = 0;
	while (i < data->n_room)
	{
		data->matrix[i] = ft_strnew(data->n_room);
		data->matrix_old[i] = ft_strnew(data->n_room);
		if (data->matrix[i] == NULL || data->matrix_old[i] == NULL)
			return (ft_msg_int(2, "Abort, failed malloc matrix\n", -2));
		i++;
	}
	data->matrix[data->n_room] = NULL;
	data->matrix_old[data->n_room] = NULL;
	return (0);
}

int	lem_in_create_anthill_matrix(t_lem_in_data *data, t_parse *rooms)
{
	int		i;
	t_parse	*tmp;

	i = 0;
	data->endroom = 1;
	if (data->start != 2 || data->end != 2)
		return (ft_msg_int(2, "Abort, no end or no start\n", -2));
	if (!(data->anthill = (char **)malloc(sizeof(char *) * (data->n_room + 1))))
		return (ft_msg_int(2, "Abort, failed malloc create anthill\n", -2));
	tmp = rooms;
	i = 0;
	while (tmp != NULL)
	{
		if (!(data->anthill[i] = ft_strsub(tmp->name, 0, tmp->size)))
			return (ft_msg_int(2, "Abort, failed malloc create anthill\n", -2));
		if (tmp->state != 0)
		{
			data->start = tmp->state == 1 ? i : data->start;
			data->end = tmp->state == 2 ? i : data->end;
		}
		i++;
		tmp = tmp->next;
	}
	data->anthill[data->n_room] = NULL;
	return (lem_in_create_matrix(data));
}
