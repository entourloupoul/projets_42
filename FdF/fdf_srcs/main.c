/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:56:58 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:41:25 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_param *param)
{
	if (key == 53)
		ft_destroy(param);
	if (key == 123 || key == 124 || key == 125 || key == 126)
		ft_deal_key_trans(key, param);
	if (key == 0 || key == 12 || key == 6 || key == 7)
		ft_deal_key_scale(key, param);
	if (key == 1 || key == 3 || key == 14 || key == 2 || key == 13 || key == 15)
		ft_deal_key_rot(key, param);
	if (key == 35)
		ft_deal_key_proj(param);
	return (0);
}

int	ft_display(t_param *param)
{
	param->proj = 0;
	ft_paral_proj(&param->line, 0.7, param->mat->mat_proj, param->image);
	mlx_put_image_to_window(param->mlx, param->win, param->image->ima, 0, 0);
	ft_putstr_inf(param);
	mlx_key_hook(param->win, deal_key, param);
	mlx_hook(param->win, 17, 0, ft_destroy, param);
	mlx_loop(param->mlx);
	return (0);
}

int	ft_create_image(t_param *param)
{
	if (!(param->mat = ft_mat_first_proj(param->line)))
		return (-1);
	if (!(param->image = (t_image *)malloc(sizeof(t_image))))
		return (-1);
	param->image->width = 2000;
	param->image->heigth = 1300;
	param->image->ima = mlx_new_image(param->mlx, param->image->width,\
			param->image->heigth);
	param->image->data = mlx_get_data_addr(param->image->ima,\
			&param->image->bpp, &param->image->sizeline,\
			&param->image->endian);
	return (0);
}

int	ft_create_window(t_line *line, char *title)
{
	t_param *param;

	if ((!(param = (t_param *)malloc(sizeof(t_param)))))
		return (-1);
	if (!(param->mlx = mlx_init()))
	{
		free(param);
		return (-1);
	}
	if (!(param->win = mlx_new_window(param->mlx, 2000, 1300, title)))
	{
		free(param->mlx);
		free(param);
		return (-1);
	}
	param->line = line;
	if (ft_create_image(param) == -1)
	{
		ft_free_param1(param);
		return (-1);
	}
	ft_display(param);
	ft_free_param(param);
	return (0);
}

int	main(int argc, char **argv)
{
	t_line	*line;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf source_file");
		return (0);
	}
	if (!(line = ft_fdf_get_file(argv[1])))
		return (0);
	if (ft_correct_file(&line) == -1)
	{
		ft_free_line(line);
		return (0);
	}
	if (ft_create_window(line, argv[1]) == -1)
	{
		ft_free_line(line);
		return (0);
	}
	ft_free_line(line);
	return (0);
}
