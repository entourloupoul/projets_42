/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_free_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:37:55 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 16:35:11 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_free_file(t_file **file)
{
	t_file *tmp;

	tmp = *file;
	if (file == NULL || *file == NULL)
		return ;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free((*file)->buff);
		(*file)->buff = NULL;
		free(*file);
		*file = NULL;
		*file = tmp;
	}
}

static	void	visu_free_tabint(int **tab, int n)
{
	int	i;

	if (tab == NULL)
		return ;
	if (*tab == NULL)
	{
		free(tab);
		return ;
	}
	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static	void	visu_free_ants(t_visu_data *data)
{
	t_ant *prev;
	t_ant *bubble;

	if (data->ants == 0)
		return ;
	prev = data->ants;
	bubble = prev->next;
	while (bubble != 0)
	{
		free(prev);
		prev = bubble;
		bubble = bubble->next;
	}
	free(prev);
}

static	void	visu_free_rooms(t_room *rooms, int n)
{
	int i;

	if (rooms == 0)
		return ;
	i = 0;
	while (i < n)
	{
		free(rooms[i].name);
		i++;
	}
	free(rooms);
}

void			visu_free_data(t_visu_data **data)
{
	int i;

	if (data != NULL)
	{
		if ((*data)->file != NULL)
			visu_free_file(&((*data)->file));
		if ((*data)->anthill != NULL)
			visu_free_rooms((*data)->anthill, (*data)->n_room);
		if ((*data)->matrix != NULL)
			visu_free_tabint((*data)->matrix, (*data)->n_room);
		if ((*data)->ants != NULL)
			visu_free_ants(*data);
		if ((*data)->win_ptr != 0)
			mlx_destroy_window((*data)->mlx_ptr, (*data)->win_ptr);
		if ((*data)->img_ptr != 0)
			mlx_destroy_image((*data)->mlx_ptr, (*data)->img_ptr);
		i = 0;
		while (i < 100 && (*data)->history[i] != NULL)
			free((*data)->history[i++]);
		free(*data);
		*data = NULL;
	}
}
