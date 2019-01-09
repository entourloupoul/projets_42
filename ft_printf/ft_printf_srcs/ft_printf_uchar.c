/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:40:34 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:59:11 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_str_char_printf(va_list *ap)
{
	int		c;
	char	*str;

	c = va_arg(*ap, int);
	if (c == 0)
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
	}
	else
	{
		if (!(str = ft_strnew(1)))
			return (NULL);
		str[0] = c;
	}
	return (str);
}

void	ft_free_uchar_printf(char *str, t_flag *parse)
{
	free(str);
	free(parse);
}

int		ft_printf_uchar(va_list *ap, char *flag, t_print **list)
{
	char	*str;
	int		a;
	t_flag	*parse;

	if (!(str = ft_get_str_char_printf(ap)))
		return (-1);
	a = ft_strlen(str) == 0 ? 1 : 0;
	if (!(parse = ft_flag_printf(flag)))
	{
		free(str);
		return (-1);
	}
	if (ft_flag_options_c(&str, parse) < 0)
	{
		free(parse);
		return (-1);
	}
	a = parse->min_width == -1 ? 1 : parse->min_width;
	if (ft_lstprintnew(str, a, list) < 0)
	{
		ft_free_uchar_printf(str, parse);
		return (-1);
	}
	free(parse);
	return (1);
}
