/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:40:18 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:10:46 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_get_printf_uint1(va_list *ap, t_flag *parse, char *flag)
{
	unsigned long long	n;
	int					i;

	i = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == 'j' || flag[i] == 'U')
		{
			n = va_arg(*ap, long long);
			return (n);
		}
		i++;
	}
	if (parse->l == 1)
		n = (unsigned long long)va_arg(*ap, unsigned long);
	if (parse->l == 2)
		n = va_arg(*ap, unsigned long long);
	if (parse->h == 1)
		n = (unsigned long long)(unsigned short)va_arg(*ap, unsigned int);
	if (parse->h == 2)
		n = (unsigned long long)(unsigned char)va_arg(*ap, unsigned int);
	if (parse->h == -1 && parse->l == -1)
		n = (unsigned long long)va_arg(*ap, unsigned int);
	return (n);
}

int					ft_printf_uint1(va_list *ap, char *flag, t_print **list)
{
	unsigned long long	n;
	char				*str;
	t_flag				*parse;

	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	n = ft_get_printf_uint1(ap, parse, flag);
	if (!(str = ft_ulltoa(n)))
	{
		free(parse);
		return (-1);
	}
	if (ft_flag_options_u(&str, parse, n) < 0)
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
