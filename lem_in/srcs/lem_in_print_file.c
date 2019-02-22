/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:11:01 by erli              #+#    #+#             */
/*   Updated: 2019/02/05 14:20:29 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <unistd.h>

void		lem_in_print_file(t_lem_in_data *data)
{
	t_file	*file;

	if (data == 0)
		return ;
	file = data->file;
	while (file != 0)
	{
		write(data->fd, file->buff, file->size);
		file = file->next;
	}
	write(data->fd, "\n", 1);
}
