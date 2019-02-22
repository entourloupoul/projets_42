/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_free_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:56:52 by erli              #+#    #+#             */
/*   Updated: 2019/02/05 14:35:50 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_free_path(t_path *path, int mode)
{
	free(path->path);
	if (mode == 1)
		free(path->occupants);
	if (mode == 0)
		free(path);
}
