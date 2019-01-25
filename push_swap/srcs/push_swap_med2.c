/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 11:15:45 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/25 18:52:03 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	push_swap_med_backb1(t_ps *all, int med, int i)
{
	int	cpt;
	int	nb;
	t_stack	*tmpb;
	t_stack	*tmpb1;

	int rrb;
	rrb = 0;

	cpt = 0;
	nb = all->numb[i];
	while (cpt < nb)
	{
		tmpb = all->b;
		if (tmpb->place >= med)
		{
			push_swap_write_do("pa\n", all);
			all->numb[i]--;
			all->elema1++;
			tmpb1 = all->b;
			if (tmpb->place >= med + nb / 4 && nb > 6 && tmpb1->place < med && cpt + 1 < nb)
			{	
				push_swap_write_do("rr\n", all);
				all->ra++;
				rrb++;
				cpt++;
			}
			else if (tmpb->place >= med + nb / 4 && nb > 6)
			{	
				push_swap_write_do("ra\n", all);
				all->ra++;
			}
		}
		else
		{
			push_swap_write_do("rb\n", all);
			rrb++;
			//enlever rrb;
		}
		
		tmpb = all->b;
		int j;
		int tr;
		tr = 0;
		j = cpt + 1;
		while (j < nb)
		{
			if (tmpb->place >= med)
				tr = 1;
			j++;
			tmpb = tmpb->next;
		}
		if (tr == 0)
		{
			if (nb - cpt + 1 >  nb / 4)
			{
				j = 0;
				while (j < rrb)
				{
					push_swap_write_do("rrb\n", all);
					j++;
				}
			}
			else
			{
				j = cpt + 1;
				while (j < nb)
				{
					push_swap_write_do("rb\n", all);
					j++;
				}
			}
			cpt = nb;
		}



		cpt++;
	}
}

void	push_swap_med_backb2(t_ps *all, int med, int i, int cpt)
{
	int	nb;
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
			if (tmpb->place >= med + nb / 4 && nb > 6 && all->elem - all->elema1 > 0)
			{
				push_swap_write_do("ra\n", all);
				all->ra++;
			}
		}
//		else
//			push_swap_write_do("rb\n", all);
		cpt++;
	}
}

void	push_swap_med_backb(t_ps *all, int i)
{
	int	med;
	t_stack	*tmpb;

	med = all->elem - all->elema0 - all->numb[i] / 2;
	tmpb = all->b;
	if (tmpb != NULL)
	{
		if (tmpb->place > all->elem - all->elema0 - all->numb[i])
			push_swap_med_backb1(all, med, i);
		else
			push_swap_med_backb2(all, med, i, 0);
	}
}

void	push_swap_med2(t_ps *all)
{
	int	i;
	int	cpt;
	int	med;
	t_stack	*tmpb;
	t_stack *tmpa;
	t_stack *tmpb2;

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
			cpt = 0;
			tmpb = all->b;
			while (cpt < all->numb[i] || cpt < all->ra)
			{
				med = all->elem - all->elema0 - all->elema1 - all->numb[i];
				if (cpt < all->numb[i] && cpt < all->ra && tmpb->place <= med)
				{
					push_swap_write_do("rrr\n", all);
					tmpb2 = all->b;
					tmpa = all->a;
		//			if (cpt > 0 && tmpa->place > tmpa->next->place && tmpb2->place < tmpb2->next->place)
		//				push_swap_write_do("ss\n", all);
					if (cpt > 0 && tmpa->place > tmpa->next->place)
						push_swap_write_do("sa\n", all);
	//				else if (cpt > 0 && tmpb2->place < tmpb2->next->place)
	//					push_swap_write_do("sb\n", all);
				}
				else if (cpt < all->numb[i] && tmpb->place <= med)
				{
					push_swap_write_do("rrb\n", all);
					tmpb2 = all->b;
		//			if (cpt > 0 && tmpb2->place < tmpb2->next->place)
		//				push_swap_write_do("sb\n", all);
				}
				else if (cpt < all->ra)
				{
					push_swap_write_do("rra\n", all);
					tmpa = all->a;
					if (cpt > 0 && tmpa->place > tmpa->next->place)
						push_swap_write_do("sa\n", all);
				}
				cpt++;
			}
			all->ra = 0;	
			push_swap_med_sort(all);
		}
	}
}

