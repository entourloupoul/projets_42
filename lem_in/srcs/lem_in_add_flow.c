/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_add_flow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:34:42 by erli              #+#    #+#             */
/*   Updated: 2019/02/01 12:00:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_add_flow(t_lem_in_data *data, int src, int dest)
{
	if (!(LI_CONNECTED(data, src, dest)))
		exit(ft_msg_int(2,
		"Error, attempt to increase flow to non existent channel.\n", 0));
	if (LI_FLOW_CAPPED(data, src, dest))
		exit(ft_msg_int(2,
		"Error, attempt to increase flow to a capped channel.\n", 0));
	if (!(LI_FLOW(data, src, dest)))
	{
		(data->matrix)[src][dest] += 6;
		(data->matrix)[dest][src] += 2;
	}
	else
	{
		(data->matrix)[src][dest] = 1;
		(data->matrix)[dest][src] = 1;
	}
}
