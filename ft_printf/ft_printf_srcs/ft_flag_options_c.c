/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_options_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:40:34 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 11:22:18 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_modified(char *str, char *add, int trigger)
{
	char			*ret;
	size_t			len;
	unsigned long	i;

	i = 0;
	len = ft_strlen(add) + 1;
	if (!(ret = ft_strnew(len)))
		return (NULL);
	while (i < len - 1)
	{
		ret[i + trigger] = add[i];
		i++;
	}
	if (trigger == 1)
		ret[0] = str[0];
	else
		ret[len - 1] = str[0];
	return (ret);
}

int		ft_options_printf_minwidth_c(char **str, t_flag *parse, int trigger)
{
	char	*tmp;
	char	*add;

	if (!(add = ft_strnew(parse->min_width - 1)))
	{
		free(*str);
		return (-1);
	}
	if (parse->zero == 1 && parse->minus == -1)
		ft_memset(add, '0', parse->min_width - 1);
	else
		ft_memset(add, ' ', parse->min_width - 1);
	if (trigger == -1)
		tmp = ft_strjoin_modified(*str, add, 1);
	else
		tmp = ft_strjoin_modified(*str, add, 0);
	free(*str);
	free(add);
	if (tmp == NULL)
		return (-1);
	*str = tmp;
	return (1);
}

int		ft_flag_options_c(char **str, t_flag *parse)
{
	int		g;

	g = 1;
	if (parse->min_width > 1)
	{
		if (parse->minus == 1)
			g = ft_options_printf_minwidth_c(str, parse, -1);
		else
			g = ft_options_printf_minwidth_c(str, parse, 1);
	}
	return (g);
}
