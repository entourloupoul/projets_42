/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_write_do.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:24:29 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/24 14:56:17 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	push_swap_write_do(char *command, t_ps *all)
{
	write(all->fd, command, ft_strlen(command));
	ft_push_swap_do_command(command, &all->a, &all->b);
}
