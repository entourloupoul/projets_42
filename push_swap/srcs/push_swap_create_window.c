/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_create_window.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 10:48:00 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/18 08:40:05 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_create_image(t_ps_window *window)
{
	window->width = 2000;
	window->heigth = 1000;
	if (!(window->ima = mlx_new_image(window->mlx, window->width,\
					window->heigth)))
	{
		mlx_destroy_window(window->mlx, window->win);
		free(window);
		return (-1);
	}
	if (!(window->data = mlx_get_data_addr(window->ima, &window->bpp,\
					&window->sizeline, &window->endian)))
	{
		mlx_destroy_image(window->mlx, window->ima);
		mlx_destroy_window(window->mlx, window->win);
		free(window);
		return (-1);
	}
	return (1);
}

int	push_swap_create_window(t_ps_window *window)
{
	if (!(window->mlx = mlx_init()))
	{
		free(window);
		return (-1);
	}
	if (!(window->win = mlx_new_window(window->mlx, 2000, 1000, "push_swap")))
	{
		free(window);
		return (-1);
	}
	if (push_swap_create_image(window) == -1)
		return (-1);
	return (1);
}
