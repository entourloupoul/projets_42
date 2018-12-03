/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_first_proj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:40:26 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:28:25 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	**ft_scale_first_proj(t_line *line)
{
	t_line	*tmp;
	int		ligne;
	int		colonne;
	double	coeff;
	double	**mat;

	tmp = line;
	while (tmp->next != NULL)
		tmp = tmp->next;
	ligne = tmp->y[0];
	colonne = tmp->colonne;
	while (sqrt(colonne * colonne + ligne * ligne) < 1100)
	{
		colonne++;
		ligne++;
	}
	ligne = (ligne - 1) / tmp->y[0];
	colonne = (colonne - 1) / tmp->colonne;
	coeff = colonne <= ligne ? colonne : ligne;
	mat = ft_create_matrice("scale", 'a', coeff);
	return (mat);
}

double	**ft_trans_init(t_line *line)
{
	t_line	*tmp;
	double	**mat;
	double	**mat1;
	double	**mat3;

	tmp = line;
	while (tmp->next != NULL && tmp != NULL)
		tmp = tmp->next;
	if (!(mat = ft_create_matrice("trans", 'x', -(tmp->colonne / 2))))
		return (NULL);
	if (!(mat1 = ft_create_matrice("trans", 'y', -(tmp->y[0] / 2))))
	{
		ft_free_mat(mat, 4);
		return (NULL);
	}
	mat3 = ft_calc_mat2(mat, mat1);
	ft_free_mat(mat, 4);
	ft_free_mat(mat1, 4);
	return (mat3);
}

double	**ft_rot_first_proj(void)
{
	double **mat;
	double **mat1;
	double **mat3;

	if (!(mat = ft_create_matrice("rot", 'z', 0.4)))
		return (NULL);
	if (!(mat1 = ft_create_matrice("rot", 'x', 0.4)))
	{
		ft_free_mat(mat, 4);
		return (NULL);
	}
	mat3 = ft_calc_mat2(mat, mat1);
	ft_free_mat(mat, 4);
	ft_free_mat(mat1, 4);
	return (mat3);
}

double	**ft_trans_first_proj(void)
{
	double	**mat;
	double	**mat1;
	double	**mat3;

	if (!(mat = ft_create_matrice("trans", 'x', 1000)))
		return (NULL);
	if (!(mat1 = ft_create_matrice("trans", 'y', 650)))
	{
		ft_free_mat(mat, 4);
		return (NULL);
	}
	mat3 = ft_calc_mat2(mat, mat1);
	ft_free_mat(mat, 4);
	ft_free_mat(mat1, 4);
	return (mat3);
}

t_mat	*ft_mat_first_proj(t_line *line)
{
	t_mat	*mat;

	if (!(mat = (t_mat *)malloc(sizeof(t_mat))))
		return (NULL);
	if (!(mat->mat_tr_init = ft_trans_init(line)))
	{
		free(mat);
		return (NULL);
	}
	mat->mat_tr = ft_trans_first_proj();
	mat->mat_rot = ft_rot_first_proj();
	mat->mat_sc = ft_scale_first_proj(line);
	if (!mat->mat_tr || !mat->mat_rot || !mat->mat_sc)
		return (NULL);
	mat = ft_calc_mat_proj(mat);
	return (mat);
}
