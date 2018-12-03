/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_get_file2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 08:58:09 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:24:28 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fill_line_column(t_line *new, int *infline)
{
	int *x;
	int *y;
	int	colonne;

	if (!(x = (int *)malloc(sizeof(int) * (infline[3] + 1))) ||\
			!(y = (int *)malloc(sizeof(int) * (infline[3] + 1))))
		return (0);
	colonne = 0;
	while (colonne < infline[3])
	{
		x[colonne] = colonne;
		y[colonne] = infline[2];
		colonne++;
	}
	x[colonne] = -1;
	y[colonne] = -1;
	new->x = x;
	new->y = y;
	new->colonne = infline[3];
	return (1);
}

int		ft_create_elem2(int *alt, int *color, t_line **line, int *infline)
{
	t_line	*new;
	t_line	*tmp;

	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (0);
	new->alt = alt;
	new->color = color;
	new->offset = infline[0];
	new->sep = infline[1];
	new->next = NULL;
	if (ft_fill_line_column(new, infline) == 0)
	{
		free(new);
		return (0);
	}
	if (*line != NULL)
	{
		tmp = *line;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*line = new;
	return (1);
}

int		ft_create_elem1(char **tab, int *infline, t_line **line, int colonne)
{
	char	**tmp;
	int		*alt;
	int		*color;

	infline[3] = ft_tab_length(tab);
	if (!(alt = (int *)malloc(sizeof(int) * infline[3])) ||\
			!(color = (int *)malloc(sizeof(int) * infline[3])))
		return (0);
	while (tab[colonne] != NULL)
	{
		if (!(tmp = ft_strsplit(tab[colonne], ',')))
		{
			ft_free_create_elem(&alt, &color);
			return (0);
		}
		alt[colonne] = ft_atoi(tmp[0]);
		color[colonne] = tmp[1] ? ft_atoi(ft_convert_base_fdf(\
					"0123456789abcdef", "0123456789ABCDEF",\
					"0123456789", tmp[1] + 2)) : 0xFFFFFF;
		ft_free_tmp1(&tmp);
		colonne++;
	}
	if ((colonne = ft_create_elem2(alt, color, line, infline)) == 0)
		ft_free_create_elem(&alt, &color);
	return (colonne);
}

int		ft_work_line(char *nline, t_line **line, int numline)
{
	char	**tab;
	int		*infline;

	if (!(infline = (int *)malloc(sizeof(int) * 4)))
		return (0);
	infline[0] = 0;
	infline[1] = 0;
	infline[2] = numline;
	infline[3] = 0;
	while (nline[infline[0]] != '\0' && nline[infline[0]] == ' ')
		infline[0]++;
	while (nline[infline[0] + infline[3]] != '\0' && infline[1] == 0)
	{
		while (nline[infline[0] + infline[3] + infline[1]] == ' ')
			infline[1]++;
		infline[3]++;
	}
	if ((tab = ft_strsplit(nline, ' ')) == NULL ||\
			ft_create_elem1(tab, infline, line, 0) == 0)
	{
		ft_free_work_line(&infline, &tab);
		return (0);
	}
	ft_free_work_line(&infline, &tab);
	return (1);
}

t_line	*ft_fdf_get_file(char *file)
{
	char	*nline;
	t_line	*line;
	int		numline;
	int		fd;

	numline = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	line = NULL;
	nline = NULL;
	while (get_next_line(fd, &nline) > 0)
	{
		if (ft_work_line(nline, &line, numline) == 0)
		{
			free(nline);
			ft_free_lst1(&line);
			return (NULL);
		}
		free(nline);
		numline++;
	}
	return (line);
}
