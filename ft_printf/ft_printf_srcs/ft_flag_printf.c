/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:42:43 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:57:18 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_incrementation_i(int nb)
{
	int		cntr;

	cntr = 0;
	while (nb != 0)
	{
		nb = nb / 10;
		cntr++;
	}
	return (cntr);
}

void	ft_flag_printf_3(char *flag, t_flag *parse)
{
	int		i;

	i = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == 'l')
		{
			parse->h = -1;
			parse->l = flag[i + 1] == 'l' ? 2 : 1;
			if (flag[i + 1] == 'l')
				i++;
		}
		if (flag[i] == 'h')
		{
			parse->l = -1;
			parse->h = flag[i + 1] == 'h' ? 2 : 1;
			if (flag[i + 1] == 'h')
				i++;
		}
		if (flag[i] == 'L')
			parse->ll = 1;
		i++;
	}
	return ;
}

void	ft_flag_printf_2(char *flag, t_flag *parse)
{
	int		i;
	int		j;

	i = 0;
	while (flag[i] != '\0')
	{
		j = 0;
		if (flag[i] >= '1' && flag[i] <= '9')
		{
			parse->min_width = ft_atoi(flag + i);
			i = i + ft_incrementation_i(parse->min_width);
			j = 1;
		}
		if (flag[i] == '.')
		{
			parse->precision = ft_atoi(&flag[i + 1]);
			i = i + ft_incrementation_i(parse->precision) + 1;
			j = 1;
		}
		if (j == 0)
			i++;
	}
	return ;
}

void	ft_flag_printf_1(char *flag, t_flag *parse)
{
	int		i;

	i = 0;
	while (flag[i] != '\0')
	{
		if (flag[i] == '-')
			parse->minus = 1;
		if (flag[i] == '+')
			parse->plus = 1;
		if (flag[i] == '#')
			parse->hashtag = 1;
		if (flag[i] == ' ')
			parse->space = 1;
		if (flag[i] == '0' && (i == 0 || ((flag[i - 1] < '0' ||\
						flag[i - 1] > '9') && flag[i - 1] != '.')))
			parse->zero = 1;
		i++;
	}
	return ;
}

t_flag	*ft_flag_printf(char *flag)
{
	t_flag	*parse;

	if (!(parse = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	parse->minus = -1;
	parse->plus = -1;
	parse->hashtag = -1;
	parse->space = -1;
	parse->zero = -1;
	parse->min_width = -1;
	parse->precision = -1;
	parse->l = -1;
	parse->ll = -1;
	parse->h = -1;
	ft_flag_printf_1(flag, parse);
	ft_flag_printf_2(flag, parse);
	ft_flag_printf_3(flag, parse);
	return (parse);
}
