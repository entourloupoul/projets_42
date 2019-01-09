/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_options_s.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 09:59:57 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 11:46:05 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_options_printf_minwidth_s(char **str, t_flag *parse, int trigger,\
		int len)
{
	char	*tmp;
	char	*add;

	if (!(add = ft_strnew(parse->min_width - len)))
	{
		free(*str);
		return (-1);
	}
	if (parse->zero == 1 && parse->minus == -1)
		ft_memset(add, '0', parse->min_width - len);
	else
		ft_memset(add, ' ', parse->min_width - len);
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

int		ft_flag_options_s(char **str, t_flag *parse)
{
	int		g;
	int		len;
	char	*tmp;

	g = 1;
	if (parse->precision >= 0 && (len = ft_strlen(*str)) > parse->precision)
	{
		tmp = *str;
		if (!(*str = ft_strsub(*str, 0, parse->precision)))
		{
			free(tmp);
			return (-1);
		}
	}
	if (parse->min_width > 0 && (len = ft_strlen(*str)) < parse->min_width)
	{
		if (parse->minus == 1)
			g = ft_options_printf_minwidth_s(str, parse, -1, len);
		else
			g = ft_options_printf_minwidth_s(str, parse, 1, len);
	}
	return (g);
}
