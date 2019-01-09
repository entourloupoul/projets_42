/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:46:55 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:46:47 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_get_printf_uint2(va_list *ap, t_flag *parse)
{
	unsigned long long	n;

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

char				*ft_get_convert_base(unsigned long long n)
{
	char	*str;
	char	*ulltoa;

	ulltoa = ft_ulltoa(n);
	str = ft_convert_base("0123456789", "01234567", ulltoa);
	free(ulltoa);
	return (str);
}

int					ft_printf_uint2(va_list *ap, char *flag, t_print **list)
{
	unsigned long long	n;
	char				*str;
	t_flag				*parse;

	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	n = ft_get_printf_uint2(ap, parse);
	if (!(str = ft_get_convert_base(n)))
	{
		free(parse);
		return (-1);
	}
	if (ft_flag_options_o(&str, parse, n) < 0)
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
