/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:10:30 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 13:29:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_draw_head(t_visu_data *data, int x, int y, int z)
{
	visu_pixel_put(data, x - 8, y - 4, z);
	visu_pixel_put(data, x - 7, y - 3, z);
	visu_pixel_put(data, x - 6, y - 2, z);
	visu_pixel_put(data, x - 8, y + 4, z);
	visu_pixel_put(data, x - 7, y + 3, z);
	visu_pixel_put(data, x - 6, y + 2, z);
	visu_pixel_put(data, x - 5, y - 1, z);
	visu_pixel_put(data, x - 5, y, z);
	visu_pixel_put(data, x - 5, y + 1, z);
	visu_pixel_put(data, x - 4, y - 1, z);
	visu_pixel_put(data, x - 4, y, z);
	visu_pixel_put(data, x - 4, y + 1, z);
	visu_pixel_put(data, x - 3, y - 1, z);
	visu_pixel_put(data, x - 3, y, z);
	visu_pixel_put(data, x - 3, y + 1, z);
	visu_pixel_put(data, x - 2, y, z);
}

static	void	visu_draw_thorax(t_visu_data *data, int x, int y, int z)
{
	visu_pixel_put(data, x - 1, y - 1, z);
	visu_pixel_put(data, x - 1, y, z);
	visu_pixel_put(data, x - 1, y + 1, z);
	visu_pixel_put(data, x, y - 1, z);
	visu_pixel_put(data, x, y, z);
	visu_pixel_put(data, x, y + 1, z);
	visu_pixel_put(data, x + 1, y - 1, z);
	visu_pixel_put(data, x + 1, y, z);
	visu_pixel_put(data, x + 1, y + 1, z);
	visu_pixel_put(data, x + 2, y - 1, z);
	visu_pixel_put(data, x + 2, y, z);
	visu_pixel_put(data, x + 2, y + 1, z);
	visu_pixel_put(data, x + 3, y, z);
}

static	void	visu_draw_abdomen(t_visu_data *data, int x, int y, int z)
{
	visu_pixel_put(data, x + 4, y - 1, z);
	visu_pixel_put(data, x + 4, y, z);
	visu_pixel_put(data, x + 4, y + 1, z);
	visu_pixel_put(data, x + 5, y - 2, z);
	visu_pixel_put(data, x + 5, y - 1, z);
	visu_pixel_put(data, x + 5, y, z);
	visu_pixel_put(data, x + 5, y + 1, z);
	visu_pixel_put(data, x + 5, y + 2, z);
	visu_pixel_put(data, x + 6, y - 2, z);
	visu_pixel_put(data, x + 6, y - 1, z);
	visu_pixel_put(data, x + 6, y, z);
	visu_pixel_put(data, x + 6, y + 1, z);
	visu_pixel_put(data, x + 6, y + 2, z);
	visu_pixel_put(data, x + 7, y - 2, z);
	visu_pixel_put(data, x + 7, y - 1, z);
	visu_pixel_put(data, x + 7, y, z);
	visu_pixel_put(data, x + 7, y + 1, z);
	visu_pixel_put(data, x + 7, y + 2, z);
	visu_pixel_put(data, x + 8, y - 1, z);
	visu_pixel_put(data, x + 8, y, z);
	visu_pixel_put(data, x + 8, y + 1, z);
}

static	void	visu_draw_legs(t_visu_data *data, int x, int y, int z)
{
	visu_pixel_put(data, x - 1, y - 2, z);
	visu_pixel_put(data, x - 2, y - 3, z);
	visu_pixel_put(data, x - 3, y - 4, z);
	visu_pixel_put(data, x + 1, y - 2, z);
	visu_pixel_put(data, x, y - 3, z);
	visu_pixel_put(data, x - 1, y - 4, z);
	visu_pixel_put(data, x + 2, y - 2, z);
	visu_pixel_put(data, x + 3, y - 3, z);
	visu_pixel_put(data, x + 4, y - 4, z);
	visu_pixel_put(data, x - 1, y + 2, z);
	visu_pixel_put(data, x - 2, y + 3, z);
	visu_pixel_put(data, x - 3, y + 4, z);
	visu_pixel_put(data, x + 1, y + 2, z);
	visu_pixel_put(data, x, y + 3, z);
	visu_pixel_put(data, x - 1, y + 4, z);
	visu_pixel_put(data, x + 2, y + 2, z);
	visu_pixel_put(data, x + 3, y + 3, z);
	visu_pixel_put(data, x + 4, y + 4, z);
}

void			visu_draw_ant(t_visu_data *data, t_pixcoord *pix)
{
	int	x;
	int	y;
	int	z;

	x = pix->px;
	y = pix->py;
	z = pix->pz;
	visu_draw_head(data, x, y, z);
	visu_draw_thorax(data, x, y, z);
	visu_draw_abdomen(data, x, y, z);
	visu_draw_legs(data, x, y, z);
}
