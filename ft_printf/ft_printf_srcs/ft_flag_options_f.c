/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_options_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:56:49 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:59:53 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_options_printf_minwidth_zero_f(char **str, t_flag *parse,\
		long double n, int len)
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
	if (n > 0 && (parse->plus == 1 || parse->space == 1))
		add[0] = parse->plus == 1 ? '+' : ' ';
	tmp = ft_strjoin(add, *str);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (2);
}

int		ft_options_printf_minwidth_minus_f_2(char **str, t_flag *parse,\
		long double n)
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
	if (n > 0 && *str[0] != '+' && parse->plus == 1)
	{
		i = 1;
		*str = ft_strjoin("+", *str);
	}
	if (n > 0 && *str[0] != ' ' && parse->plus == -1 && parse->space == 1)
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

int		ft_options_printf_minwidth_minus_f(char **str, t_flag *parse,\
		long double n, int len)
{
	char	*tmp;
	char	*add;

	if (ft_options_printf_minwidth_minus_f_2(str, parse, n) < 0)
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

int		ft_flag_options_f(char **str, t_flag *parse, long double n)
{
	int		len;
	int		g;

	g = 0;
	if ((len = ft_strlen(*str)) < parse->min_width)
	{
		if (parse->zero == 1 && parse->minus == -1 && g == 0)
			g = ft_options_printf_minwidth_zero_f(str, parse, n, len);
		else
			g = ft_options_printf_minwidth_minus_f(str, parse, n, len);
	}
	if (g == 0)
		g = ft_options_printf_minwidth_minus_f_2(str, parse, n);
	return (g);
}
