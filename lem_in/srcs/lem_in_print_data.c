/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 08:06:40 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 16:43:19 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

static	void	print_matrix(t_lem_in_data *data, char **matrix)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < data->n_room)
	{
		j = 0;
		while (j < data->n_room)
		{
			ft_printf("%d ", (int)matrix[i][j]);
			if ((int)matrix[i][j] != 0)
				count++;
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_printf("count = %d\n", count);
}

void			lem_in_print_data(t_lem_in_data *data)
{
	ft_printf("\n=========Lem_in_data============\n");
	ft_printf("n_ant = %d\nstart = %d\nend = %d\nn_room = %d\noptions = %d\n",
		data->n_ant, data->start, data->end, data->n_room, data->options);
	ft_printf("fd = %d\n", data->fd);
	if (data->anthill != 0)
		ft_printf("anthill = \n%ts\n", data->anthill, data->n_room);
	if (data->matrix != 0)
	{
		ft_printf("matrix:\n");
		print_matrix(data, data->matrix);
	}
	if (data->matrix_old != 0)
	{
		ft_printf("matrix_old:\n");
		print_matrix(data, data->matrix_old);
	}
	if (data->buf != 0)
		ft_printf("buf = \n%td\n", data->anthill, B_SIZE);
}
