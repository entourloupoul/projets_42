/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:19:15 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 17:00:17 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_get_printf_ldouble(va_list *ap, char *format)
{
	long double	n;
	int			i;
	int			l;

	l = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == 'l')
			l = 1;
		if (format[i] == 'L')
			l = 2;
		i++;
	}
	if (l == 0)
		n = (long double)(float)va_arg(*ap, double);
	if (l == 1)
		n = (long double)va_arg(*ap, double);
	if (l == 2)
		n = va_arg(*ap, long double);
	return (n);
}

int			ft_printf_double(va_list *ap, char *flag, t_print **list)
{
	long double	f;
	char		*str;
	t_flag		*parse;

	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	f = ft_get_printf_ldouble(ap, flag);
	if (!(str = ft_printf_lftoa_no_signe(f, parse->precision)))
	{
		free(parse);
		return (-1);
	}
	if (ft_flag_options_f(&str, parse, f) < 0)
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
