/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:04:20 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/08 18:34:16 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned long		i;
	unsigned char		*dst2;
	unsigned char const	*src2;

	i = 0;
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char const *)src;
	while (i < n && src2[i] != (unsigned char)c)
	{
		dst2[i] = src2[i];
		i++;
	}
	if (src2[i] == (unsigned char)c)
	{
		dst2[i] = src2[i];
		return (dst + i + 1);
	}
	return (NULL);
}
