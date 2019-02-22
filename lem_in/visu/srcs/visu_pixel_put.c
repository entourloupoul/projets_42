/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_pixel_put.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:53:08 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 18:31:44 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	t_colour	visu_colour2(int z)
{
	if (((z >> 10) & 1) == 1)
		return (mlx_str_to_colour("0x00eca190"));
	else if (((z >> 11) & 1) == 1)
		return (mlx_str_to_colour("0x00ff3b3f"));
	else if (((z >> 12) & 1) == 1)
		return (mlx_str_to_colour("0x003cb371"));
	else if (((z >> 13) & 1) == 1)
		return (mlx_str_to_colour("0x00ffe4e1"));
	else if (((z >> 14) & 1) == 1)
		return (mlx_str_to_colour("0x0028d031"));
	else
		return (mlx_str_to_colour("0x00d8c3fe"));
}

static	t_colour	visu_colour(int z)
{
	if (z == 0)
		return (mlx_str_to_colour("0x00ce9178"));
	else if (((z >> 20) & 1) == 1)
		return (mlx_str_to_colour("0x00000000"));
	else if ((z & 1) == 1)
		return (mlx_str_to_colour("0x00af19af"));
	else if (((z >> 1) & 1) == 1)
		return (mlx_str_to_colour("0x003635d5"));
	else if (((z >> 2) & 1) == 1)
		return (mlx_str_to_colour("0x00ff00be"));
	else if (((z >> 3) & 1) == 1)
		return (mlx_str_to_colour("0x0000ff00"));
	else if (((z >> 4) & 1) == 1)
		return (mlx_str_to_colour("0x00ff5f00"));
	else if (((z >> 5) & 1) == 1)
		return (mlx_str_to_colour("0x00cc0000"));
	else if (((z >> 6) & 1) == 1)
		return (mlx_str_to_colour("0x00ffffff"));
	else if (((z >> 7) & 1) == 1)
		return (mlx_str_to_colour("0x00f2d388"));
	else if (((z >> 8) & 1) == 1)
		return (mlx_str_to_colour("0x0000d3df"));
	else if (((z >> 9) & 1) == 1)
		return (mlx_str_to_colour("0x00f1be13"));
	return (visu_colour2(z));
}

void				visu_pixel_put(t_visu_data *data, int x, int y, int z)
{
	int			i;
	t_colour	*int_ptr;

	if (data->img_ptr == 0)
		return ;
	if (x < 0 || y < 0 || x > data->size_line / data->bypp
		|| y > data->nb_line)
		return ;
	i = x * (data->bypp) + y * data->size_line;
	if (i > data->size_line * y && i < (data->size_line * (y + 1)))
	{
		int_ptr = (t_colour *)((data->img_str) + i);
		int_ptr[0] = visu_colour(z);
	}
}
