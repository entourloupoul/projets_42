/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_get_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:01:32 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 16:10:51 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	lem_in_get_steps(t_lem_in_data *data, char **matrix,
						int *tab, int n_paths)
{
	int	index;
	int	steps;
	int	room;
	int	i;
	int	i_tab;

	index = 0;
	i_tab = 0;
	while (i_tab < n_paths && index < data->n_room)
	{
		while (!(matrix[data->start][index] == 7))
			index++;
		room = index++;
		steps = 1;
		while (room != data->end)
		{
			i = 0;
			while (!(matrix[room][i] == 7))
				i++;
			steps++;
			room = i;
		}
		tab[i_tab] = steps;
		i_tab++;
	}
}
