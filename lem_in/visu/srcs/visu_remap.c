/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_anthill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 10:43:02 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:10:14 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_sqrt(int nb)
{
	int i;

	i = 1;
	while ((i * i) < nb)
		i++;
	return (i);
}

static	void	visu_uniform_remap(t_visu_data *data, int room_per_line)
{
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	while (i < data->n_room)
	{
		x = 0;
		while (x < room_per_line && i < data->n_room)
		{
			data->anthill[i].x = x;
			data->anthill[i].y = y;
			x += 1;
			i++;
		}
		y++;
	}
	data->max_x = (y > 0 ? room_per_line : x);
	data->max_y = y;
}

void			visu_remap(t_visu_data *data)
{
	int i;
	int	room_per_line;

	if (data != 0 && !VI_OPT_COORD(data->options))
	{
		i = 0;
		while (i < data->n_room)
		{
			data->anthill[i].x -= data->min_x;
			data->anthill[i].y -= data->min_y;
			i++;
		}
		data->max_x -= data->min_x;
		data->max_y -= data->min_y;
		data->min_x = 0;
		data->min_y = 0;
	}
	else if (data != 0)
	{
		room_per_line = visu_sqrt(data->n_room);
		data->min_x = 0;
		data->min_y = 0;
		visu_uniform_remap(data, room_per_line);
	}
}
