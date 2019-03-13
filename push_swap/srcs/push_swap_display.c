/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:37:44 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/30 08:46:32 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_clear_image(t_ps_window *window)
{
	int	x;
	int	y;

	y = 0;
	while (y < window->heigth)
	{
		x = 0;
		while (x < window->width)
		{
			*((unsigned int *)(window->data + x * window->bpp / 8 + y\
						* window->sizeline)) = 0x000000;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(window->mlx, window->win, window->ima, 0, 0);
}

void	push_swap_draw_stack(t_stack **a, t_ps_window *w, int trigger,\
		int y)
{
	int		x;
	t_stack	*tmp;
	int		b;
	int		c;

	tmp = *a;
	while (tmp != NULL)
	{
		c = (int)(((double)tmp->nb - (double)w->min) / (double)w->range *\
				(850 - (double)w->minsize) + (double)w->minsize);
		b = 0;
		while (b < w->step)
		{
			x = trigger + 425 - c / 2;
			while (x < trigger + 425 + c / 2)
			{
				*((unsigned int *)(w->data + x * w->bpp / 8 + (y + b)\
							* w->sizeline)) = w->c_stack;
				x++;
			}
			b++;
		}
		y = y + w->step;
		tmp = tmp->next;
	}
}

void	push_swap_display(t_stack **a, t_stack **b, t_ps_window *window,\
		char *command)
{
	(void)command;
	push_swap_clear_image(window);
	window->c_stack = 0x5DADE2;
	push_swap_draw_stack(a, window, 100, (100 + window->jumpa * window->step));
	window->c_stack = 0xF07A04;
	push_swap_draw_stack(b, window, 1050, (100 + window->jumpb * window->step));
	mlx_put_image_to_window(window->mlx, window->win, window->ima, 0, 0);
}
