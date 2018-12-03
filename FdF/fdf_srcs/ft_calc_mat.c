/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:08:38 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:16:25 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**ft_calc_mat2(double **mat, double **mat2)
{
	double	**ret;
	int		i;
	int		j;
	int		k;

	if (!(ret = (double **)malloc(sizeof(double*) * 4)))
		return (NULL);
	j = -1;
	while (j++ < 3)
	{
		if (!(ret[j] = (double *)malloc(sizeof(double) * 4)))
		{
			ft_free_mat(ret, j);
			return (NULL);
		}
		i = -1;
		while (i++ < 3)
		{
			ret[j][i] = 0;
			k = -1;
			while (k++ < 3)
				ret[j][i] = ret[j][i] + mat[j][k] * mat2[k][i];
		}
	}
	return (ret);
}

double	*ft_calc_mat(t_line *tmp, int i, double **mat, double *ret)
{
	int		j;

	j = 0;
	while (j < 4)
	{
		ret[j] = tmp->x[i] * mat[j][0] + tmp->y[i] * mat[j][1]\
				+ tmp->alt[i] * mat[j][2] + 1 * mat[j][3];
		j++;
	}
	return (ret);
}

double	*ft_calc_coord_iso(t_line *tmp, int i, t_mat *mat, double *ret)
{
	int		j;
	double	**mat1;
	double	coef1;

	coef1 = 0.7;
	j = 0;
	mat1 = ft_calc_mat2(mat->mat_sc, mat->mat_tr_init);
	mat1 = ft_calc_mat2(mat->mat_rot, mat1);
	while (j < 4)
	{
		ret[j] = tmp->x[i] * mat1[j][0] + tmp->y[i] * mat1[j][1] + tmp->alt[i]\
				* mat1[j][2] + 1 * mat1[j][3];
		j++;
	}
	ret[0] = (int)round(ret[0] * coef1 - 0.7 * ret[1]);
	ret[1] = (int)round(-ret[2] + ret[0] * coef1 / 2 + 0.7 / 2 * ret[1]);
	j = 0;
	while (j < 4)
	{
		ret[j] = (int)(ret[0] * mat->mat_tr[j][0] + ret[1] * mat->mat_tr[j][1]\
				+ ret[2] * mat->mat_tr[j][2] + 1 * mat->mat_tr[j][3]);
		j++;
	}
	return (ret);
}

t_mat	*ft_calc_mat_proj(t_mat *mat)
{
	double **mat1;
	double **mat2;

	mat1 = ft_calc_mat2(mat->mat_sc, mat->mat_tr_init);
	mat2 = ft_calc_mat2(mat->mat_rot, mat1);
	mat->mat_proj = ft_calc_mat2(mat->mat_tr, mat2);
	ft_free_mat(mat1, 4);
	ft_free_mat(mat2, 4);
	return (mat);
}
