/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:54:39 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:13:16 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_is_not_flag(const char *format, int i, t_print **list)
{
	char	*str;
	int		j;

	j = i;
	while (format[i] && format[i] != '%')
		i++;
	if (!(str = ft_strsub(format, j, i - j)))
		return (-1);
	if (ft_lstprintnew(str, i - j, list) < 0)
	{
		free(str);
		return (-1);
	}
	return (i);
}

int		ft_get_g_printf(const char *format, int *i)
{
	int		g;

	g = -1;
	while (format[*i] != '\0' && g == -1)
	{
		g = ft_strchr_printf(format[*i + 1]);
		*i = *i + 1;
	}
	return (g);
}

int		ft_g_minus_one(char *flag, const char *format)
{
	free(flag);
	return (ft_strlen(format));
}
