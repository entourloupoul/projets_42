/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_seg_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:28:57 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:45:25 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_put_seg1_im(int *a1, int *a2, t_image *image, t_infseg *inf)
{
	int	dx;
	int	dy;
	int	e;
	int dc;

	dx = 2 * (a2[0] - a1[0]);
	dy = 2 * (a2[1] - a1[1]);
	e = a2[0] - a1[0];
	dc = (int)round(((inf->color2 - inf->color1) / sqrt(dx / 2 * dx / 2\
					+ dy / 2 * dy / 2)));
	while (a1[0] <= a2[0])
	{
		if (a1[0] < image->width && a1[0] >= 0 &&\
				a1[1] < image->heigth && a1[1] >= 0)
			*((unsigned int *)(image->data + a1[0] * image->bpp / 8 + a1[1]\
						* image->sizeline)) = inf->color1;
		if ((e = e - dy) < 0)
		{
			a1[1] = a1[1] + 1;
			e = e + dx;
		}
		inf->color1 = inf->color1 + dc;
		a1[0]++;
	}
	return (0);
}

int	ft_put_seg2_im(int *a1, int *a2, t_image *image, t_infseg *inf)
{
	int	dx;
	int	dy;
	int	e;
	int dc;

	dx = 2 * (a2[0] - a1[0]);
	dy = 2 * (a2[1] - a1[1]);
	e = a2[0] - a1[0];
	dc = (int)round(((inf->color2 - inf->color1) / sqrt(dx / 2 * dx / 2\
					+ dy / 2 * dy / 2)));
	while (a1[0] <= a2[0])
	{
		if (a1[1] < image->width && a1[1] >= 0 &&\
				a1[0] < image->heigth && a1[0] >= 0)
			*((unsigned int *)(image->data + a1[1] * image->bpp / 8 + a1[0]\
						* image->sizeline)) = inf->color1;
		if ((e = e - dy) < 0)
		{
			a1[1] = a1[1] + 1;
			e = e + dx;
		}
		inf->color1 = inf->color1 + dc;
		a1[0]++;
	}
	return (0);
}

int	ft_put_seg3_im(int *a1, int *a2, t_image *image, t_infseg *inf)
{
	int	dx;
	int	dy;
	int	e;
	int dc;

	dx = 2 * (a2[0] - a1[0]);
	dy = 2 * (a2[1] - a1[1]);
	e = a2[0] - a1[0];
	dc = (int)round(((inf->color2 - inf->color1) / sqrt(dx / 2 * dx / 2\
					+ dy / 2 * dy / 2)));
	while (a1[0] >= a2[0])
	{
		if (a1[0] < image->width && a1[0] >= 0 &&\
				a1[1] < image->heigth && a1[1] >= 0)
			*((unsigned int *)(image->data + a1[0] * image->bpp / 8 + a1[1]\
						* image->sizeline)) = inf->color1;
		if ((e = e + dy) > 0)
		{
			a1[1] = a1[1] + 1;
			e = e + dx;
		}
		inf->color1 = inf->color1 + dc;
		a1[0]--;
	}
	return (0);
}

int	ft_put_seg4_im(int *a1, int *a2, t_image *image, t_infseg *inf)
{
	int	dx;
	int	dy;
	int	e;
	int dc;

	dx = 2 * (a2[0] - a1[0]);
	dy = 2 * (a2[1] - a1[1]);
	e = a2[0] - a1[0];
	dc = (int)round(((inf->color2 - inf->color1) / sqrt(dx / 2 * dx / 2\
					+ dy / 2 * dy / 2)));
	while (a1[0] >= a2[0])
	{
		if (a1[1] < image->width && a1[1] >= 0 &&\
				a1[0] < image->heigth && a1[0] >= 0)
			*((unsigned int *)(image->data + a1[1] * image->bpp / 8 + a1[0]\
						* image->sizeline)) = inf->color1;
		if ((e = e + dy) > 0)
		{
			a1[1] = a1[1] + 1;
			e = e + dx;
		}
		inf->color1 = inf->color1 + dc;
		a1[0]--;
	}
	return (0);
}
