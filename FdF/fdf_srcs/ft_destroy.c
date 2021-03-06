/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:15:05 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/15 18:14:43 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_destroy(t_param *param)
{
	mlx_destroy_image(param->mlx, param->image->ima);
	exit(0);
}
