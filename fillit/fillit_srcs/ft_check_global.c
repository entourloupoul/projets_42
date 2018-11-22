/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_global.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:33:57 by etlagors          #+#    #+#             */
/*   Updated: 2018/11/21 10:49:41 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_check_global(char *str, int i)
{
	int hashtag;
	int a;

	if (ft_strlen(str) % 21 != 0 || ft_strlen(str) > 546)
		return (-1);
	while (str[i] != '\0')
	{
		a = 0;
		hashtag = 0;
		while (a < 20)
		{
			if (a % 5 == 4 && str[i + a] != '\n')
				return (-1);
			if (a % 5 != 4 && str[i + a] != '.' && str[i + a] != '#')
				return (-1);
			if (str[i + a] == '#')
				hashtag++;
			a++;
		}
		if (str[i + a] != '\n' || hashtag != 4)
			return (-1);
		i = i + 21;
	}
	return (1);
}
