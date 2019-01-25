/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_create_stack.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 13:47:58 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/18 14:14:39 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_push_swap_atoi(char *str, int *d, int i, long a)
{
	long	coeff;

	coeff = 1;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i]) == 0 && (i != 0 || (str[i] != '-' &&\
						str[i] != '+'))) || ((str[0] == '-' || str[0] == '+')\
						&& ft_isdigit(str[1]) == 0))
			return (0);
		i++;
	}
	i--;
	while (i >= 0)
	{
		a = str[i] == '-' ? -a : a + coeff * (str[i] - 48);
		a = str[i] == '+' ? a - coeff * (str[i] - 48) : a;
		coeff = coeff * 10;
		if (a > 2147483648 || (a == 2147483648 && str[0] != '-'))
			return (0);
		i--;
	}
	*d = a;
	return (1);
}

t_stack	*ft_push_swap_create_elem(char *str)
{
	t_stack	*new;
	int		d;

	d = 0;
	if (!(new = (t_stack *)malloc(sizeof(t_stack) * 1)))
		return (NULL);
	if (ft_push_swap_atoi(str, &d, 0, 0) == 0)
	{
		free(new);
		return (NULL);
	}
	new->nb = d;
	new->place = -1;
	new->next = NULL;
	return (new);
}

void	ft_push_swap_create_stack_free_tab(char ***tab)
{
	int	i;

	i = 0;
	while ((*tab)[i] != NULL)
	{
		free((*tab)[i]);
		i++;
	}
	free(*tab);
}

int		ft_push_swap_create_stack(t_stack **a, t_stack **tmp, char *str)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(str, ' ')))
		return (-1);
	while (i >= 0 && tab[i] != NULL)
	{
		if ((*tmp) == NULL)
		{
			*tmp = ft_push_swap_create_elem(tab[i]);
			*a = *tmp;
		}
		else
		{
			(*tmp)->next = ft_push_swap_create_elem(tab[i]);
			(*tmp) = (*tmp)->next;
		}
		if ((*tmp) == NULL)
			i = -2;
		i++;
	}
	ft_push_swap_create_stack_free_tab(&tab);
	return (i);
}
