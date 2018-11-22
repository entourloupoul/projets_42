/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etlagors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:41:44 by etlagors          #+#    #+#             */
/*   Updated: 2018/11/21 11:38:02 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_file(int fd)
{
	char	*buff;
	char	*str;
	char	*temp;
	int		nb_read;

	if (!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (NULL);
	str = ft_strdup("");
	while ((nb_read = read(fd, buff, BUFF_SIZE)) > 0)
	{
		temp = str;
		str = ft_strjoin(str, buff);
		free(temp);
	}
	free(buff);
	temp = str;
	str = ft_strjoin(str, "\n");
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	free(temp);
	return (str);
}
