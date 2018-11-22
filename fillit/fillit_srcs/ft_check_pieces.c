/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pieces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 08:49:14 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/21 11:40:31 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_tab_unique(void)
{
	char	**unique_pieces;
	int		i;

	if (!(unique_pieces = (char **)malloc(sizeof(char *) * 20)))
		return (NULL);
	i = 0;
	while (i < 19)
	{
		if (!(unique_pieces[i] = ft_strnew(9)))
		{
			i--;
			while (i >= 0)
			{
				free(unique_pieces[i]);
				i--;
			}
			free(unique_pieces);
			return (NULL);
		}
		i++;
	}
	unique_pieces[19] = NULL;
	return (unique_pieces);
}

void	ft_create_19(char ***unique_pieces)
{
	(*unique_pieces)[0] = ft_strcpy((*unique_pieces)[0], "00102030");
	(*unique_pieces)[1] = ft_strcpy((*unique_pieces)[1], "00010203");
	(*unique_pieces)[2] = ft_strcpy((*unique_pieces)[2], "00011011");
	(*unique_pieces)[3] = ft_strcpy((*unique_pieces)[3], "00011112");
	(*unique_pieces)[4] = ft_strcpy((*unique_pieces)[4], "01101120");
	(*unique_pieces)[5] = ft_strcpy((*unique_pieces)[5], "01021011");
	(*unique_pieces)[6] = ft_strcpy((*unique_pieces)[6], "00101121");
	(*unique_pieces)[7] = ft_strcpy((*unique_pieces)[7], "00011121");
	(*unique_pieces)[8] = ft_strcpy((*unique_pieces)[8], "02101112");
	(*unique_pieces)[9] = ft_strcpy((*unique_pieces)[9], "00102021");
	(*unique_pieces)[10] = ft_strcpy((*unique_pieces)[10], "00010210");
	(*unique_pieces)[11] = ft_strcpy((*unique_pieces)[11], "00011020");
	(*unique_pieces)[12] = ft_strcpy((*unique_pieces)[12], "00010212");
	(*unique_pieces)[13] = ft_strcpy((*unique_pieces)[13], "01112021");
	(*unique_pieces)[14] = ft_strcpy((*unique_pieces)[14], "00101112");
	(*unique_pieces)[15] = ft_strcpy((*unique_pieces)[15], "00101120");
	(*unique_pieces)[16] = ft_strcpy((*unique_pieces)[16], "00010211");
	(*unique_pieces)[17] = ft_strcpy((*unique_pieces)[17], "01101121");
	(*unique_pieces)[18] = ft_strcpy((*unique_pieces)[18], "01101112");
}

int		ft_piececmp(char *piece, char **unique_pieces)
{
	int npiece;
	int i;

	npiece = 0;
	while (npiece < 19)
	{
		i = 0;
		while (piece[i + 1] == unique_pieces[npiece][i] && i < 8)
			i++;
		if (i == 8)
			return (1);
		npiece++;
	}
	return (-1);
}

void	ft_free_unique(char **unique_pieces)
{
	int i;

	i = 0;
	while (unique_pieces[i] != NULL)
	{
		free(unique_pieces[i]);
		i++;
	}
	free(unique_pieces[i]);
	free(unique_pieces);
}

int		ft_check_pieces(char **pieces)
{
	char	**unique_pieces;
	int		i;

	if (!(unique_pieces = ft_create_tab_unique()))
		return (-1);
	ft_create_19(&unique_pieces);
	i = 0;
	while (pieces[i] != NULL)
	{
		if (ft_piececmp(pieces[i], unique_pieces) == -1)
		{
			ft_free_unique(unique_pieces);
			return (-1);
		}
		i++;
	}
	ft_free_unique(unique_pieces);
	return (1);
}
