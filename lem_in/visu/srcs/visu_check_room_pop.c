/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_check_room_pop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:14:04 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 17:27:11 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		visu_check_room_pop(t_visu_data *data)
{
	int i;

	i = 0;
	while (i < data->n_room)
	{
		if (i != data->start && i != data->end
			&& data->anthill[i].occupants > 1)
		{
			visu_free_data(&data);
			exit(ft_msg_int(2, "2 ants in the same room\n", 0));
		}
		i++;
	}
}
