/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init_visu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:51:58 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:52:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int			visu_init_visu(t_visu_data *data)
{
	if (!(data->mlx_ptr = mlx_init()))
		return (ft_msg_int(2, "Failed to make X-connection.\n", -1));
	if (!(data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT,
		"Anthill Visualizer")))
		return (ft_msg_int(2, "Failed to make X-connection.\n", -1));
	if (!(data->img_ptr = mlx_new_image(data->mlx_ptr, HEIGHT, HEIGHT)))
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		return (ft_msg_int(2, "Failed to create image.\n", -1));
	}
	data->img_str = mlx_get_data_addr(data->img_ptr, &(data->bpp),
		&(data->size_line), &(data->endian));
	return (0);
}
