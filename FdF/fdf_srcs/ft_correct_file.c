/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_correct_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:05:52 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 17:22:27 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_colonne(t_line *tmp, int colonne, int i)
{
	int *x;
	int *y;
	int	*alt;
	int *color;

	if ((!(x = (int *)malloc(sizeof(int) * (colonne + 1)))) ||\
			(!(y = (int *)malloc(sizeof(int) * (colonne + 1)))) ||\
			(!(alt = (int *)malloc(sizeof(int) * (colonne + 1)))) ||\
			(!(color = (int *)malloc(sizeof(int) * (colonne + 1)))))
		return (-1);
	while (i < colonne)
	{
		x[i] = i < tmp->colonne ? tmp->x[i] : tmp->x[0] + i;
		y[i] = tmp->y[1];
		color[i] = i < tmp->colonne ? tmp->color[i] : 0x000000;
		alt[i] = i < tmp->colonne ? tmp->alt[i] : 1;
		i++;
	}
	ft_free_elem_correct(tmp);
	tmp->x = x;
	tmp->y = y;
	tmp->color = color;
	tmp->alt = alt;
	tmp->colonne = i;
	return (1);
}

int	ft_offset(t_line *tmp, int add, int i)
{
	int *x;
	int *y;
	int	*alt;
	int *color;

	if ((!(x = (int *)malloc(sizeof(int) * (tmp->colonne + add + 1)))) ||\
			(!(y = (int *)malloc(sizeof(int) * (tmp->colonne + add + 1)))) ||\
			(!(alt = (int *)malloc(sizeof(int) * (tmp->colonne + add + 1)))) ||\
			(!(color = (int *)malloc(sizeof(int) * (tmp->colonne + add + 1)))))
		return (-1);
	while (i < tmp->colonne + add)
	{
		x[i] = i;
		y[i] = tmp->y[1];
		color[i] = i < add ? 0x000000 : tmp->color[i - add];
		alt[i] = i < add ? 1 : tmp->alt[i - add];
		i++;
	}
	ft_free_elem_correct(tmp);
	tmp->x = x;
	tmp->y = y;
	tmp->color = color;
	tmp->alt = alt;
	tmp->colonne = i;
	return (1);
}

int	ft_change_elem(t_line **tmp, int sep, int colonne)
{
	int	ret;
	int	ret1;
	int	ret2;

	if ((*tmp)->offset != 0)
	{
		ret1 = ft_offset(*tmp, (*tmp)->offset / (sep + 1), 0);
		ret2 = ft_colonne(*tmp, colonne, 0);
		if (ret1 == 1 && ret2 == 1)
			ret = 1;
		else
			ret = 0;
	}
	else
		ret = ft_colonne(*tmp, colonne, 0);
	(*tmp)->x[colonne] = -1;
	(*tmp)->y[colonne] = -1;
	(*tmp)->alt[colonne] = -1;
	(*tmp)->color[colonne] = -1;
	return (ret);
}

int	ft_change_line(t_line **line, int sep, int colonne)
{
	t_line	*tmp;

	tmp = *line;
	while (tmp != NULL)
	{
		if (tmp->colonne != colonne)
		{
			if (ft_change_elem(&tmp, sep, colonne) == -1)
				return (-1);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_correct_file(t_line **line)
{
	int		sep;
	int		colonne;
	t_line	*tmp;
	int		a;

	a = 0;
	tmp = *line;
	sep = tmp->sep;
	colonne = tmp->colonne;
	while (tmp != NULL)
	{
		if (tmp->sep < sep)
			sep = tmp->sep;
		if (tmp->colonne != colonne)
		{
			colonne = tmp->colonne > colonne ? tmp->colonne : colonne;
			a = 1;
		}
		tmp = tmp->next;
	}
	if (a == 1)
		a = ft_change_line(line, sep, colonne);
	return (a);
}
