/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_options_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:46:41 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:12:25 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_options_printf_precision_u(char **str, t_flag *parse,\
		int len, unsigned long long n)
{
	char	*tmp;
	char	*add;

	tmp = *str;
	if (n == 0 && parse->precision == 0)
		tmp = ft_strdup("");
	if (len < parse->precision)
	{
		if (!(add = ft_strnew(parse->precision - len)))
		{
			free(*str);
			return (-1);
		}
		ft_memset(add, '0', parse->precision - len);
		tmp = ft_strjoin(add, *str);
		free(*str);
		free(add);
	}
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (1);
}

int		ft_options_printf_minwidth_zero_u(char **str, t_flag *parse, int len)
{
	char	*tmp;
	char	*add;

	if (!(add = ft_strnew(parse->min_width - len)))
	{
		free(*str);
		return (-1);
	}
	ft_memset(add, '0', parse->min_width - len);
	tmp = ft_strjoin(add, *str);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (2);
}

int		ft_options_printf_minwidth_minus_u_2(char **str, t_flag *parse,\
		unsigned long long n)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *str;
	if (parse->hashtag == 1 && *str[0] != '0' && n != 0)
	{
		i = 1;
		*str = ft_strjoin("0", *str);
	}
	if (i == 1)
		free(tmp);
	if (*str == NULL)
		return (-1);
	return (1);
}

int		ft_options_printf_minwidth_minus_u(char **str, t_flag *parse,\
		int len, unsigned long long n)
{
	char	*tmp;
	char	*add;

	if (ft_options_printf_minwidth_minus_u_2(str, parse, n) < 0)
	{
		free(*str);
		return (-1);
	}
	len = ft_strlen(*str);
	if (!(add = ft_strnew(parse->min_width - len)))
	{
		free(*str);
		return (-1);
	}
	ft_memset(add, ' ', parse->min_width - len);
	if (parse->minus < 1)
		tmp = ft_strjoin(add, *str);
	else
		tmp = ft_strjoin(*str, add);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (2);
}

int		ft_flag_options_u(char **str, t_flag *parse, unsigned long long n)
{
	int		len;
	int		g;
	char	*tmp;

	g = 0;
	len = ft_strlen(*str);
	if ((n == 0 && parse->precision == 0) || (len < parse->precision))
		g = ft_options_printf_precision_u(str, parse, len, n);
	if (g > -1 && (len = ft_strlen(*str)) < parse->min_width)
	{
		if (parse->zero == 1 && parse->minus == -1 && g == 0 &&\
				parse->precision == -1)
			g = ft_options_printf_minwidth_zero_u(str, parse, len);
		else
			g = ft_options_printf_minwidth_minus_u(str, parse, len, n);
	}
	if (g < 2 && g != -1 && parse->hashtag == 1 && n != 0)
	{
		tmp = *str;
		*str = ft_strjoin("0", *str);
		free(tmp);
	}
	if (*str == NULL)
		return (-1);
	return (g);
}
