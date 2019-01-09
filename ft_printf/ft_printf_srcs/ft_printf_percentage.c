/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:40:34 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:40:23 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_printf_address(char *flag, char **str, va_list *ap)
{
	int		i;

	(void)ap;
	i = 0;
	while (flag[i])
		i++;
	if (!(*str = ft_strnew(1)))
		return (-1);
	if (i == 0)
		return (1);
	(*str)[0] = flag[i - 1];
	return (2);
}

void	ft_free_address_printf(char *str, t_flag *parse)
{
	free(str);
	free(parse);
}

int		ft_printf_percentage(va_list *ap, char *flag, t_print **list)
{
	char	*str;
	t_flag	*parse;
	int		a;

	str = NULL;
	a = ft_get_printf_address(flag, &str, ap);
	if (a == 1 || a == -1)
		return (a);
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
	if (ft_lstprintnew(str, ft_strlen(str), list) < 0)
	{
		ft_free_address_printf(str, parse);
		return (-1);
	}
	free(parse);
	return (1);
}
