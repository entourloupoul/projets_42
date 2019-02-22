/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_str_to_colour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:18:40 by erli              #+#    #+#             */
/*   Updated: 2018/12/01 18:58:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxadd.h"
#include "libft.h"

t_colour	mlx_str_to_colour(char *data)
{
	t_colour	colour;
	int			i;
	int			hex;
	int			len;

	colour = 0;
	i = 4;
	len = ft_strlen(data);
	hex = 0;
	if ((len < 10) || (len > 10 && data[len] != '\n'))
		return (0);
	if (ft_strncmp(data, "0x00", 4) == 0)
	{
		while (i < 10 && hex >= 0)
		{
			hex = ft_char_at_pos(data[i], "0123456789abcdef");
			colour = colour * 16 + hex;
			i++;
		}
		if (!(i == 10 && hex >= 0))
			return (0);
	}
	return (colour);
}
