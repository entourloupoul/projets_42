/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:49:52 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/09 12:10:42 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(*new) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	if (size == 0)
		return(new);
	ft_memset(new, '\0', size);
	return (new);
}
