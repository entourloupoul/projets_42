/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:48:21 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:50:38 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	ft_get_printf_uint4(va_list *ap, t_flag *parse)
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

char				*ft_get_convert_base_uint4(unsigned long long n)
{
	char	*str;
	char	*ulltoa;

	ulltoa = ft_ulltoa(n);
	str = ft_convert_base("0123456789", "0123456789ABCDEF", ulltoa);
	free(ulltoa);
	return (str);
}

void				ft_free_uint4(char *str, t_flag *parse)
{
	free(str);
	free(parse);
}

int					ft_printf_uint4(va_list *ap, char *flag, t_print **list)
{
	unsigned long long	n;
	char				*str;
	t_flag				*parse;

	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	n = ft_get_printf_uint4(ap, parse);
	if (!(str = ft_get_convert_base_uint4(n)))
	{
		free(parse);
		return (-1);
	}
	if (ft_flag_options_xx(&str, parse, n) < 0)
	{
		free(parse);
		return (-1);
	}
	if (ft_lstprintnew(str, ft_strlen(str), list) < 0)
	{
		ft_free_uint4(str, parse);
		return (-1);
	}
	free(parse);
	return (1);
}
