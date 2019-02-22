/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_manage_room_pop.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:08:10 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 17:32:32 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int		visu_manage_room_pop(t_visu_data *data, int orig, int dest)
{
	data->anthill[orig].occupants -= 1;
	if (data->anthill[orig].occupants < 0)
	{
		ft_putstr_fd("Error, There was no ant in room ", 2);
		ft_putstr_fd(data->anthill[orig].name, 2);
		ft_putstr_fd(" to be sent\n", 2);
		return (-1);
	}
	data->anthill[dest].occupants += 1;
	return (1);
}
