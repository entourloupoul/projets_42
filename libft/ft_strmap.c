/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:03:34 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/08 18:38:13 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned long	len;
	char			*new;

	len = ft_strlen(s);
	i = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new[len] = '\0';
	while (i < len)
	{
		new[i] = f(s[i]);
		i++;
	}
	return (new);
}
