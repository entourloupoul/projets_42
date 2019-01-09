/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lftoa_no_signe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:20:57 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:43:02 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_lftoa_len(long double f)
{
	unsigned long long	l;
	int					len;

	len = 0;
	l = f >= 0 ? (unsigned long long)f : (unsigned long long)(-f);
	if (l == 0)
		return (1);
	while (l > 0)
	{
		len++;
		l = l / 10;
	}
	len = f < 0 ? len + 1 : len;
	return (len);
}

void	ft_fill_lftoa_int(char **str, long double f, int len1)
{
	unsigned long long	l;

	l = f >= 0 ? (unsigned long long)f : (unsigned long long)(-f);
	while (len1 > 1)
	{
		(*str)[len1 - 1] = 48 + l % 10;
		l = l / 10;
		len1--;
	}
	(*str)[0] = 48 + l % 10;
}

int		ft_printf_round(char **str, long double f, int i)
{
	int		a;
	char	*tmp;

	f = f * 10;
	a = (int)f;
	if (a >= 5)
	{
		while (i >= 0 && ((*str)[i] == '9' || (*str)[i] == '.'))
		{
			if ((*str)[i] == '9')
				(*str)[i] = '0';
			i--;
		}
		if (i >= 0)
			(*str)[i] = (*str)[i] + 1;
		else
		{
			tmp = *str;
			*str = ft_strjoin("1", *str);
			free(tmp);
		}
		if (*str == NULL)
			return (-1);
	}
	return (1);
}

int		ft_fill_lftoa_dec(char **str, long double f, int len1, int precision)
{
	unsigned long long	l;
	int					a;
	int					i;

	i = 1;
	a = 0;
	l = f >= 0 ? (unsigned long long)f : (unsigned long long)(-f);
	f = f < 0 ? -(f + (long double)l) : f - (long double)l;
	if (precision > 0)
	{
		(*str)[len1] = '.';
		while (precision > 0)
		{
			f = f * 10;
			a = (int)f;
			(*str)[len1 + i] = 48 + a % 10;
			f = f - (long double)a;
			precision--;
			i++;
		}
		a = ft_printf_round(str, f, len1 + i - 1);
	}
	return (a);
}

char	*ft_printf_lftoa_no_signe(long double f, int precision)
{
	char				*str;
	int					len;
	int					len1;

	len = ft_printf_lftoa_len(f);
	len1 = len;
	precision = precision == -1 ? 6 : precision;
	len = precision > 0 ? len + precision + 1 : len;
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_fill_lftoa_int(&str, f, len1);
	if (ft_fill_lftoa_dec(&str, f, len1, precision) == -1)
		return (NULL);
	return (str);
}
