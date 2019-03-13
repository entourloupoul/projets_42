/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_visual.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 12:12:32 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/30 08:48:33 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker_visual_check_stack_a(t_stack *a, t_ps_window *window)
{
	t_stack	*tmp;
	t_stack	*check;
	int		i;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		window->min = tmp->nb < window->min ? tmp->nb : window->min;
		window->max = tmp->nb > window->max ? tmp->nb : window->max;
		check = tmp->next;
		while (check != NULL)
		{
			if (tmp->nb == check->nb)
				return (-1);
			check = check->next;
		}
		tmp = tmp->next;
		i++;
	}
	window->jumpb = i;
	window->elem = i;
	window->jumpa = 0;
	return (1);
}

int		push_swap_deal_key(int key, t_ps_window *window)
{
	if (key == 49)
		window->play = window->play == 1 ? 0 : 1;
	if (key == 53)
		push_swap_destroy_window(window);
	return (0);
}

int		push_swap_checker_visual_command(t_ps_window *window, int fd)
{
	window->range = window->max - window->min;
	window->range = window->range < 0 ? -window->range : window->range;
	window->range = window->range == 0 ? 1 : window->range;
	window->minsize = 850 / window->range;
	window->minsize = window->minsize < 5 ? 5 : window->minsize;
	window->fd = fd;
	window->step = 850 / window->elem;
	window->play = 0;
	push_swap_display(&window->a, &window->b, window, NULL);
	mlx_hook(window->win, 17, 0, push_swap_destroy_window, window);
	mlx_key_hook(window->win, push_swap_deal_key, window);
	mlx_loop_hook(window->mlx, push_swap_visual_command, window);
	mlx_loop(window->mlx);
	return (1);
}

int		push_swap_checker_visual(t_stack **a, int c, int fd)
{
	t_ps_window	*window;
	t_stack		*b;

	b = NULL;
	if (!(window = (t_ps_window *)malloc(sizeof(t_ps_window) * 1)))
		return (-1);
	window->min = (*a)->nb;
	window->max = (*a)->nb;
	window->color = c;
	if (ft_checker_visual_check_stack_a(*a, window) < 0)
	{
		free(window);
		return (-1);
	}
	if (push_swap_create_window(window) < 0)
		return (-1);
	window->a = *a;
	window->b = b;
	if (push_swap_checker_visual_command(window, fd) < 0)
		return (-1);
	return (1);
}
