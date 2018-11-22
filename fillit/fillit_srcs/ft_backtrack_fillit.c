/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtrack_fillit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 09:26:03 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/21 11:39:36 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_square(int k)
{
	char	**new;
	int		i;

	if (!(new = (char **)malloc(sizeof(char *) * (k + 1))))
		return (NULL);
	i = 0;
	while (i < k)
	{
		if (!(new[i] = ft_strnew(k + 1)))
		{
			ft_free_tab(new, i);
			return (NULL);
		}
		new[i] = ft_memset(new[i], 46, k);
		i++;
	}
	if (!(new[i] = ft_strnew(k + 1)))
	{
		ft_free_tab(new, i);
		return (NULL);
	}
	new[i] = ft_memset(new[i], 49, k);
	return (new);
}

int		ft_place_piece(char ***square, char *piece, int ligne, int colonne)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if ((*square)[piece[1 + i] - 48 + ligne]\
				[piece[2 + i] - 48 + colonne] != '.')
		{
			i = i - 2;
			while (i >= 0)
			{
				(*square)[piece[1 + i] - 48 + ligne]\
					[piece[2 + i] - 48 + colonne] = 46;
				i = i - 2;
			}
			return (0);
		}
		(*square)[piece[1 + i] - 48 + ligne]\
			[piece[2 + i] - 48 + colonne] = piece[0];
		i = i + 2;
	}
	return (1);
}

void	ft_clear_piece(char ***square, char *piece, int ligne, int colonne)
{
	int i;

	i = 0;
	while (i < 8)
	{
		(*square)[piece[1 + i] - 48 + ligne][piece[2 + i] - 48 + colonne] = 46;
		i = i + 2;
	}
}

int		ft_backtrack(char ***square, char **pieces, int piece, int colonne)
{
	int	ligne;

	ligne = 0;
	while ((*square)[ligne][colonne] != 49)
	{
		if (ft_place_piece(square, pieces[piece], ligne, colonne) == 1)
		{
			if (pieces[++piece] == NULL)
				return (1);
			if (ft_backtrack(square, pieces, piece, 0) == 1)
				return (1);
			ft_clear_piece(square, pieces[--piece], ligne, colonne);
		}
		if ((*square)[ligne][colonne] == '\0')
		{
			colonne = 0;
			ligne++;
		}
		else
			colonne++;
	}
	return (0);
}

char	**ft_backtrack_fillit(char **pieces)
{
	char	**square;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (pieces[i] != NULL)
		i++;
	k = ft_carre(i);
	if (!(square = ft_square(k)))
		return (NULL);
	while (ft_backtrack(&square, pieces, 0, 0) != 1)
	{
		j = 0;
		while (j <= k)
		{
			free(square[j]);
			j++;
		}
		free(square);
		k++;
		if (!(square = ft_square(k)))
			return (NULL);
	}
	return (square);
}
