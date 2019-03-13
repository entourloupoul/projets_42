/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_normal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:14:10 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/28 14:02:34 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker_check_stack_a(t_stack *a)
{
	t_stack *tmp;
	t_stack *check;

	tmp = a;
	while (tmp != NULL)
	{
		check = tmp->next;
		while (check != NULL)
		{
			if (tmp->nb == check->nb)
				return (0);
			check = check->next;
		}
		tmp = tmp->next;
	}
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
	t_stack *tmp;

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

int		ft_checker_get_command(t_stack **a, int fd)
{
	char	*buff;
	t_stack	*b;

	b = NULL;
	buff = NULL;
	while (push_swap_get_next_line(fd, &buff) > 0)
	{
		if (ft_checker_check_command(buff) == 0)
		{
			free(buff);
			ft_push_swap_free_stack(&b);
			return (0);
		}
		ft_push_swap_do_command(buff, a, &b);
		free(buff);
	}
	ft_checker_check_result(a, &b);
	ft_push_swap_free_stack(&b);
	return (1);
}

int		push_swap_checker_normal(t_stack **a, int fd)
{
	if (ft_checker_check_stack_a(*a) == 0)
	{
		ft_push_swap_free_stack(a);
		return (-1);
	}
	if (ft_checker_get_command(a, fd) == 0)
	{
		ft_push_swap_free_stack(a);
		return (-1);
	}
	ft_push_swap_free_stack(a);
	return (1);
}
