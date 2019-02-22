/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 11:50:11 by erli              #+#    #+#             */
/*   Updated: 2019/02/11 16:55:09 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void		visu_init_data2(t_visu_data *data)
{
	int i;

	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->img_ptr = NULL;
	data->bypp = 4;
	data->bpp = data->bypp * 8;
	data->size_line = 4 * WIDTH;
	data->nb_line = HEIGHT;
	data->endian = 0;
	i = 0;
	while (i < 100)
	{
		data->history[i] = NULL;
		i++;
	}
}

t_visu_data			*visu_init_data(void)
{
	t_visu_data *data;

	if (!(data = (t_visu_data *)malloc(sizeof(t_visu_data) * 1)))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	data->n_ant = 0;
	data->n_room = 0;
	data->endroom = 0;
	data->start = -1;
	data->end = -1;
	data->min_x = 2147483647;
	data->max_x = -2147483648;
	data->min_y = 2147483647;
	data->max_y = -2147483648;
	data->options = 0;
	data->play_param = 0;
	data->file = NULL;
	data->anthill = NULL;
	data->matrix = NULL;
	data->ants = NULL;
	data->pioneers = NULL;
	data->current_pheromon = 0;
	data->cursor = -1;
	visu_init_data2(data);
	return (data);
}
