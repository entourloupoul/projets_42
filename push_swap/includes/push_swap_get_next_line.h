/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_get_next_line.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 09:55:57 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 09:49:02 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_GET_NEXT_LINE_H
# define PUSH_SWAP_GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef	struct	s_fd
{
	char			*str;
	int				fd;
	struct s_fd		*next;
}				t_fd;
int				push_swap_get_next_line(const int fd, char **line);
#endif
