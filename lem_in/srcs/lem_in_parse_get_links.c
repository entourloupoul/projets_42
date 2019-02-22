/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse_get_links.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:13:08 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 16:39:13 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	lem_in_parse_get_links_matrix(t_lem_in_data *data, int tr1, int tr2)
{
	data->matrix[tr1][tr2] = 1;
	data->matrix[tr2][tr1] = 1;
	return (1);
}

int	lem_in_parse_get_links(char *line, t_lem_in_data *data, int tr1, int tr2)
{
	int	i;
	int	b;
	int j;

	i = 1;
	while (line[i] != '\0' && line[i] != '-')
		i++;
	b = i;
	if (line[i] != '-')
		return (0);
	i++;
	j = 0;
	while (data->anthill[j] != NULL && (tr1 < 0 || tr2 < 0))
	{
		if (ft_strncmp(line, data->anthill[j], b) == 0
			&& data->anthill[j][b] == '\0')
			tr1 = j;
		if (ft_strcmp(line + i, data->anthill[j]) == 0)
			tr2 = j;
		j++;
	}
	if (tr1 >= 0 && tr2 >= 0)
		return (lem_in_parse_get_links_matrix(data, tr1, tr2));
	return (0);
}
