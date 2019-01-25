/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:59:36 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/21 10:06:40 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
/*
int		ft_checker_check_stack_a(t_stack *a, t_ps_window *window)
{
	t_stack	*tmp;
	t_stack	*check;
	int		i;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (window != NULL)
			window->min = tmp->nb < window->min ? tmp->nb : window->min;
		if (window != NULL)
			window->max = tmp->nb > window->max ? tmp->nb : window->max;
		check = tmp->next;
		while (check != NULL)
		{
			if (tmp->nb == check->nb)
				return (0);
			check = check->next;
		}
		tmp = tmp->next;
		i++;
	}
	if (window != NULL && (window->jumpb = i) >= 0)
		window->elem = i;
	return (1);
}

int		ft_checker_check_command(char *str)
{
	if (ft_strcmp(str, "sa\n") != 0 && ft_strcmp(str, "sb\n") != 0 &&\
			ft_strcmp(str, "ss\n") != 0 && ft_strcmp(str, "pa\n") != 0 &&\
			ft_strcmp(str, "pb\n") != 0 && ft_strcmp(str, "ra\n") != 0 &&\
			ft_strcmp(str, "rb\n") != 0 && ft_strcmp(str, "rr\n") != 0 &&\
			ft_strcmp(str, "rra\n") != 0 && ft_strcmp(str, "rrb\n") != 0 &&\
			ft_strcmp(str, "rrr\n") != 0)
		return (0);
	return (1);
}

void	ft_checker_check_result(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b != NULL)
	{
		write(1, "KO\n", 3);
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
			return ;
		}
	}
	write(1, "OK\n", 3);
}

int		ft_checker_get_command(t_stack **a, t_ps_window *window)
{
	char	*buff;
	t_stack	*b;

	b = NULL;
	buff = NULL;
	if (window != NULL)
		push_swap_display(a, &b, window, NULL);
	while (push_swap_get_next_line(0, &buff) > 0)
	{	
		if (ft_checker_check_command(buff) == 0)
		{
			free(buff);
			ft_push_swap_free_stack(&b);
			return (0);
		}
		ft_push_swap_do_command(buff, a, &b);
		if (window != NULL)
			push_swap_display(a, &b, window, buff);
		free(buff);
	}
	ft_checker_check_result(a, &b);
	ft_push_swap_free_stack(&b);
	return (1);
}
*/

int		push_swap_checker_chose(t_stack **a, int *f, char *file)
{
	int	fd;

	fd = 0;
	if (f[2] == 1)
	{
		if ((fd = open(file, O_RDONLY)) < 0)
			return (-1);
	}
	if (f[0] == 1)
		return (push_swap_checker_visual(a, f[1], fd));
	else
		return (push_swap_checker_normal(a, fd));
}

int		push_swap_get_stack(t_stack **a, char **argv, int *f, char **file)
{
	t_stack	*tmp;

	tmp = *a;
	while (f[3] < f[5] && f[4] > 0)
	{
		if (f[3] == 1 && ft_strcmp(argv[f[3]], "-v") == 0)
			f[0] = 1;
		else if (f[3] <= 2 && ft_strcmp(argv[f[3]], "-c") == 0)
			f[1] = 1;
		else if (f[3] <= 3 && ft_strcmp(argv[f[3]], "-o") == 0)
		{	
			f[2] = 1;
			if (f[3] + 1 < f[5])
			{
				if (!(*file = ft_strdup(argv[f[3] + 1])))
					return (-1);
				f[3]++;
			}
		}
		else
			f[4] = ft_push_swap_create_stack(a, &tmp, argv[f[3]]);
		f[3]++;
	}
	return (f[4]);
}

int		main(int argc, char **argv)
{
	int		tr;
	t_stack	*a;
	int		f[6];
	char	*file;

	file = NULL;
	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 1;
	f[4] = 1;
	f[5] = argc;
	if (argc < 2)
		return (0);
	a = NULL;
	tr = push_swap_get_stack(&a, argv, f, &file);
	if (tr > 0)
		tr = push_swap_checker_chose(&a, f, file);
	if (tr < 0)
		write(2, "Error\n", 6);
	if (file != NULL)
		free(file);
	return (0);
}
