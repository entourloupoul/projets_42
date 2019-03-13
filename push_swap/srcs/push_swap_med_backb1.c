/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med_backb1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:02:47 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 07:26:34 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_med_backb12(t_ps *all)
{
	push_swap_write_do("ra\n", all);
	all->ra++;
}

int		push_swap_med_backb13(t_ps *all)
{
	push_swap_write_do("rb\n", all);
	return (1);
}

int		push_swap_med_backb141(t_ps *all, int j, int med, int *nb)
{
	t_stack *tmpb;

	tmpb = all->b;
	while (j < nb[1])
	{
		if (tmpb->place >= med)
			return (1);
		j++;
		tmpb = tmpb->next;
	}
	return (0);
}

void	push_swap_med_backb14(t_ps *all, int *cpt, int *nb, int med)
{
	int j;

	j = *cpt + 1;
	if (push_swap_med_backb141(all, j, med, nb) == 0)
	{
		if (nb[1] - *cpt + 1 > nb[1] / 4)
		{
			j = 0;
			while (j < nb[0])
			{
				push_swap_write_do("rrb\n", all);
				j++;
			}
		}
		else
		{
			j = *cpt + 1;
			while (j < nb[1])
			{
				push_swap_write_do("rb\n", all);
				j++;
			}
		}
		*cpt = nb[1];
	}
}

void	push_swap_med_backb1(t_ps *all, int med, int i, int cpt)
{
	t_stack *tmpb;
	t_stack *tmpb1;
	int		nb[2];

	nb[0] = 0;
	nb[1] = all->numb[i];
	while (cpt < nb[1])
	{
		tmpb = all->b;
		if (tmpb->place >= med)
		{
			push_swap_med_backb15(all, i);
			tmpb1 = all->b;
			if (tmpb->place >= med + nb[1] / 4 && nb[1] > 6 &&\
					tmpb1->place < med && cpt + 1 < nb[1])
				push_swap_med_backb16(all, nb, &cpt);
			else if (tmpb->place >= med + nb[1] / 4 && nb[1] > 6)
				push_swap_med_backb12(all);
		}
		else
			nb[0] = nb[0] + push_swap_med_backb13(all);
		push_swap_med_backb14(all, &cpt, nb, med);
		cpt++;
	}
}
