/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:14:16 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/08 09:27:36 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;
	unsigned long	len;
	int				pos;
	char			*s1;

	c1 = (unsigned char)c;
	len = ft_strlen(s);
	s1 = (char *)s;
	i = len;
	pos = -1;
	while (i >= 0 && pos == -1)
	{
		if (s[i] == c1)
			pos = i;
		i--;
	}
	if (pos == -1)
		return (NULL);
	return (s1 + pos);
}
