/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_inf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:55:21 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:06:39 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_putstr_inf(t_param *param)
{
	mlx_string_put(param->mlx, param->win, 20, 50, 0xFFFFFF,\
			"change projection : p");
	mlx_string_put(param->mlx, param->win, 20, 70, 0xFFFFFF,\
			"rotation x        : s/f");
	mlx_string_put(param->mlx, param->win, 20, 90, 0xFFFFFF,\
			"rotation y        : e/d");
	mlx_string_put(param->mlx, param->win, 20, 110, 0xFFFFFF,\
			"rotation z        : w/r");
	mlx_string_put(param->mlx, param->win, 20, 130, 0xFFFFFF,\
			"translation x     : right/left arrow");
	mlx_string_put(param->mlx, param->win, 20, 150, 0xFFFFFF,\
			"translation y     : up/down arrow");
	mlx_string_put(param->mlx, param->win, 20, 170, 0xFFFFFF,\
			"scale altitude    : q/a");
	mlx_string_put(param->mlx, param->win, 20, 190, 0xFFFFFF,\
			"scale map         : z/x");
	return (0);
}
