/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 10:32:27 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/21 11:37:29 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_pieces(char **pieces)
{
	int i;

	i = 0;
	while (pieces[i] != NULL)
	{
		free(pieces[i]);
		i++;
	}
	free(pieces[i]);
	free(pieces);
}

char	**create_result(int fd)
{
	char	*str;
	char	**pieces;
	char	**result;

	if (!(str = ft_get_file(fd)))
		return (NULL);
	if (ft_check_global(str, 0) == -1)
	{
		free(str);
		return (NULL);
	}
	if (!(pieces = ft_create_pieces(str)))
		return (NULL);
	if (ft_check_pieces(pieces) == -1)
	{
		ft_free_pieces(pieces);
		return (NULL);
	}
	if (!(result = ft_backtrack_fillit(pieces)))
	{
		ft_free_pieces(pieces);
		return (NULL);
	}
	ft_free_pieces(pieces);
	return (result);
}

void	ft_print(char **ret)
{
	int	i;

	i = 0;
	while (ret[i][0] != '1')
	{
		ft_putstr(ret[i]);
		free(ret[i]);
		ft_putchar('\n');
		i++;
	}
	free(ret[i]);
	free(ret);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**ret;

	if (argc != 2)
	{
		write(1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!(ret = create_result(fd)))
	{
		write(1, "error\n", 6);
		return (0);
	}
	ft_print(ret);
	return (0);
}
