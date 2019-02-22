/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_unload_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 11:30:13 by erli              #+#    #+#             */
/*   Updated: 2019/02/06 14:04:38 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

static	void		lem_in_print_unload(t_lem_in_data *data)
{
	char	buf[B_SIZE + 1];
	int		i;

	i = 1;
	ft_bzero(buf, B_SIZE + 1);
	data->buf = buf;
	data->buf_cursor = 0;
	while (i <= data->n_ant)
	{
		lem_in_print(data, i, data->end, 0);
		i++;
	}
	(data->buf)[data->buf_cursor - 1] = '\n';
	write(data->fd, data->buf, data->buf_cursor);
}

void				lem_in_unload_ants(t_lem_in_data *data, t_path *path)
{
	if (path == 0)
		return ;
	if (path->steps == 1 && (path->path)[0] == data->end)
	{
		lem_in_print_file(data);
		lem_in_print_unload(data);
		free(path->path);
		free(path);
		if (LI_OPT_STEPS(data->options))
			lem_in_print_total_step(data, 1);
		if (!(LI_OPT_GRAPH(data->options)))
		{
			lem_in_free_data(&data);
			exit(0);
		}
	}
}
