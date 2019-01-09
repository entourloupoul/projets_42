/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:01:06 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 12:55:40 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	ft_get_printf_int(va_list *ap, t_flag *parse, char *flag)
{
	long long	n;
	int			i;

	i = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == 'j' || flag[i] == 'z')
		{
			n = va_arg(*ap, long long);
			return (n);
		}
		i++;
	}
	if (parse->l == 1)
		n = (long long)va_arg(*ap, long);
	if (parse->l == 2)
		n = va_arg(*ap, long long);
	if (parse->h == 1)
		n = (long long)(short)va_arg(*ap, int);
	if (parse->h == 2)
		n = (long long)(char)va_arg(*ap, int);
	if (parse->h == -1 && parse->l == -1)
		n = (long long)va_arg(*ap, int);
	return (n);
}

int			ft_printf_int(va_list *ap, char *flag, t_print **list)
{
	long long	n;
	char		*str;
	t_flag		*parse;

	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	n = ft_get_printf_int(ap, parse, flag);
	if (!(str = ft_lltoa_no_signe(n)))
	{
		free(parse);
		return (-1);
	}
	if (ft_flag_options_d(&str, parse, n) < 0)
	{
		free(parse);
		return (-1);
	}
	if (ft_lstprintnew(str, ft_strlen(str), list) < 0)
	{
		free(str);
		free(parse);
		return (-1);
	}
	free(parse);
	return (1);
}
