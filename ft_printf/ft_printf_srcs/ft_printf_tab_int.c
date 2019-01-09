/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tab_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:12:19 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 17:08:17 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_get_str_tab_int(int *tab, t_flag *parse, int cntr)
{
	char	*ret;
	char	*tmp;

	if (parse->precision < 0)
	{
		ft_putstr("Merci de preciser une precision \
				valide pour afficher le tableau");
		return (NULL);
	}
	if (!(ret = (char *)malloc(sizeof(char) * (parse->precision + 1))))
		return (NULL);
	ret = ft_itoa(tab[cntr]);
	cntr++;
	while (cntr < parse->precision)
	{
		tmp = ret;
		ret = ft_strjoin(ret, ft_itoa(tab[cntr]));
		free(tmp);
		cntr++;
	}
	ret[cntr] = '\0';
	return (ret);
}

int		ft_printf_tab_int(va_list *ap, char *flag, t_print **list)
{
	char	*str;
	t_flag	*parse;

	if (!(parse = ft_flag_printf(flag)))
		return (-1);
	if (!(str = ft_get_str_tab_int(va_arg(*ap, int *), parse, 0)))
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
