/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_do_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 10:06:09 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/23 13:20:55 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_move_s(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		tr;

	tr = c == 's' ? 1 : 0;
	if ((c == 'a' || tr == 1) && (*a != NULL && (*a)->next != NULL))
	{
		tmp1 = *a;
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*a = tmp2;
	}
	if ((c == 'b' || tr == 1) && (*b != NULL && (*b)->next != NULL))
	{
		tmp1 = *b;
		tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		tmp2->next = tmp1;
		*b = tmp2;
	}
}

void	ft_push_swap_move_p(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (c == 'a' && *b != NULL)
	{
		tmp1 = *b;
		tmp2 = tmp1->next;
		tmp1->next = *a;
		*b = tmp2;
		*a = tmp1;
	}
	if (c == 'b' && *a != NULL)
	{
		tmp1 = *a;
		tmp2 = tmp1->next;
		tmp1->next = *b;
		*a = tmp2;
		*b = tmp1;
	}
}

void	ft_push_swap_move_r(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		tr;

	tr = c == 'r' ? 1 : 0;
	if ((c == 'a' || tr == 1) && (*a != NULL && (*a)->next != NULL))
	{
		tmp1 = *a;
		*a = tmp1->next;
		tmp1->next = NULL;
		tmp2 = *a;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
	}
	if ((c == 'b' || tr == 1) && (*b != NULL && (*b)->next != NULL))
	{
		tmp1 = *b;
		*b = tmp1->next;
		tmp1->next = NULL;
		tmp2 = *b;
		while (tmp2->next != NULL)
			tmp2 = tmp2->next;
		tmp2->next = tmp1;
	}
}

void	ft_push_swap_move_rr(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		tr;

	tr = c == 'r' ? 1 : 0;
	if ((c == 'a' || tr == 1) && (*a != NULL && (*a)->next != NULL))
	{
		tmp1 = *a;
		while (tmp1->next->next != NULL)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		tmp2->next = *a;
		*a = tmp2;
	}
	if ((c == 'b' || tr == 1) && (*b != NULL && (*b)->next != NULL))
	{
		tmp1 = *b;
		while (tmp1->next->next != NULL)
			tmp1 = tmp1->next;
		tmp2 = tmp1->next;
		tmp1->next = NULL;
		tmp2->next = *b;
		*b = tmp2;
	}
}

void	ft_push_swap_do_command(char *command, t_stack **a, t_stack **b)
{
	if (command[0] == 's')
	{
		ft_push_swap_move_s(a, b, command[1]);
	}
	if (command[0] == 'p')
	{
		ft_push_swap_move_p(a, b, command[1]);
	}
	if (command[0] == 'r' && command[2] == '\n')
	{
		ft_push_swap_move_r(a, b, command[1]);
	}
	if (command[0] == 'r' && command[1] == 'r')
	{
		ft_push_swap_move_rr(a, b, command[2]);
	}
}
