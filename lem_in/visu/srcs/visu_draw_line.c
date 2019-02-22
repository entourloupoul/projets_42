/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:05:20 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 13:32:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_pixel_put_cross(t_visu_data *data, int x, int y, int z)
{
	visu_pixel_put(data, x, y, z);
	visu_pixel_put(data, x + 1, y, z);
	visu_pixel_put(data, x, y + 1, z);
	visu_pixel_put(data, x - 1, y, z);
	visu_pixel_put(data, x, y - 1, z);
}

static	void	draw_line_case1(t_visu_data *data, t_pixcoord *a,
			t_pixcoord *b)
{
	int x;
	int x_diff;
	int y;
	int z;
	int x_pro;

	x = a->px;
	x_diff = b->px - a->px;
	while (x <= b->px)
	{
		x_pro = x - a->px;
		if (x_diff != 0)
		{
			z = a->pz + x_pro * (b->pz - a->pz) / x_diff;
			y = a->py + x_pro * (b->py - a->py) / x_diff;
		}
		else
		{
			z = a->pz;
			y = a->py;
		}
		visu_pixel_put_cross(data, x, y, z);
		x++;
	}
}

static	void	draw_line_case2(t_visu_data *data, t_pixcoord *a,
			t_pixcoord *b)
{
	int x;
	int y_diff;
	int y;
	int z;
	int	y_pro;

	y = a->py;
	y_diff = b->py - a->py;
	while (y <= b->py)
	{
		y_pro = y - a->py;
		z = a->pz + y_pro * (b->pz - a->pz) / y_diff;
		x = a->px + y_pro * (b->px - a->px) / y_diff;
		visu_pixel_put_cross(data, x, y, z);
		y++;
	}
}

void			visu_draw_line(t_visu_data *data, t_pixcoord *a,
						t_pixcoord *b)
{
	int	y_diff;
	int x_diff;

	if (a == 0 || b == 0)
		return ;
	y_diff = b->py - a->py;
	x_diff = b->px - a->px;
	if (x_diff >= 0 && x_diff >= (y_diff < 0 ? -y_diff : y_diff))
		draw_line_case1(data, a, b);
	else if (x_diff < 0 && -x_diff >= (y_diff < 0 ? -y_diff : y_diff))
		draw_line_case1(data, b, a);
	else if (y_diff > 0 && y_diff >= (x_diff < 0 ? -x_diff : x_diff))
		draw_line_case2(data, a, b);
	else
		draw_line_case2(data, b, a);
}
