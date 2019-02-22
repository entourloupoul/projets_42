/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_print_total_step.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:03:13 by erli              #+#    #+#             */
/*   Updated: 2019/02/06 16:05:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		lem_in_print_total_step(t_lem_in_data *data, int steps)
{
	ft_putstr_fd("\n==========Total Steps==========\n", 1);
	ft_putstr_fd("Moving ", 1);
	ft_putnbr_fd(data->n_ant, 1);
	ft_putstr_fd(" ants from room ", 1);
	ft_putstr_fd((data->anthill)[data->start], 1);
	ft_putstr_fd("\nto room ", 1);
	ft_putstr_fd((data->anthill)[data->end], 1);
	ft_putstr_fd("\nin \x1B[32m", 1);
	ft_putnbr_fd(steps, 1);
	ft_putstr_fd("\x1B[0m steps.\n", 1);
}
