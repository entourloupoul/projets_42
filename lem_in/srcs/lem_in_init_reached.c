/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_init_reached.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:39:11 by erli              #+#    #+#             */
/*   Updated: 2019/02/11 11:45:42 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lem_in_init_reached(t_lem_in_data *data)
{
	int i;
	int	*reached;

	if (data == 0)
		return (-1);
	if (!(reached = (int *)malloc(sizeof(int) * data->n_room)))
		return (ft_msg_int(2, "Failed malloc for reached\n", -2));
	i = 0;
	data->reached = reached;
	while (i < data->n_room)
	{
		reached[i] = -1;
		i++;
	}
	return (0);
}
