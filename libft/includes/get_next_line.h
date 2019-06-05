/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:13:01 by pmasson           #+#    #+#             */
/*   Updated: 2019/06/05 11:22:45 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 4

typedef	struct	s_fd
{
	char			*str;
	int				fd;
	struct s_fd		*next;
}				t_fd;
int				get_next_line(const int fd, char **line);
#endif
