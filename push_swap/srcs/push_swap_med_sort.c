/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:53:41 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 07:42:51 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_med_sort_ahigh(t_ps *all)
{
	t_stack *tmpa;

	tmpa = all->a;
	if (all->elema1 == 3)
	{
		if (tmpa->next->next->place > tmpa->next->place &&\
				tmpa->next->next->place > tmpa->place)
		{
			all->elema0++;
			all->elema1--;
		}
	}
}

void	push_swap_med_sort_alow(t_ps *all, int i)
{
	t_stack *tmpa;
	t_stack *tmpb;

	tmpa = all->a;
	tmpb = all->b;
	if (all->elema1 == 1)
	{
		all->elema0++;
		all->elema1 = 0;
	}
	if (all->elema1 == 2)
	{
		if (tmpa->place > tmpa->next->place && all->numb[i] > 1 &&\
				tmpb->place < tmpb->next->place)
			push_swap_write_do("ss\n", all);
		else if (tmpa->place > tmpa->next->place)
			push_swap_write_do("sa\n", all);
		all->elema0 = all->elema0 + 2;
		all->elema1 = 0;
	}
}

void	push_swap_med_sort(t_ps *all)
{
	int i;

	i = 1;
	while (i < 50 && all->numb[i] != 0)
		i++;
	i--;
	if (i == 1 && all->numb[0] + all->numb[1] <= 3)
	{
		all->numb[1] = all->numb[1] + all->numb[0];
		all->numb[0] = all->numb[1];
	}
	push_swap_med_sort_ahigh(all);
	push_swap_med_sort_alow(all, i);
	push_swap_med_sort_zero(all, i);
	push_swap_med_sort2(all, i);
}
