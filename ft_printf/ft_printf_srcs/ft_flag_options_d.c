/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_options_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:00:35 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:07:03 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_options_printf_precision_d(char **str, t_flag *parse,\
		int len, long long n)
{
	char	*tmp;
	char	*add;
	int		i;

	i = (n < 0 || (n >= 0 && (parse->plus == 1 || parse->space == 1))) ? 1 : 0;
	if (!(add = ft_strnew(parse->precision - len + i)))
	{
		free(*str);
		return (-1);
	}
	ft_memset(add, '0', parse->precision - len + i);
	if (n < 0)
		add[0] = '-';
	if (n >= 0 && (parse->plus == 1 || parse->space == 1))
		add[0] = parse->plus == 1 ? '+' : ' ';
	tmp = ft_strjoin(add, *str);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (1);
}

int		ft_options_printf_minwidth_zero_d(char **str, t_flag *parse,\
		long long n, int len)
{
	char	*tmp;
	char	*add;

	if (!(add = ft_strnew(parse->min_width - len)))
	{
		free(*str);
		return (-1);
	}
	ft_memset(add, '0', parse->min_width - len);
	if (n < 0)
		add[0] = '-';
	if (n >= 0 && (parse->plus == 1 || parse->space == 1))
		add[0] = parse->plus == 1 ? '+' : ' ';
	tmp = ft_strjoin(add, *str);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (2);
}

int		ft_options_printf_minwidth_minus_d_2(char **str, t_flag *parse,\
		long long n)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *str;
	if (n < 0 && *str[0] != '-')
	{
		i = 1;
		*str = ft_strjoin("-", *str);
	}
	if (n >= 0 && *str[0] != '+' && parse->plus == 1)
	{
		i = 1;
		*str = ft_strjoin("+", *str);
	}
	if (n >= 0 && *str[0] != ' ' && parse->plus == -1 && parse->space == 1)
	{
		i = 1;
		*str = ft_strjoin(" ", *str);
	}
	if (i == 1)
		free(tmp);
	if (*str == NULL)
		return (-1);
	return (1);
}

int		ft_options_printf_minwidth_minus_d(char **str, t_flag *parse,\
		long long n, int len)
{
	char	*tmp;
	char	*add;

	if (ft_options_printf_minwidth_minus_d_2(str, parse, n) < 0)
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

int		ft_flag_options_d(char **str, t_flag *parse, long long n)
{
	int		len;
	int		g;

	g = 0;
	if (parse->precision == 0 && n == 0)
	{
		free(*str);
		if (!(*str = ft_strdup("")))
			return (-1);
	}
	if ((len = ft_strlen(*str)) < parse->precision)
		g = ft_options_printf_precision_d(str, parse, len, n);
	if (g > -1 && (len = ft_strlen(*str)) < parse->min_width)
	{
		if (parse->zero == 1 && parse->minus == -1 && g == 0)
			g = ft_options_printf_minwidth_zero_d(str, parse, n, len);
		else
			g = ft_options_printf_minwidth_minus_d(str, parse, n, len);
	}
	if (g == 0)
		g = ft_options_printf_minwidth_minus_d_2(str, parse, n);
	return (g);
}
