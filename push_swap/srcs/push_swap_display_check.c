/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_display_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 12:56:17 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/18 13:33:14 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_draw_elem(t_stack *tmp, t_ps_window *w, int trigger, int y)
{
	int	x;
	int	b;
	int	c;

	c = (int)(((double)tmp->nb - (double)w->min) / (double)w->range *\
			(850 - (double)w->minsize) + (double)w->minsize);
	b = 0;
	while (b < w->step)
	{
		x = trigger + 425 - c / 2;
		while (x < trigger +425 + c / 2)
		{
			*((unsigned int *)(w->data + x * w->bpp / 8 + (y + b)\
						* w->sizeline)) = w->c_stack;
			x++;
		}
		b++;
	}
}



void	push_swap_display_check(t_stack **a, t_stack **b, t_ps_window *window)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp != NULL)
	{
		if (tmp->next == NULL)
			window->c_stack = 0x44F004;
		else
			window->c_stack = tmp->nb < tmp->next->nb ? 0x44F004 : 0xFF0000;
		push_swap_draw_elem(tmp, window, 100, (100 + window->jumpa * window->step));
		window->jumpa++;
		mlx_put_image_to_window(window->mlx, window->win, window->ima, 0, 0);
		tmp = tmp->next;
	}
	tmp = *b;
	window->c_stack = 0xFF0000;
	while (tmp != NULL)
	{
		push_swap_draw_elem(tmp, window, 1050, (100 + window->jumpb * window->step));
		window->jumpb++;
		mlx_put_image_to_window(window->mlx, window->win, window->ima, 0, 0);
		tmp = tmp->next;
	}	
}
