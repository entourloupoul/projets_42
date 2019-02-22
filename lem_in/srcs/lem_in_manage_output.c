/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_manage_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:31:59 by erli              #+#    #+#             */
/*   Updated: 2019/02/06 15:53:26 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>
#include <fcntl.h>

void			lem_in_manage_output(t_lem_in_data *data)
{
	int fd;

	if (data == 0)
		return ;
	if (!(LI_OPT_OUT(data->options)))
		data->fd = 1;
	else
	{
		fd = open(OUTPUT_PATH, O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, 0644);
		if (fd > 0)
			data->fd = fd;
		else
		{
			write(1, "Failed to open output file.\n", 28);
			data->fd = 1;
		}
	}
}
