/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 13:58:57 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/10 17:30:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include <unistd.h>

static	int		visu_close(void *arg)
{
	t_visu_data *data;

	if (arg == 0)
		return (0);
	data = (t_visu_data *)arg;
	visu_free_data(&data);
	exit(0);
}

static	int		visu_loop_hook(void *arg)
{
	t_visu_data *data;

	if (arg == 0)
		return (0);
	data = (t_visu_data *)arg;
	if (!VI_PLAY_AUTO(data->play_param))
		return (0);
	if (visu_get_instructions(data) < 0)
	{
		visu_free_data(&data);
		exit(0);
	}
	sleep(1);
	return (0);
}

static	int		visu_key(int key, void *arg)
{
	t_visu_data *data;
	int			ret;

	ret = 0;
	if (arg == 0)
		return (0);
	data = (t_visu_data *)arg;
	if (key == 9)
		data->play_param = ((1 << 2) | 1);
	else if (key == 11)
	{
		data->play_param = (1 << 1);
		ret = visu_get_instructions(data);
	}
	else if (key == 49)
	{
		data->play_param = 1;
		ret = visu_get_instructions(data);
	}
	if (key == 53 || ret < 0)
	{
		visu_free_data(&data);
		exit(0);
	}
	return (0);
}

static	void	visu_loop(t_visu_data *data)
{
	int	pioneers[data->n_ant];

	ft_bzero(pioneers, sizeof(int) * data->n_ant);
	data->pioneers = pioneers;
	mlx_loop_hook(data->mlx_ptr, &visu_loop_hook, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), &visu_close, data);
	mlx_hook(data->win_ptr, 2, (1L << 0), &visu_key, data);
	mlx_loop(data->mlx_ptr);
	visu_free_data(&data);
}

int				main(int argc, char **argv)
{
	t_visu_data *data;

	data = NULL;
	if (!(data = visu_parse(argc, argv)))
		return (0);
	visu_remap(data);
	if (visu_init_visu(data) < 0)
	{
		visu_free_data(&data);
		return (0);
	}
	visu_draw_anthill(data);
	visu_loop(data);
	return (0);
}
