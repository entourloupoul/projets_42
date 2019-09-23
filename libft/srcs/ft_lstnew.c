/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 13:36:47 by pmasson           #+#    #+#             */
/*   Updated: 2019/09/23 13:25:04 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	void	*content1;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(content1 = (void *)malloc(sizeof(char) * content_size)))
	{
		free(new);
		return (NULL);
	}
	if (content == NULL)
	{
		free(content1);
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
		return (new);
	}
	new->content = ft_memcpy(content1, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
