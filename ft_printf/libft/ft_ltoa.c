/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:51:07 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:52:49 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_fill_str(char *str, long long n1, int len)
{
	str[len - 1] = '\0';
	len = len - 2;
	if (n1 < 0)
	{
		str[0] = '-';
		n1 = -n1;
	}
	while (len > 0)
	{
		str[len] = 48 + n1 % 10;
		n1 = n1 / 10;
		len--;
	}
	if (str[0] != '-')
		str[0] = 48 + n1 % 10;
}

static int	ft_len_str(long long n1)
{
	int	len;

	len = 1;
	if (n1 < 0)
	{
		len++;
		n1 = -n1;
	}
	if (n1 == 0)
	{
		len++;
		return (len);
	}
	while (n1 > 0)
	{
		n1 = n1 / 10;
		len++;
	}
	return (len);
}

char		*ft_ltoa(long n)
{
	char		*str;
	int			len;
	long long	u;

	u = n;
	len = ft_len_str(u);
	if (!(str = ft_strnew(len - 1)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_fill_str(str, u, len);
	return (str);
}
