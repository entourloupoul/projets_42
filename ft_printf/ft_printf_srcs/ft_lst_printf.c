/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 08:59:44 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 12:45:20 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_lstprintnew(char *str, int len, t_print **list)
{
	t_print *new;
	t_print *tmp;

	tmp = *list;
	if (!(new = (t_print *)malloc(sizeof(t_print))))
		return (-1);
	new->str = str;
	new->len = len;
	new->next = NULL;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

void	ft_freelst_printf(t_print **list)
{
	t_print	*tmp;
	t_print	*atc;

	tmp = *list;
	if (tmp == NULL)
		return ;
	while (tmp != NULL)
	{
		if (tmp->str != NULL)
			free(tmp->str);
		atc = tmp;
		tmp = tmp->next;
		free(atc);
	}
}
