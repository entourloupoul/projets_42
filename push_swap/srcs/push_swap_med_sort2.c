/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med_sort2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 15:35:57 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/25 18:00:34 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

#include <stdio.h>

void    push_swap_med_sorta31(t_ps *all, int nb)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = all->a;
	tmpb = all->b;
	if (tmpa->next->place > tmpa->next->next->place)
	{
		if (nb > 2 && tmpb->next->place < tmpb->next->next->place)
		{
			push_swap_write_do("rr\n", all);
			push_swap_write_do("ss\n", all);
			push_swap_write_do("rrr\n", all);
		}
		else
		{
			push_swap_write_do("ra\n", all);
			push_swap_write_do("sa\n", all);
			push_swap_write_do("rra\n", all);
		}
	}
}

void    push_swap_med_sortb(t_ps *all, int nb, int i)
{
	t_stack *tmpb;

	tmpb = all->b;
	if (nb > 1)
	{
		if (tmpb->place < tmpb->next->place)
			push_swap_write_do("sb\n", all);
		tmpb = all->b;
		if (nb > 2 && tmpb->next->place < tmpb->next->next->place)
		{
			push_swap_write_do("rb\n", all);
			push_swap_write_do("sb\n", all);
			push_swap_write_do("rrb\n", all);
		}
		tmpb = all->b;
		if (tmpb->place < tmpb->next->place)
			push_swap_write_do("sb\n", all);
	}
	while (all->numb[i] > 0)
	{
		push_swap_write_do("pa\n", all);
		all->numb[i]--;
		all->elema0++;
	}
}

void    push_swap_med_sorta3(t_ps *all, int i, t_stack **tmpb)
{
	t_stack *tmpa;

	tmpa = all->a;
	if (all->elema1 > 1)
	{
		all->elema0 = all->elema0 + all->elema1;
		if (tmpa->place > tmpa->next->place)
		{
			if (all->numb[i] > 1 && (*tmpb)->place < (*tmpb)->next->place)
				push_swap_write_do("ss\n", all);
			else
				push_swap_write_do("sa\n", all);
		}
		if (all->elema1 == 3)
			push_swap_med_sorta31(all, all->numb[i]);
		tmpa = all->a;
		*tmpb = all->b;
		if (tmpa->place > tmpa->next->place)
		{
			if ( all->numb[i] > 1 && (*tmpb)->place < (*tmpb)->next->place)
				push_swap_write_do("ss\n", all);
			else
				push_swap_write_do("sa\n", all);
		}
	}
	push_swap_med_sortb(all, all->numb[i], i);
}


void	push_swap_med_sort2(t_ps *all, int i)
{
//	int	i;
	t_stack	*tmpb;

	tmpb = all->b;
//	i = 1;
//	while (i < 50 && all->numb[i] != 0)
//		i++;
//	i--;
	//printf("a:%d\nb:%d\n", all->elema1, all->numb[i]);
	push_swap_med_sorta3(all, i, &tmpb);
	all->elema1 = 0;
}

