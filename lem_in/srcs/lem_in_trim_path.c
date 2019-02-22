/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_trim_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 16:58:58 by erli              #+#    #+#             */
/*   Updated: 2019/02/05 12:03:58 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	void	lem_in_del_first(t_path **list)
{
	t_path *head;

	if (list == 0 || *list == 0 || (*list)->next == 0)
		return ;
	head = (*list)->next;
	head->previous = NULL;
	free((*list)->path);
	(*list)->path = NULL;
	free(*list);
	*list = head;
}

static	void	lem_in_del_second(t_path **list)
{
	t_path *second;

	if (list == 0 || *list == 0 || (*list)->next == 0)
		return ;
	second = (*list)->next;
	if (second->next != 0)
		second->next->previous = *list;
	(*list)->next = second->next;
	free(second->path);
	second->path = NULL;
	free(second);
	second = NULL;
}

void			lem_in_trim_path(t_lem_in_data *data, t_path **list)
{
	if (list == 0 || *list == 0)
		return ;
	while ((*list)->next != 0)
	{
		if (((*list)->path)[(*list)->steps - 1] != data->end)
			lem_in_del_first(list);
		else
			lem_in_del_second(list);
	}
}
