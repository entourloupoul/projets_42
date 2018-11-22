/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_pieces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:43:32 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/21 10:52:09 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_table(int len)
{
	int		nb;
	int		i;
	char	**tab;

	nb = len / 21;
	if (!(tab = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	i = 0;
	while (i < nb)
	{
		if (!(tab[i] = ft_strnew(9)))
		{
			while (i > 0)
			{
				i--;
				free(tab[i]);
			}
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_fill_table(char *buff, char ***pieces, int piece)
{
	int	j;
	int i;
	int a;

	j = 0;
	while (buff[j] != '\0')
	{
		i = 0;
		(*pieces)[piece][0] = piece + 65;
		a = 0;
		while (i < 20)
		{
			if (buff[i + j] == '#')
			{
				(*pieces)[piece][a + 1] = i / 5 + 48;
				(*pieces)[piece][a + 2] = i % 5 + 48;
				a = a + 2;
			}
			i++;
		}
		j = j + 21;
		piece++;
	}
}

void	ft_compress_table(char ***pieces, int i, int b, int c)
{
	int	a;

	while ((*pieces)[i] != NULL)
	{
		b = 51;
		c = 51;
		a = 1;
		while (a < 9)
		{
			if ((*pieces)[i][a] < b && a % 2 == 1)
				b = (*pieces)[i][a];
			if ((*pieces)[i][a] < c && a % 2 == 0)
				c = (*pieces)[i][a];
			a++;
		}
		while (a > 1)
		{
			a--;
			if (b != 48 && a % 2 == 1)
				(*pieces)[i][a] = (*pieces)[i][a] - b + 48;
			if (c != 48 && a % 2 == 0)
				(*pieces)[i][a] = (*pieces)[i][a] - c + 48;
		}
		i++;
	}
}

char	**ft_create_pieces(char *buff)
{
	char	**pieces;

	if (!(pieces = ft_create_table(ft_strlen(buff))))
	{
		free(buff);
		return (NULL);
	}
	ft_fill_table(buff, &pieces, 0);
	ft_compress_table(&pieces, 0, 51, 51);
	free(buff);
	return (pieces);
}
