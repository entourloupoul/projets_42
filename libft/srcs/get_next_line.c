/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:12:05 by pmasson           #+#    #+#             */
/*   Updated: 2019/09/23 13:21:53 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	gnl_create(t_fd **lst, int fd)
{
	t_fd *new;

	if (!(new = (t_fd *)malloc(sizeof(t_fd) * 1)))
		return (-1);
	new->str = NULL;
	new->fd = fd;
	new->next = *lst;
	*lst = new;
	return (1);
}

static int	gnl_read(t_fd *tmp, int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*ant;
	char	*end;
	int		ret;

	end = NULL;
	ft_bzero(buff, BUFF_SIZE + 1);
	while (end == NULL && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		ant = tmp->str;
		if (tmp->str == NULL)
			tmp->str = ft_strdup(buff);
		else
			tmp->str = ft_strjoin(tmp->str, buff);
		free(ant);
		if (tmp->str == NULL)
			return (-1);
		end = ft_strchr(buff, 10);
		ft_strclr(buff);
	}
	return (ret);
}

static int	gnl_get_line(t_fd *tmp, char **line)
{
	int	i;

	i = 0;
	while (tmp->str[i] != '\0' && tmp->str[i] != '\n')
		i++;
	if (!(*line = ft_strsub(tmp->str, 0, i)))
		return (-1);
	if (tmp->str[i] == '\0')
	{
		ft_strclr(tmp->str);
		return (1);
	}
	ft_strncpy(tmp->str, tmp->str + i + 1, ft_strlen(tmp->str));
	return (1);
}

static void	gnl_free_fd(t_fd **lst, int fd)
{
	t_fd	*tmp;
	t_fd	*ant;

	tmp = *lst;
	ant = tmp;
	while (tmp != NULL && tmp->fd != fd)
	{
		ant = tmp;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return ;
	if (ant == tmp)
		*lst = tmp->next;
	else
		ant->next = tmp->next;
	free(tmp->str);
	free(tmp);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd	*lst = NULL;
	t_fd		*tmp;
	int			ret;

	tmp = lst;
	if (BUFF_SIZE < 1)
		return (-1);
	while (tmp != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp == NULL)
	{
		if (gnl_create(&lst, fd) == -1)
			return (-1);
		tmp = lst;
	}
	if (fd < 0 || line == NULL || (ret = gnl_read(tmp, fd)) < 0)
		return (-1);
	if (ret == 0 && (tmp->str == NULL || tmp->str[0] == '\0'))
	{
		gnl_free_fd(&lst, fd);
		return (0);
	}
	if (gnl_get_line(tmp, line) < 0)
		return (-1);
	return (1);
}
