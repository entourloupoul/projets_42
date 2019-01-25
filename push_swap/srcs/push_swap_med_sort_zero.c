/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med_sort_zero.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:07:53 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/25 17:44:02 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_med_sort_zero_a31(t_ps *all, int type)
{
	if (type == 1 || type == 2 || type == 4)
	{
		push_swap_write_do("pa\n", all);
		push_swap_write_do("sb\n", all);
		push_swap_write_do("pa\n", all);
		if (type == 1 || type == 2)
			push_swap_write_do("sa\n", all);
		push_swap_write_do("pa\n", all);
		if (type == 1)
			push_swap_write_do("sa\n", all);
	}
	else if (type == 3 || type == 5 || type == 6)
	{
		push_swap_write_do("pa\n", all);
		push_swap_write_do("pa\n", all);
		if (type == 5 || type == 6)
			push_swap_write_do("sa\n", all);
		push_swap_write_do("pa\n", all);
		if (type == 5)
			push_swap_write_do("sa\n", all);
	}
}

void	push_swap_med_sort_zero_a3(t_ps *all, int *pl)
{
	int type;
	
	type = -1;
	if (pl[1] < pl[2] && pl[1] < pl[3] && pl[2] < pl[3])
		type = 1;
	if (pl[1] > pl[2] && pl[1] < pl[3] && pl[2] < pl[3])
		type = 2;
	if (pl[1] > pl[2] && pl[1] > pl[3] && pl[2] > pl[3])
		type = 3;
	if (pl[1] > pl[2] && pl[1] > pl[3] && pl[2] < pl[3])
		type = 4;
	if (pl[1] < pl[2] && pl[1] < pl[3] && pl[2] > pl[3])
		type = 5;
	if (pl[1] < pl[2] && pl[1] > pl[3] && pl[2] > pl[3])
		type = 6;
	push_swap_med_sort_zero_a31(all, type);
}
	

void	push_swap_med_sort_zero_a(t_ps *all, int i)
{
	t_stack *tmpb;
	int		pl[4];

	pl[0] = 0;
	tmpb = all->b;
	while (pl[0] < all->numb[i])
	{
		pl[pl[0] + 1] = tmpb->place;
		tmpb = tmpb->next;
		pl[0]++;
	}
	if (all->numb[i] == 3 )
		push_swap_med_sort_zero_a3(all, pl);		
	else if (all->numb[i] == 2)
	{
		if (pl[1] < pl[2])
			push_swap_write_do("sb\n", all);
		push_swap_write_do("pa\n", all);
		push_swap_write_do("pa\n", all);
	}
	else if (all->numb[i] == 1)
		push_swap_write_do("pa\n", all);
	all->elema0 = all->elema0 + all->elema1 + all->numb[i];
	all->numb[i] = 0;
	all->elema1 = 0;
}

	


void	push_swap_med_sort_zero(t_ps *all, int i)
{

	if (all->elema1 < 3)
		push_swap_med_sort_zero_a(all, i);
}
