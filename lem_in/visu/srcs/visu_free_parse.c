/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_free_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:44:35 by erli              #+#    #+#             */
/*   Updated: 2019/02/06 18:45:08 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	visu_free_parse(t_parse **rooms)
{
	t_parse	*tmp;

	tmp = *rooms;
	if (rooms == NULL || *rooms == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(*rooms);
		*rooms = NULL;
		*rooms = tmp;
	}
	return ;
}
