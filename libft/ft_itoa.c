/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:25:10 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/05 11:51:55 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_fill_str(char *str, long n1, int len)
{
	str[len - 1] = '\0';
	len = len - 2;
	if (n1 < 0)
	{
		str[0] = '-';
		n1 = -n1;
	}
	if (n1 == 0)
		str[0] = 0;
	while (n1 != 0)
	{
		str[len] = 48 + n1 % 10;
		n1 = n1 / 10;
		len--;
	}
}

static int	ft_len_str(long n1)
{
	int	len;

	len = 1;
	if (n1 < 0)
	{
		len++;
		n1 = -n1;
	}
	if (n1 == 0)
		len++;
	while (n1 != 0)
	{
		n1 = n1 / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*str;
	long	n1;
	int		len;

	n1 = (long)n;
	len = ft_len_str(n1);
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_fill_str(str, n1, len);
	return (str);
}
