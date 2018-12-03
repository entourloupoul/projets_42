/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:15:28 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:21:22 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clear_image(t_param *param)
{
	int x;
	int y;

	x = 0;
	while (x < param->image->width)
	{
		y = 0;
		while (y < param->image->heigth)
		{
			*((unsigned int *)(param->image->data + x\
						* param->image->bpp / 8 + y\
				* param->image->sizeline)) = 0x000000;
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(param->mlx, param->win, param->image->ima, 0, 0);
}

void	ft_deal_key_trans(int key, t_param *param)
{
	double	coef;
	char	a;
	double	**mat;

	coef = (key == 123 || key == 126) ? -10 : 10;
	a = (key == 123 || key == 124) ? 'x' : 'y';
	ft_clear_image(param);
	mat = param->mat->mat_tr;
	param->mat->mat_tr = ft_calc_mat2(param->mat->mat_tr,\
			ft_create_matrice("trans", a, coef));
	ft_free_mat(mat, 4);
	mat = param->mat->mat_proj;
	param->mat = ft_calc_mat_proj(param->mat);
	if (param->proj == 0)
		ft_paral_proj(&param->line, 0.7, param->mat->mat_proj, param->image);
	else
		ft_iso_proj(&param->line, param->mat, param->image);
	mlx_put_image_to_window(param->mlx, param->win, param->image->ima, 0, 0);
	ft_putstr_inf(param);
	ft_free_mat(mat, 4);
}

void	ft_deal_key_scale(int key, t_param *param)
{
	double	coef;
	char	a;
	double	**mat;

	coef = (key == 0 || key == 6) ? 0.9 : 1.1;
	a = (key == 0 || key == 12) ? 'z' : 'a';
	ft_clear_image(param);
	mat = param->mat->mat_sc;
	param->mat->mat_sc = ft_calc_mat2(param->mat->mat_sc,\
			ft_create_matrice("scale", a, coef));
	ft_free_mat(mat, 4);
	mat = param->mat->mat_proj;
	param->mat = ft_calc_mat_proj(param->mat);
	if (param->proj == 0)
		ft_paral_proj(&param->line, 0.7, param->mat->mat_proj, param->image);
	else
		ft_iso_proj(&param->line, param->mat, param->image);
	ft_free_mat(mat, 4);
	mlx_put_image_to_window(param->mlx, param->win, param->image->ima, 0, 0);
	ft_putstr_inf(param);
}

void	ft_deal_key_rot(int key, t_param *param)
{
	double	coef;
	char	a;
	double	**mat;

	coef = (key == 1 || key == 2 || key == 13) ? -0.05 : 0.05;
	a = (key == 1 || key == 3) ? 'y' : 'a';
	if (a == 'a')
		a = (key == 14 || key == 2) ? 'x' : 'z';
	ft_clear_image(param);
	mat = param->mat->mat_rot;
	param->mat->mat_rot = ft_calc_mat2(param->mat->mat_rot,\
			ft_create_matrice("rot", a, coef));
	ft_free_mat(mat, 4);
	mat = param->mat->mat_proj;
	param->mat = ft_calc_mat_proj(param->mat);
	if (param->proj == 0)
		ft_paral_proj(&param->line, 0.7, param->mat->mat_proj, param->image);
	else
		ft_iso_proj(&param->line, param->mat, param->image);
	mlx_put_image_to_window(param->mlx, param->win, param->image->ima, 0, 0);
	ft_putstr_inf(param);
	ft_free_mat(mat, 4);
}

void	ft_deal_key_proj(t_param *param)
{
	ft_clear_image(param);
	param->proj = param->proj == 0 ? 1 : 0;
	if (param->proj == 0)
		ft_paral_proj(&param->line, 0.7, param->mat->mat_proj, param->image);
	else
		ft_iso_proj(&param->line, param->mat, param->image);
	mlx_put_image_to_window(param->mlx, param->win, param->image->ima, 0, 0);
	ft_putstr_inf(param);
}
