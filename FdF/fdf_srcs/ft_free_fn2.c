/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fn2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:25:18 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:19:01 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_coord_a(t_coord *a)
{
	free(a->a1);
	free(a->a2);
	free(a);
}

void	ft_free_line(t_line *line)
{
	t_line	*tmp;
	t_line	*tmp2;

	if (line == NULL)
		return ;
	tmp = line;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		free(tmp->x);
		free(tmp->y);
		free(tmp->alt);
		free(tmp->color);
		tmp = tmp->next;
		free(tmp2);
	}
}

void	ft_free_param1(t_param *param)
{
	free(param->mlx);
	free(param->win);
	free(param);
}

void	ft_free_param(t_param *param)
{
	free(param->mlx);
	free(param->win);
	free(param->line);
	free(param->image);
	free(param->mat);
	free(param);
}

void	ft_free_mat(double **mat, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		free(mat[j]);
		j++;
	}
	free(mat);
}
