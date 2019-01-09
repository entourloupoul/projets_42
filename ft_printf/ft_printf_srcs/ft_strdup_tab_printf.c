/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_tab_printf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:43:03 by etlagors          #+#    #+#             */
/*   Updated: 2018/12/11 16:51:36 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_size_tab_printf(char **str, t_flag *parse)
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

void	ft_free_tab_printf(int cntr, char **ret)
{
	cntr--;
	while (cntr >= 0)
	{
		free(ret[cntr]);
		cntr--;
	}
	free(ret);
}

char	**ft_strdup_tab_printf(char **str, t_flag *parse, int cntr)
{
	int		size;
	char	**ret;

	if (parse->precision == -1 && parse->minus == -1)
	{
		ft_putstr("Merci de preciser une precision valide \
				soit '-' pour afficher le tableau en entier");
		return (NULL);
	}
	size = ft_size_tab_printf(str, parse);
	if (!(ret = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (cntr < size)
	{
		if (!(ret[cntr] = ft_strdup(str[cntr])))
		{
			ft_free_tab_printf(cntr, ret);
			return (NULL);
		}
		cntr++;
	}
	ret[cntr] = NULL;
	return (ret);
}
