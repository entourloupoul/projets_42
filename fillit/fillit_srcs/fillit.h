/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:45:54 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/21 11:19:54 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 1
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

char	**ft_backtrack_fillit(char **pieces);
char	**ft_create_pieces(char *buff);
int		ft_check_global(char *str, int i);
char	*ft_get_file(int fd);
int		ft_check_pieces(char **pieces);
int		ft_carre(int size);
void	ft_free_tab(char **tab, int i);

#endif
