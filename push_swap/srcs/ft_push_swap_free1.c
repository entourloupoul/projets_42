/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_free1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:12:50 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/18 09:57:24 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_free_stack(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (*a == NULL)
		return ;
	while (tmp != NULL)
	{
		*a = tmp->next;
		free(tmp);
		tmp = *a;
	}
}
