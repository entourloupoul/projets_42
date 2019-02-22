/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_path_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:33:14 by erli              #+#    #+#             */
/*   Updated: 2019/02/04 11:18:56 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_path_add(t_path **list, t_path *path)
{
	t_path *tmp;

	if (list == 0 || path == 0)
		return ;
	if (*list == 0)
		*list = path;
	else if ((*list)->next == 0)
	{
		(*list)->next = path;
		path->previous = *list;
	}
	else
	{
		tmp = (*list)->next;
		tmp->previous = path;
		path->next = tmp;
		(*list)->next = path;
		path->previous = *list;
	}
}
