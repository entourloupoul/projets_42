/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_fill_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:39:55 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/10 17:26:25 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	void	visu_fill_file_cpynew_cpy(t_file **new,\
		char *line, int len, char *newbuff)
{
	ft_strcpy(newbuff, line);
	(*new)->buff = newbuff;
	(*new)->buff[len] = '\n';
	(*new)->size = len + 1;
}

static	int		visu_fill_file_create_new(char *line, t_file *tmp,\
		t_file **new, int len)
{
	char	*newbuff;

	if (!(*new = (t_file *)malloc(sizeof(t_file) * 1)))
		return (ft_msg_int(2, "Abort, failed malloc file", -2));
	if (!(newbuff = (char *)malloc(sizeof(char) * (B_SIZE + 1))))
	{
		free(*new);
		*new = NULL;
		return (ft_msg_int(2, "Abort, failed malloc buff_file", -2));
	}
	ft_bzero(newbuff, B_SIZE + 1);
	(*new)->next = NULL;
	visu_fill_file_cpynew_cpy(new, line, len, newbuff);
	if (tmp != NULL)
		tmp->next = *new;
	return (1);
}

int				visu_fill_file(char *line, t_file **file)
{
	t_file	*tmp;
	t_file	*new;
	int		len;

	tmp = *file;
	new = NULL;
	while (tmp != NULL && tmp->next != NULL)
		tmp = tmp->next;
	len = ft_strlen(line);
	if (tmp == NULL || (tmp->size + len + 1) > B_SIZE)
	{
		if (visu_fill_file_create_new(line, tmp, &new, len) < 0)
			return (-1);
		if (tmp == NULL)
			*file = new;
	}
	else
	{
		ft_strcpy(tmp->buff + tmp->size, line);
		tmp->buff[tmp->size + len] = '\n';
		tmp->size = tmp->size + len + 1;
	}
	return (1);
}
