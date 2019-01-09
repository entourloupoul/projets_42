/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:35:45 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 13:09:31 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncat_printf(char *buff, char *str, int len1, int len2)
{
	int		i;

	i = 0;
	while (i < len2)
	{
		buff[len1 + i] = str[i];
		i++;
	}
	return (buff);
}

void	ft_display_else_printf(int *i, int *j, char *buff, char *str)
{
	buff = ft_strncat_printf(buff, str + *j, *i, 100 - *i);
	write(1, buff, 100);
	*j = *j + 100 - *i;
	ft_bzero(buff, 101);
	*i = 0;
}

int		ft_display_printf(t_print **list, int total, int i, int j)
{
	char	*buff;
	t_print	*tmp;

	if (!(buff = ft_strnew(101)))
		return (-1);
	tmp = *list;
	while (tmp != NULL)
	{
		if (i + tmp->len - j <= 100)
		{
			buff = ft_strncat_printf(buff, tmp->str + j, i, tmp->len - j);
			i = i + tmp->len - j;
			total = total + tmp->len;
			tmp = tmp->next;
			j = 0;
		}
		else
			ft_display_else_printf(&i, &j, buff, tmp->str);
	}
	write(1, buff, i);
	free(buff);
	return (total);
}
