/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 17:55:47 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 18:05:10 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_draw_star2(t_visu_data *data, int x, int y, int z)
{
	visu_pixel_put(data, x + 1, y - 1, z);
	visu_pixel_put(data, x + 2, y - 2, z);
	visu_pixel_put(data, x + 3, y - 3, z);
	visu_pixel_put(data, x - 1, y - 1, z);
	visu_pixel_put(data, x - 2, y - 2, z);
	visu_pixel_put(data, x - 3, y - 3, z);
	visu_pixel_put(data, x, y + 1, z);
	visu_pixel_put(data, x, y + 2, z);
	visu_pixel_put(data, x, y + 3, z);
	visu_pixel_put(data, x, y - 1, z);
	visu_pixel_put(data, x, y - 2, z);
	visu_pixel_put(data, x, y - 3, z);
}

static	void	visu_draw_star(t_visu_data *data, t_pixcoord *pix)
{
	int x;
	int y;
	int z;

	z = 1 << 20;
	x = pix->px;
	y = pix->py;
	visu_pixel_put(data, x, y, z);
	visu_pixel_put(data, x + 1, y, z);
	visu_pixel_put(data, x + 2, y, z);
	visu_pixel_put(data, x + 3, y, z);
	visu_pixel_put(data, x - 1, y, z);
	visu_pixel_put(data, x - 2, y, z);
	visu_pixel_put(data, x - 3, y, z);
	visu_pixel_put(data, x + 1, y + 1, z);
	visu_pixel_put(data, x + 2, y + 2, z);
	visu_pixel_put(data, x + 3, y + 3, z);
	visu_pixel_put(data, x - 1, y + 1, z);
	visu_pixel_put(data, x - 2, y + 2, z);
	visu_pixel_put(data, x - 3, y + 3, z);
	visu_draw_star2(data, x, y, z);
}

void			visu_draw_pop(t_visu_data *data, t_pixcoord *pix, int i)
{
	int	pop;

	pop = data->anthill[i].occupants;
	if (pop == 0)
		return ;
	if (pop > 0)
		visu_draw_star(data, pix);
}
