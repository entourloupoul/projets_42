/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_destroy_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:38:14 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/18 11:23:03 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_destroy_window(t_ps_window *window)
{
	mlx_destroy_image(window->mlx, window->ima);
	mlx_destroy_window(window->mlx, window->win);
	ft_push_swap_free_stack(&window->a);
	ft_push_swap_free_stack(&window->b);
	exit(0);
}
