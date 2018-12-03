/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_seg_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:29:06 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:39:19 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_inf(t_infseg *inf, int dx, int dy, int color)
{
	inf->dx = dx;
	inf->dy = dy;
	inf->color1 = color;
}

void	ft_swap_coord(t_coord *a)
{
	int	tmp;

	tmp = a->a1[1];
	a->a1[1] = a->a1[0];
	a->a1[0] = tmp;
	tmp = a->a2[1];
	a->a2[1] = a->a2[0];
	a->a2[0] = tmp;
}

int		ft_seg_choice(t_coord *a, t_image *image, t_infseg *inf, int tmp)
{
	if ((inf->dx < 0 && inf->dy < 0 && -inf->dx < -inf->dy) ||\
			(inf->dx < 0 && inf->dy < 0 && -inf->dx >= -inf->dy) ||\
			(inf->dx >= 0 && inf->dy < 0 && inf->dx >= -inf->dy) ||\
			(inf->dx < 0 && inf->dy >= 0 && -inf->dx <= inf->dy))
	{
		inf->color1 = inf->color2;
		inf->color2 = tmp;
	}
	if (inf->dx >= 0 && inf->dy >= 0 && inf->dx >= inf->dy)
		ft_put_seg1_im(a->a1, a->a2, image, inf);
	if (inf->dx >= 0 && inf->dy >= 0 && inf->dx < inf->dy)
		ft_put_seg2_im(a->a1, a->a2, image, inf);
	if (inf->dx < 0 && inf->dy < 0 && -inf->dx < -inf->dy)
		ft_put_seg2_im(a->a2, a->a1, image, inf);
	if (inf->dx < 0 && inf->dy < 0 && -inf->dx >= -inf->dy)
		ft_put_seg1_im(a->a2, a->a1, image, inf);
	if (inf->dx < 0 && inf->dy >= 0 && -inf->dx >= inf->dy)
		ft_put_seg3_im(a->a1, a->a2, image, inf);
	if (inf->dx >= 0 && inf->dy < 0 && inf->dx >= -inf->dy)
		ft_put_seg3_im(a->a2, a->a1, image, inf);
	if (inf->dx < 0 && inf->dy >= 0 && -inf->dx < inf->dy)
		ft_put_seg4_im(a->a2, a->a1, image, inf);
	if (inf->dx >= 0 && inf->dy < 0 && inf->dx < -inf->dy)
		ft_put_seg4_im(a->a1, a->a2, image, inf);
	return (0);
}

int		ft_trace_seg_image(t_coord *a, t_image *image, int color1, int color2)
{
	int			dx;
	int			dy;
	t_infseg	*inf;

	dx = a->a2[0] - a->a1[0];
	dy = a->a2[1] - a->a1[1];
	if (!(inf = (t_infseg *)malloc(sizeof(t_infseg))))
		return (0);
	if (ft_abs(dx) < ft_abs(dy))
		ft_swap_coord(a);
	ft_fill_inf(inf, dx, dy, color1);
	inf->color2 = color2;
	ft_seg_choice(a, image, inf, inf->color1);
	free(inf);
	return (1);
}
