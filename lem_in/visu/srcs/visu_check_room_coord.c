/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_check_room_coord.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:09:36 by erli              #+#    #+#             */
/*   Updated: 2019/02/07 11:17:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		visu_check_room_coord(t_visu_data *data, t_parse *rooms, t_parse *new)
{
	if (VI_OPT_COORD(data->options))
		return (0);
	while (rooms != NULL)
	{
		if (rooms->x == new->x && rooms->y == new->y)
			return (-1);
		rooms = rooms->next;
	}
	if (new->x < data->min_x)
		data->min_x = new->x;
	if (new->x > data->max_x)
		data->max_x = new->x;
	if (new->y < data->min_y)
		data->min_y = new->y;
	if (new->y > data->max_y)
		data->max_y = new->y;
	return (0);
}
