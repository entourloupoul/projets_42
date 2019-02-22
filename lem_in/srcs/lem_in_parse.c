/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 17:13:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 17:16:31 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lem_in.h"

int				lem_in_parse_get_other(char *line, t_lem_in_data *data,\
		t_parse **rooms, t_file *file)
{
	int	tr;

	tr = 0;
	if (data->endroom == 0)
		tr = lem_in_parse_get_rooms(line, data, rooms, file);
	if (tr == 0 && data->endroom == 0)
		tr = lem_in_create_anthill_matrix(data, *rooms);
	if (tr == 0 && data->endroom == 1)
		tr = lem_in_parse_get_links(line, data, -1, -1);
	if (tr == 0)
		return (ft_msg_int(2, "Abort, not a pipe, not a room\n", -1));
	return (tr);
}

int				lem_in_parse_line(char *line, t_lem_in_data *data,\
		t_file **file, t_parse **rooms)
{
	int	tr;

	tr = 1;
	if (lem_in_fill_file(line, file) < 0)
		return (-2);
	if (line[0] != '#')
	{
		if (data->n_ant == 0)
			tr = lem_in_parse_get_ants(line, data);
		else
			tr = lem_in_parse_get_other(line, data, rooms, *file);
	}
	else
	{
		if (ft_strcmp(line, "##start") == 0)
			data->start = data->start == -1 ? 1 : -2;
		else if (ft_strcmp(line, "##end") == 0)
			data->end = data->end == -1 ? 1 : -2;
		if (data->start == -2 || data->end == -2)
			return (ft_msg_int(2, "Abort, double start or end input\n", -1));
	}
	if (tr < 0)
		return (tr);
	return (1);
}

void			lem_in_delete_last_entry_file(t_file **file, char *line)
{
	t_file	*tmp;
	int		len;
	int		i;

	len = ft_strlen(line);
	tmp = *file;
	if (tmp == 0)
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = 0;
	while (i <= len + 1)
	{
		tmp->buff[tmp->size - i] = '\0';
		i++;
	}
	tmp->size = tmp->size - i + 1;
}

int				lem_in_read(t_lem_in_data *data)
{
	char	*line;
	int		tr;
	int		tr2;
	t_file	*file;
	t_parse	*rooms;

	file = NULL;
	line = NULL;
	rooms = NULL;
	tr2 = 1;
	while (tr2 == 1 && (tr = get_next_line(0, &line)) > 0)
	{
		tr2 = lem_in_parse_line(line, data, &file, &rooms);
		if (tr2 < 0)
			lem_in_delete_last_entry_file(&file, line);
		free(line);
		line = NULL;
	}
	data->file = file;
	lem_in_free_rooms(&rooms);
	if (tr < 0)
		return (ft_msg_int(2, "Abort, failed gnl\n", -1));
	if (tr2 == -2)
		return (-2);
	return (1);
}

t_lem_in_data	*lem_in_parse(int argc, char **argv, int tr)
{
	t_lem_in_data	*data;

	if (!(data = (t_lem_in_data *)malloc(sizeof(t_lem_in_data) * 1)))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	data->n_ant = 0;
	data->n_room = 0;
	data->fd = 1;
	data->endroom = 0;
	data->start = -1;
	data->end = -1;
	data->options = 0;
	data->anthill = NULL;
	data->matrix = NULL;
	data->matrix_old = NULL;
	data->reached = NULL;
	data->file = NULL;
	data->win_ptr = NULL;
	if (argc > 1)
		tr = lem_in_get_options(argc, argv, data);
	if (tr > 0)
		tr = lem_in_read(data);
	if (tr < 0 || data->anthill == NULL)
		lem_in_free_data(&data);
	return (data);
}
