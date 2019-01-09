/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:09:59 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:14:55 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_tab_fn.h"

int		ft_strchr_printf(char c)
{
	int		g;

	g = 0;
	while (g_function[g].c != '\0')
	{
		if (g_function[g].c == c)
			return (g);
		g++;
	}
	if (c != '-' && c != '+' && c != '#' && c != ' ' && (c < '0' || c > '9')\
			&& c != 'l' && c != 'L' && c != 'h' &&\
			c != '.' && c != 'j' && c != 'z')
		return (-2);
	return (-1);
}

int		ft_launch_ft_printf(int g, va_list *ap, char *flag, t_print **list)
{
	if (g_function[g].ft(ap, flag, list) < 0)
	{
		free(flag);
		return (-1);
	}
	free(flag);
	return (1);
}

int		ft_is_flag(const char *format, int i, t_print **list, va_list *ap)
{
	int		j;
	int		g;
	char	*flag;

	j = i;
	g = ft_get_g_printf(format, &i);
	if (!(flag = ft_strsub(format, j + 1, i - j)))
		return (-1);
	if (g == -1)
		return (ft_g_minus_one(flag, format));
	if (g == -2)
	{
		if (ft_printf_percentage(ap, flag, list) < 0)
		{
			free(flag);
			return (-1);
		}
		if (format[i] != '\0')
			i = ft_is_not_flag(format, i + 1, list);
		free(flag);
		return (i);
	}
	if ((g = ft_launch_ft_printf(g, ap, flag, list)) < 0)
		return (-1);
	return (i + 1);
}

int		ft_printf_loop(const char *format, va_list *ap, t_print **list)
{
	int		i;

	i = 0;
	while (format[i] != '\0' && i != -1)
	{
		if (format[i] != '%')
			i = ft_is_not_flag(format, i, list);
		else
			i = ft_is_flag(format, i, list, ap);
	}
	if (i == -1)
		return (-1);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_print	*list;
	int		total;

	total = 0;
	list = NULL;
	if (!format)
		return (-1);
	va_start(ap, format);
	if (ft_printf_loop(format, &ap, &list) < 0)
	{
		ft_freelst_printf(&list);
		va_end(ap);
		return (-1);
	}
	total = ft_display_printf(&list, 0, 0, 0);
	ft_freelst_printf(&list);
	va_end(ap);
	return (total);
}
