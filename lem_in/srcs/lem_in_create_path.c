/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_create_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:44:10 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:38:45 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_path	*lem_in_free_then_abort(t_path *path)
{
	free(path);
	return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
}

static	void	lem_in_dup_path(int *dest, int *src, int steps)
{
	int	i;

	i = 0;
	while (i < steps)
	{
		dest[i] = src[i];
		i++;
	}
}

t_path			*lem_in_create_path(t_lem_in_data *data, int room_id,
					int *n_path, t_path *dup)
{
	t_path	*elem;
	int		*tab;

	if (data == 0)
		return (ft_msg_ptr(2, "lem_in_data is null.\n", 0));
	if (!(elem = (t_path *)malloc(sizeof(t_path))))
		return (ft_msg_ptr(2, "Abort, failed malloc\n", 0));
	elem->path_id = *n_path;
	elem->steps = 1;
	elem->previous = NULL;
	elem->next = NULL;
	if (!(tab = (int *)malloc(sizeof(int) * data->n_room)))
		return (lem_in_free_then_abort(elem));
	if (dup != NULL)
	{
		elem->steps = dup->steps;
		lem_in_dup_path(tab, dup->path, dup->steps);
	}
	elem->path = tab;
	*n_path += 1;
	(elem->path)[elem->steps - 1] = room_id;
	return (elem);
}
