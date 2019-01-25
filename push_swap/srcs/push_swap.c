/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:46:46 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/24 14:43:47 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int     push_swap_check_stack_a(t_stack *a)
{
	t_stack *tmp;
	t_stack *check;

	tmp = a;
	while (tmp != NULL)
	{
		check = tmp->next;
		while (check != NULL)
		{
			if (tmp->nb == check->nb)
				return (0);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int     push_swap_get_stack(t_stack **a, char **argv, int *f, char **file)
{
	t_stack *tmp;

	tmp = *a;
	while (f[1] < f[3] && f[2] > 0)
	{
		if (f[1] == 1 && ft_strcmp(argv[f[1]], "-o") == 0)
		{
			f[0] = 1;
			if (f[1] + 1 < f[3])
			{
				if (!(*file = ft_strdup(argv[f[1] + 1])))
					return (-1);
				f[1]++;
			}
		}
		else
			f[2] = ft_push_swap_create_stack(a, &tmp, argv[f[1]]);
		f[1]++;
	}
	if (f[2] > 0)
		f[2] = push_swap_check_stack_a(*a);
	return (f[2]);
}

void	push_swap_sort1(t_stack **a, int p)
{
	t_stack *tmp;
	t_stack *min;
	int		c;

	c = 1;
	while (c == 1)
	{
		tmp = *a;
		while (tmp != NULL && tmp->place != -1)
			tmp = tmp->next;
		min = tmp;
		c = min == NULL ? 0 : 1;
		while (tmp != NULL && c != 0)
		{
			min = tmp->place == -1 && tmp->nb < min->nb ? tmp : min;
			tmp = tmp->next;
		}
		if (min != NULL)
			min->place = p;
		p++;
	}
}

int		push_swap_sort(t_stack **a, int *f, char *file)
{
	push_swap_sort1(a, 1);
	push_swap_create_command(a, f[0], file);

	return (1);
}


int     main(int argc, char **argv)
{
	int     tr;
	t_stack *a;
	int     f[4];
	char    *file;

	file = NULL;
	f[0] = 0;
	f[1] = 1;
	f[2] = 1;
	f[3] = argc;
	if (argc < 2)
		return (0);
	a = NULL;
	tr = push_swap_get_stack(&a, argv, f, &file);
	if (tr > 0)
		tr = push_swap_sort(&a, f, file);
	if (tr < 0)
		write(2, "Error\n", 6);
	if (file != NULL)
		free(file);
	return (0);
}
