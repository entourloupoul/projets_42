/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:25:10 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/09 18:03:07 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_fill_str(char *str, long n1)
{
	long	a;
	int		i;

	a = 1000000000;
	i = 0;
	if (n1 < 0)
	{
		str[i] = '-';
		i++;
		n1 = -n1;
	}
	while (n1 / a == 0 && a != 0)
		a = a / 10;
	while (a != 0)
	{
		str[i] = n1 / a + 48;
		i++;
		n1 = n1 - (n1 / a) * a;
		a = a / 10;
	}
	str[i] = '\0';
}

int		ft_len_str(long n1)
{
	long	a;
	long	len;

	a = 1000000000;
	len = 1;
	if (n1 < 0)
	{
		len++;
		n1 = -n1;
	}
	if (n1 == 0)
		len++;
	while (n1 / a == 0 && a != 0)
		a = a / 10;
	while (a != 0)
	{
		len++;
		n1 = n1 - (n1 / a) * a;
		a = a / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	n1;

	n1 = (long)n;
	if (!(str = (char *)malloc(sizeof(char) * ft_len_str(n1))))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0' ;
		str[1] = '\0';
		return (str);
	}
	ft_fill_str(str, n1);
	return (str);
}
