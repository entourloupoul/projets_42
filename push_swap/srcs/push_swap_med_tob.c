/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med_tob.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:12:23 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 07:56:01 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_med_tob1(t_ps *all, int med, int i)
{
	int		cpt;
	int		nb;
	t_stack	*tmpa;

	cpt = 0;
	nb = all->elema1 - all->ra;
	while (cpt < nb)
	{
		tmpa = all->a;
		push_swap_write_do("pb\n", all);
		all->elema1--;
		if (tmpa->place <= med + nb / 4 && nb > 3)
		{
			push_swap_write_do("rb\n", all);
			all->numb[i + 1]++;
		}
		else
			all->numb[i + 2]++;
		cpt++;
	}
	if (all->numb[i + 1] == 0)
	{
		all->numb[i + 1] = all->numb[i + 2];
		all->numb[i + 2] = 0;
	}
}

void	push_swap_med_tob21(t_ps *all, int i)
{
	push_swap_write_do("rb\n", all);
	all->numb[i + 1]++;
}

void	push_swap_med_tob22(t_ps *all, int i)
{
	all->numb[i + 1] = all->numb[i + 2];
	all->numb[i + 2] = 0;
}

void	push_swap_med_tob2(t_ps *all, int med, int i)
{
	int		cpt;
	int		nb;
	t_stack *tmpa;

	cpt = 0;
	nb = all->ra;
	while (cpt < nb)
	{
		push_swap_write_do("rra\n", all);
		tmpa = all->a;
		all->ra--;
		if (tmpa->place < med)
		{
			push_swap_write_do("pb\n", all);
			all->elema1--;
			if (tmpa->place <= med + nb / 4 && nb > 6)
				push_swap_med_tob21(all, i);
			else
				all->numb[i + 2]++;
		}
		cpt++;
	}
	if (all->numb[i + 1] == 0)
		push_swap_med_tob22(all, i);
}

void	push_swap_med_tob(t_ps *all, int i)
{
	int		med;
	t_stack	*tmpa;

	med = all->elem - all->elema0 - all->ra - (all->elema1 - all->ra) / 2;
	tmpa = all->a;
	if (tmpa != NULL)
	{
		push_swap_med_tob1(all, med, i);
		i = 1;
		while (i < 50 && all->numb[i] != 0)
			i++;
		i--;
		med = all->elem - all->elema0 - all->ra / 2;
		if (all->ra > 0)
			push_swap_med_tob2(all, med, i);
	}
}
