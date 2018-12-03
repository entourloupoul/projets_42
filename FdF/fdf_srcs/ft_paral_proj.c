/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paral_proj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:54:35 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:38:20 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_coord	*ft_create_coord_plan2(t_line *tmp, int i,\
		double **mat, double coef)
{
	t_coord	*a;
	double	*coord1;
	int		*a1;
	int		*a2;

	a2 = NULL;
	coord1 = NULL;
	if (!(a = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	if ((!(a1 = (int *)malloc(sizeof(int) * 2))) ||\
			(!(a2 = (int *)malloc(sizeof(int) * 2))) ||\
			(!(coord1 = (double *)malloc(sizeof(double) * 4))))
		return (NULL);
	coord1 = ft_calc_mat(tmp, i, mat, coord1);
	a1[0] = (int)round(coord1[0] - coef * coord1[2]);
	a1[1] = (int)round(coord1[1] - coef / 2 * coord1[2]);
	coord1 = ft_calc_mat(tmp->next, i, mat, coord1);
	a->a1 = a1;
	a2[0] = (int)round(coord1[0] - coef * coord1[2]);
	a2[1] = (int)round(coord1[1] - coef / 2 * coord1[2]);
	a->a2 = a2;
	free(coord1);
	return (a);
}

static t_coord	*ft_create_coord_plan(t_line *tmp, int i,\
		double **mat, double coef)
{
	t_coord	*a;
	double	*coord1;
	int		*a1;
	int		*a2;

	a2 = NULL;
	coord1 = NULL;
	if (!(a = (t_coord *)malloc(sizeof(t_coord))))
		return (NULL);
	if ((!(a1 = (int *)malloc(sizeof(int) * 2))) ||\
			(!(a2 = (int *)malloc(sizeof(int) * 2))) ||\
			(!(coord1 = (double *)malloc(sizeof(double) * 4))))
		return (NULL);
	coord1 = ft_calc_mat(tmp, i, mat, coord1);
	a1[0] = (int)round(coord1[0] - coef * coord1[2]);
	a1[1] = (int)round(coord1[1] - coef / 2 * coord1[2]);
	coord1 = ft_calc_mat(tmp, i + 1, mat, coord1);
	a->a1 = a1;
	a2[0] = (int)round(coord1[0] - coef * coord1[2]);
	a2[1] = (int)round(coord1[1] - coef / 2 * coord1[2]);
	a->a2 = a2;
	free(coord1);
	return (a);
}

static int		ft_put_seg(t_line *tmp, double coef, double **mat,\
		t_image *image)
{
	int		i;
	t_coord	*a;

	i = 0;
	while (tmp->x[i + 1] != -1)
	{
		if (!(a = ft_create_coord_plan(tmp, i, mat, coef)))
			return (0);
		ft_trace_seg_image(a, image, tmp->color[i], tmp->color[i + 1]);
		ft_free_coord_a(a);
		if (!(a = ft_create_coord_plan2(tmp, i, mat, coef)))
			return (0);
		ft_trace_seg_image(a, image, tmp->color[i], tmp->next->color[i]);
		ft_free_coord_a(a);
		i++;
	}
	if (!(a = ft_create_coord_plan2(tmp, i, mat, coef)))
		return (0);
	ft_trace_seg_image(a, image, tmp->color[i], tmp->next->color[i]);
	ft_free_coord_a(a);
	return (1);
}

int				ft_paral_proj(t_line **line, double coef,\
		double **mat, t_image *image)
{
	t_line	*tmp;
	int		i;
	t_coord	*a;

	tmp = *line;
	while (tmp->next != NULL)
	{
		ft_put_seg(tmp, coef, mat, image);
		tmp = tmp->next;
	}
	i = 0;
	while (tmp->x[i + 1] != -1)
	{
		if (!(a = ft_create_coord_plan(tmp, i, mat, coef)))
			return (0);
		ft_trace_seg_image(a, image, tmp->color[i], tmp->color[i + 1]);
		ft_free_coord_a(a);
		i++;
	}
	return (1);
}
