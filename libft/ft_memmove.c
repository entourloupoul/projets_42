/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:48:21 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/09 10:01:26 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_place_mem(unsigned char *dst2, unsigned const char *src2)
{
	return (dst2 - src2);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned long		i;
	unsigned char		*dst2;
	unsigned char const	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char const *)src;
	if (n == 0)
		return (dst);
	if (ft_place_mem(dst, src) <= 0)
	{
		i = 0;
		while (++i < n)
			dst2[i - 1] = src2[i - 1];
	}
	else
	{
		i = n;
		while (i > 0)
		{
			dst2[i - 1] = src2[i - 1];
			i--;
		}
	}
	return (dst);
}
