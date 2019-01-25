/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_create_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:12:12 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/25 18:52:06 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


#include <stdio.h>

void	push_swap_push_med12(t_ps *all, int tr, int med1)
{
	int		med;
	t_stack	*tmpb;
	t_stack *tmpa;

	if (all->a == NULL)
		return ;
	push_swap_write_do("pb\n", all);
	tmpb = all->b;
	all->elemb++;
	all->elema1--;
	if (tr > 0)
		all->numb[tr + 1]++;
	if (tr == 0)
	{
		med = med1 / 2;
		tmpa = all->a;
		if (tmpb->place < med && tmpa->place > med1)
		{
			push_swap_write_do("rr\n", all);
			all->numb[0]++;
		}
		else if (tmpb->place < med)
		{
			push_swap_write_do("rb\n", all);
			all->numb[0]++;
		}
		else
		{
			//		push_swap_write_do("ra\n", all);
			all->numb[1]++;
		}
	}
}




void	push_swap_push_med1(t_ps *all, int tr)
{
	t_stack	*tmp;
	int		med;
	int		i;

	i = 1;
	med = all->elema1 / 2 + all->elemb;
	while (i > 0)
	{
		tmp = all->a;
		i = 0;
		while (tmp != NULL)
		{
			i = tmp->place <= med ? 1 : i;
			tmp = tmp->next;
		}
		tmp = all->a;
		if (tmp->place <= med)
		{
			push_swap_push_med12(all, tr, med);
			tmp = all->a;
			i = 0;
			while (tmp != NULL)
			{
				i = tmp->place <= med ? 1 : i;
				tmp = tmp->next;
			}
		}
		else
			push_swap_write_do("ra\n", all);
		tmp = all->a;
		i = 0;
		while (tmp != NULL)
		{
			i = tmp->place <= med ? 1 : i;
			tmp = tmp->next;
		}
	}
}





void	push_swap_sort_and_create(t_ps *all)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = all->a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	all->elem = i;
	all->elema0 = 0;
	all->elema1 = i;
	all->elemb = 0;
	i = 0;
	while (all->elema1 > 3)
	{
		push_swap_push_med1(all, i);
		i++;
	}
	push_swap_med_sort(all);
	push_swap_med2(all);
}

int	push_swap_create_command(t_stack **a, int f, char *file)
{
	t_stack *b;
	t_ps    *all;
	int     i;

	b = NULL;
	if (!(all = (t_ps *)malloc(sizeof(t_ps) * 1)))
		return (-1);
	all->fd = 1;
	if (f == 1)
	{
		if ((all->fd = open(file, O_CREAT, O_WRONLY, O_APPEND)) < 0)
			return (-1);
	}
	all->a = *a;
	all->b = b;
	i = 0;
	while (i < 52)
	{
		all->numb[i] = 0;
		i++;
	}
	push_swap_sort_and_create(all);
	return (1);
}
