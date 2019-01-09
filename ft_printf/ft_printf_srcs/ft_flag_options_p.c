/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_options_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:11:14 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:02:26 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_options_printf_precision_p(char **str, t_flag *parse, int len)
{
	char	*tmp;
	char	*add;

	tmp = *str;
	if (*str[0] == '0' && len == 1 && parse->precision == 0)
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

int		ft_options_printf_minwidth_p(char **str, int min, int trigger, int len)
{
	char	*tmp;
	char	*add;

	if (!(add = ft_strnew(min - len)))
	{
		free(*str);
		return (-1);
	}
	ft_memset(add, ' ', min - len);
	if (trigger == -1)
		tmp = ft_strjoin(*str, add);
	else
		tmp = ft_strjoin(add, *str);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (1);
}

int		ft_options_printf_zero_p(t_flag *parse, char **str)
{
	char	*tmp;
	int		len;
	char	*add;

	len = ft_strlen(*str);
	if (!(add = ft_strnew(parse->min_width - len - 2)))
	{
		free(*str);
		return (-1);
	}
	ft_memset(add, '0', parse->min_width - len - 2);
	tmp = ft_strjoin(add, *str);
	free(*str);
	*str = tmp;
	free(add);
	if (str == NULL)
		return (-1);
	return (1);
}

int		ft_flag_options_p(char **str, t_flag *parse, int g)
{
	int		len;
	char	*tmp;

	if (((len = ft_strlen(*str)) < parse->precision) ||\
			(*str[0] == '0' && len == 1 && parse->precision == 0))
		g = ft_options_printf_precision_p(str, parse, len);
	if (parse->zero == 1 && parse->minus == -1 && g == 0 &&\
			parse->min_width - len - 2 > 0)
		g = ft_options_printf_zero_p(parse, str);
	if (g > -1)
	{
		tmp = *str;
		*str = ft_strjoin("0x", *str);
		free(tmp);
	}
	if (*str != NULL && parse->min_width > 0 &&\
			(len = ft_strlen(*str)) < parse->min_width)
	{
		if (parse->minus == 1)
			g = ft_options_printf_minwidth_p(str, parse->min_width, -1, len);
		else
			g = ft_options_printf_minwidth_p(str, parse->min_width, 1, len);
	}
	return (g);
}
