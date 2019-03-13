/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_med_backb15.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 07:17:15 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 07:26:31 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_med_backb16(t_ps *all, int *nb, int *cpt)
{
	push_swap_write_do("rr\n", all);
	all->ra++;
	nb[0]++;
	*cpt = *cpt + 1;
}

void	push_swap_med_backb15(t_ps *all, int i)
{
	push_swap_write_do("pa\n", all);
	all->numb[i]--;
	all->elema1++;
}
