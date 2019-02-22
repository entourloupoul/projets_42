/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_del_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:48:31 by erli              #+#    #+#             */
/*   Updated: 2019/02/01 12:45:59 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			lem_in_del_list(t_path **list)
{
	t_path *bubble;
	t_path *tmp;

	if (list == 0 || *list == 0)
		return ;
	bubble = (*list)->next;
	while (bubble != 0)
	{
		tmp = bubble;
		bubble = bubble->next;
		free(tmp->path);
		free(tmp);
	}
	free((*list)->path);
	free(*list);
	*list = NULL;
}
