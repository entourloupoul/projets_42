/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmadeof.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:50:06 by pmasson           #+#    #+#             */
/*   Updated: 2019/06/18 16:00:26 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strmadeof(char *str, char *src)
{
	int	i;

	i = 0;
	if (str == NULL || src == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (ft_strchr(src, (int)str[i]) == NULL)
			return (-1);
		i++;
	}
	return (0);
}
