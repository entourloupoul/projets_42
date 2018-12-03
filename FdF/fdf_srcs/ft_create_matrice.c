/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:22:04 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 17:22:32 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**ft_create_mat(int i)
{
	double	**mat;
	int		j;

	if (!(mat = (double **)malloc(sizeof(double *) * 4)))
		return (NULL);
	while (i < 4)
	{
		if (!(mat[i] = (double *)malloc(sizeof(double) * 4)))
		{
			ft_free_mat(mat, i);
			return (NULL);
		}
		j = 0;
		while (j < 4)
		{
			mat[i][j] = 0;
			j++;
		}
		i++;
	}
	mat[0][0] = 1;
	mat[1][1] = 1;
	mat[2][2] = 1;
	mat[3][3] = 1;
	return (mat);
}

double	**ft_create_mat_trans(char axe, double val)
{
	double	**trans;

	if (!(trans = ft_create_mat(0)))
		return (NULL);
	if (axe == 'x')
		trans[0][3] = val;
	if (axe == 'y')
		trans[1][3] = val;
	if (axe == 'z')
		trans[2][3] = val;
	return (trans);
}

double	**ft_create_mat_rot(char axe, double val)
{
	double	**rot;

	rot = ft_create_mat(0);
	if (axe == 'x' && rot != NULL)
	{
		rot[1][1] = cos(val);
		rot[1][2] = -sin(val);
		rot[2][1] = sin(val);
		rot[2][2] = cos(val);
	}
	if (axe == 'y' && rot != NULL)
	{
		rot[0][0] = cos(val);
		rot[0][2] = sin(val);
		rot[2][0] = -sin(val);
		rot[2][2] = cos(val);
	}
	if (axe == 'z' && rot != NULL)
	{
		rot[0][0] = cos(val);
		rot[0][1] = -sin(val);
		rot[1][0] = sin(val);
		rot[1][1] = cos(val);
	}
	return (rot);
}

double	**ft_create_mat_scale(char axe, double val)
{
	double	**scale;

	if (!(scale = ft_create_mat(0)))
		return (NULL);
	if (axe == 'z')
		scale[2][2] = val;
	if (axe == 'a')
	{
		scale[0][0] = val;
		scale[1][1] = val;
	}
	return (scale);
}

double	**ft_create_matrice(char *rts, char axe, double val)
{
	double	**mat;

	if (ft_strcmp(rts, "trans") == 0)
		mat = ft_create_mat_trans(axe, val);
	if (ft_strcmp(rts, "rot") == 0)
		mat = ft_create_mat_rot(axe, val);
	if (ft_strcmp(rts, "scale") == 0)
		mat = ft_create_mat_scale(axe, val);
	return (mat);
}
