/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:52:17 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:41:00 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free_string_printf(char *str, t_flag *parse)
{
	free(str);
	free(parse);
}

int		ft_printf_string(va_list *ap, char *flag, t_print **list)
{
	char	*str;
	t_flag	*parse;

	str = va_arg(*ap, char *);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	if (!(parse = ft_flag_printf(flag)))
	{
		free(str);
		return (-1);
	}
	if (ft_flag_options_s(&str, parse) < 0)
	{
		free(parse);
		return (-1);
	}
	if (ft_lstprintnew(str, ft_strlen(str), list) < 0)
	{
		ft_free_string_printf(str, parse);
		return (-1);
	}
	free(parse);
	return (1);
}
