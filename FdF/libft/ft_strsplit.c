/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:25:56 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/28 11:48:56 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_count_words(char const *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] == c || (s[i] == '\0' && s[i - 1] != c))
			k++;
	}
	return (k);
}

static void	*ft_strsplit_mallocwords(char const *s, char c, char **new)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			j++;
		}
		if (s[i] == c || (s[i] == '\0' && s[i - 1] != c))
		{
			if (!(new[k] = (char *)malloc(sizeof(char) * (j + 1))))
				return (NULL);
			k++;
		}
	}
	return (new);
}

static void	ft_strsplit_fill(char const *s, char c, char **new)
{
	int i;
	int k;
	int j;

	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			new[k][j] = s[i];
			i++;
			j++;
		}
		if (s[i] == c || (s[i] == '\0' && s[i - 1] != c))
		{
			new[k][j] = '\0';
			k++;
		}
	}
	new[k] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		k;

	if (s == NULL)
		return (NULL);
	k = ft_count_words(s, c);
	if (!(new = (char **)malloc(sizeof(char **) * (k + 1))))
		return (NULL);
	if (!(ft_strsplit_mallocwords(s, c, new)))
		return (NULL);
	if (!(new[k] = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	ft_strsplit_fill(s, c, new);
	return (new);
}
