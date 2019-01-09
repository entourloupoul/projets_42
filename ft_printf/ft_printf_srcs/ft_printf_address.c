/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:56:06 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 17:04:34 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_address_2(t_flag *parse, char *str, t_print **list)
{
	if (ft_flag_options_p(&str, parse, 0) < 0)
	{
		free(parse);
		return (-1);
	}
	if (ft_lstprintnew(str, ft_strlen(str), list) < 0)
	{
		free(parse);
		return (-1);
	}
	free(parse);
	return (1);
}

int	ft_printf_address(va_list *ap, char *flag, t_print **list)
{
	char	*str;
	char	*tmp;
	t_flag	*parse;

	if (!(str = ft_ltoa((unsigned long)va_arg(*ap, void *))))
		return (-1);
	tmp = str;
	if (!(str = ft_convert_base("0123456789", "0123456789abcdef", str)))
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	if (!(parse = ft_flag_printf(flag)))
	{
		free(str);
		return (-1);
	}
	if (ft_printf_address_2(parse, str, list) < 0)
	{
		free(str);
		return (-1);
	}
	return (1);
}
