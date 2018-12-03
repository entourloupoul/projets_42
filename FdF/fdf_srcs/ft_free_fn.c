/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:51:21 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 17:22:56 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_elem_correct(t_line *tmp)
{
	free(tmp->x);
	free(tmp->y);
	free(tmp->alt);
	free(tmp->color);
}

void	ft_free_work_line(int **infline, char ***tab)
{
	int i;

	i = 0;
	free(*infline);
	if (*tab != NULL)
	{
		while ((*tab)[i] != NULL)
		{
			free((*tab)[i]);
			i++;
		}
		free(*tab);
	}
}

void	ft_free_tmp1(char ***tmp)
{
	free((*tmp)[0]);
	free((*tmp)[1]);
	free(*tmp);
}

void	ft_free_create_elem(int **alt, int **color)
{
	free(*alt);
	free(*color);
}

void	ft_free_lst1(t_line **line)
{
	t_line	*tmp;
	t_line	*tmp2;

	if (line == NULL)
		return ;
	tmp = *line;
	while (tmp != NULL)
	{
		free(tmp->x);
		free(tmp->y);
		free(tmp->alt);
		free(tmp->color);
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}
