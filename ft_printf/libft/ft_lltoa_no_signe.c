/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_no_signe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:51:07 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/07 18:02:11 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static void	ft_fill_str_ll(char *str, unsigned long long n1, int len)
{
	str[len - 1] = '\0';
	len = len - 2;
	while (len >= 0)
	{
		str[len] = 48 + n1 % 10;
		n1 = n1 / 10;
		len--;
	}
}

static int	ft_len_str_ll(unsigned long long n1)
{
	int	len;

	len = 1;
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

char		*ft_lltoa_no_signe(long long n)
{
	char				*str;
	int					len;
	unsigned long long	u;

	if (n < 0)
		u = -n;
	else
		u = n;
	len = ft_len_str_ll(u);
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	ft_fill_str_ll(str, u, len);
	return (str);
}
