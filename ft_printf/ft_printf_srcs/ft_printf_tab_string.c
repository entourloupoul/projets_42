/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tab_string.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:33:01 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:43:45 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_size_printf(char **str, t_flag *parse)
{
	int		size;
	int		cntr;

	cntr = 0;
	size = 0;
	if (parse->precision != -1 && parse->minus != 1)
	{
		while (str[cntr] != NULL)
			cntr++;
		if (cntr < parse->precision)
			size = cntr;
		else
			size = parse->precision;
	}
	else
	{
		while (str[size] != NULL)
			size++;
	}
	return (size);
}

void	ft_free_str_tab_string(char **str, int cntr, t_flag *parse, int trigger)
{
	if (trigger == 1)
	{
		cntr--;
		while (cntr >= 0)
		{
			free(str[cntr]);
			cntr--;
		}
	}
	free(str);
	free(parse);
	return ;
}

int		ft_printf_tab_string(va_list *ap, char *flag, t_print **list)
{
	int		size;
	int		cntr;
	char	**str;
	t_flag	*parse;

	cntr = 0;
	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	if (!(str = ft_strdup_tab_printf(va_arg(*ap, char **), parse, 0)))
	{
		free(parse);
		return (-1);
	}
	size = ft_size_printf(str, parse);
	while (cntr < size)
	{
		if (!(ft_lstprintnew(str[cntr], ft_strlen(str[cntr]), list)))
		{
			ft_free_str_tab_string(str, cntr, parse, 1);
			return (-1);
		}
		cntr++;
	}
	ft_free_str_tab_string(str, cntr, parse, 0);
	return (1);
}
