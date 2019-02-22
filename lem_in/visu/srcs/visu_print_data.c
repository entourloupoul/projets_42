/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_print_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 08:06:40 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 14:01:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <unistd.h>

static	void	print_matrix(t_visu_data *data, int **matrix)
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
			if (matrix[i][j] != 0)
			{
				count++;
				ft_printf("\x1B[35m%d \x1B[0m", matrix[i][j]);
			}
			else
				ft_printf("%d ", matrix[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	ft_printf("count = %d\n", count);
}

static	void	visu_print_anthill(t_visu_data *data)
{
	int i;

	i = 0;
	ft_putstr("\nanthill :\n[");
	while (i < data->n_room)
	{
		ft_printf("\x1B[32m%s \x1B[0m(%d, %d)", data->anthill[i].name,
			data->anthill[i].x, data->anthill[i].y);
		if (i < data->n_room - 1)
			ft_putstr("; ");
		else
			ft_putstr("]\n");
		i++;
	}
}

void			visu_print_data(t_visu_data *data)
{
	ft_printf("\n=========visu_data============\n");
	ft_printf("n_ant = %d\nstart = %d\nend = %d\nn_room = %d\noptions = %d\n",
		data->n_ant, data->start, data->end, data->n_room, data->options);
	ft_printf("min x = %d, max x = %d\n", data->min_x, data->max_x);
	ft_printf("min y = %d, max y = %d\n", data->min_y, data->max_y);
	ft_printf("cursor = %d\nplay_param = %d\ncurrent_phero = %d\n",
		data->cursor, (int)data->play_param, data->current_pheromon);
	if (data->anthill != 0)
		visu_print_anthill(data);
	if (data->matrix != 0)
	{
		ft_printf("\nmatrix:\n");
		print_matrix(data, data->matrix);
	}
}
