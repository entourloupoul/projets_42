/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:15:45 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 07:41:03 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_med_backb2(t_ps *all, int med, int i, int cpt)
{
	int		nb;
	t_stack	*tmpb;

	nb = all->numb[i];
	while (cpt < nb)
	{
		push_swap_write_do("rrb\n", all);
		tmpb = all->b;
		if (tmpb->place >= med)
		{
			push_swap_write_do("pa\n", all);
			all->numb[i]--;
			all->elema1++;
			if (tmpb->place >= med + nb / 4 && nb > 6 &&\
					all->elem - all->elema1 > 0)
			{
				push_swap_write_do("ra\n", all);
				all->ra++;
			}
		}
		cpt++;
	}
}

void	push_swap_med_backb(t_ps *all, int i)
{
	int		med;
	t_stack	*tmpb;

	med = all->elem - all->elema0 - all->numb[i] / 2;
	tmpb = all->b;
	if (tmpb != NULL)
	{
		if (tmpb->place > all->elem - all->elema0 - all->numb[i])
			push_swap_med_backb1(all, med, i, 0);
		else
			push_swap_med_backb2(all, med, i, 0);
	}
}

void	push_swap_med21(t_ps *all, int i, int med, int cpt)
{
	t_stack *tmpb;
	t_stack	*tmpa;

	tmpb = all->b;
	while (cpt < all->numb[i] || cpt < all->ra)
	{
		med = all->elem - all->elema0 - all->elema1 - all->numb[i];
		if (cpt < all->numb[i] && cpt < all->ra && tmpb->place <= med)
		{
			push_swap_write_do("rrr\n", all);
			tmpa = all->a;
			if (cpt > 0 && tmpa->place > tmpa->next->place)
				push_swap_write_do("sa\n", all);
		}
		else if (cpt < all->numb[i] && tmpb->place <= med)
			push_swap_write_do("rrb\n", all);
		else if (cpt < all->ra)
		{
			push_swap_write_do("rra\n", all);
			tmpa = all->a;
			if (cpt > 0 && tmpa->place > tmpa->next->place)
				push_swap_write_do("sa\n", all);
		}
		cpt++;
	}
}

void	push_swap_med2(t_ps *all)
{
	int		i;

	all->ra = 0;
	while (all->elema0 < all->elem)
	{
		i = 1;
		while (i < 50 && all->numb[i] != 0)
			i++;
		i--;
		if (all->elema1 <= 3 && all->numb[i] > 3)
			push_swap_med_backb(all, i);
		else
			push_swap_med_tob(all, i);
		i = 1;
		while (i < 50 && all->numb[i] != 0)
			i++;
		i--;
		if (all->elema1 <= 3 && all->numb[i] <= 3)
		{
			push_swap_med21(all, i, 0, 0);
			all->ra = 0;
			push_swap_med_sort(all);
		}
	}
}
