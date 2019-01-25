/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_visual_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:54:27 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/18 13:22:40 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	ft_checker_check_command_visual(char *str, t_ps_window *window)
{
	if (ft_strcmp(str, "sa\n") != 0 && ft_strcmp(str, "sb\n") != 0 &&\
			ft_strcmp(str, "ss\n") != 0 && ft_strcmp(str, "pa\n") != 0 &&\
			ft_strcmp(str, "pb\n") != 0 && ft_strcmp(str, "ra\n") != 0 &&\
			ft_strcmp(str, "rb\n") != 0 && ft_strcmp(str, "rr\n") != 0 &&\
			ft_strcmp(str, "rra\n") != 0 && ft_strcmp(str, "rrb\n") != 0 &&\
			ft_strcmp(str, "rrr\n") != 0)
		return (0);
	if (ft_strcmp(str, "pa\n") == 0 && window->b != NULL)
	{
		window->jumpb = window->jumpb + 1;
		window->jumpa = window->jumpa - 1;
	}
	if (ft_strcmp(str, "pb\n") == 0 && window->a != NULL)
	{
		window->jumpb = window->jumpb - 1;
		window->jumpa = window->jumpa + 1;
	}
	return (1);
}

void	ft_checker_check_result_visual(t_stack **a, t_stack **b, t_ps_window *window)
{
	t_stack *tmp;

	if (*b != NULL)
	{
		write(1, "KO\n", 3);
		window->play = 0;
		push_swap_display_check(a, b, window);
		return ;
	}
	tmp = *a;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->nb < tmp->next->nb)
			tmp = tmp->next;
		else
		{
			write(1, "KO\n", 3);
			window->play = 0;
			push_swap_display_check(a, b, window);
			return ;
		}
	}
	write(1, "OK\n", 3);
	push_swap_display_check(a, b, window);
	window->play = 0;
}

#include <stdio.h>

int	push_swap_visual_command(t_ps_window *window)
{
	char	*buff;
	int		tr;

	buff = NULL;
	tr = 0;
	if (window->play == 1)
	{
		tr = push_swap_get_next_line(window->fd, &buff);
		if (tr < 0)
		{
			write(2, "Error\n", 6);
			push_swap_destroy_window(window);
			return (0);
		}
		if (tr == 0)
			ft_checker_check_result_visual(&window->a, &window->b, window);
		else if (ft_checker_check_command_visual(buff, window) == 0)
			write(2, "Wrong Input\n", 12);
		else if (tr > 0)
		{
			ft_push_swap_do_command(buff, &window->a, &window->b);
			push_swap_display(&window->a, &window->b, window, buff);
		}
		free(buff);
	}
	return (tr);
}
