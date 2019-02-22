/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_draw_circle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:09:57 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 14:35:49 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void				visu_draw_circle(t_visu_data *data, t_pixcoord *pix)
{
	int	x;
	int	y;
	int	rad_2;
	int	rad_3;
	int	dist;

	rad_2 = ROOM_RAD * ROOM_RAD;
	rad_3 = (ROOM_RAD - 3) * (ROOM_RAD - 3);
	x = -ROOM_RAD;
	while (x <= ROOM_RAD)
	{
		y = -ROOM_RAD;
		while (y <= ROOM_RAD)
		{
			dist = (x * x) + (y * y);
			if (dist <= rad_2 && dist > rad_3)
				visu_pixel_put(data, pix->px + x, pix->py + y, pix->pz);
			else if (dist < rad_3)
				visu_pixel_put(data, pix->px + x, pix->py + y, ROOM_COLOUR);
			y++;
		}
		x++;
	}
}
