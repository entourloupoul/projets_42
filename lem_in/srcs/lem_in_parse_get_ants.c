/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse_get_ants.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:08:00 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 17:12:46 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	lem_in_parse_get_ants(char *line, t_lem_in_data *data)
{
	int i;
	int	wspace;

	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'
			|| line[i] == '\v'))
		i++;
	wspace = i;
	if (line[i] != '+' && ft_isdigit(line[i]) == 0)
		return (ft_msg_int(2, "Abort, wrong input (nb ants)\n", -1));
	if (line[i] == '+')
		i++;
	while (line[i] != '\0' && ft_isdigit(line[i]) == 1)
		i++;
	if (line[i] == '\0' || line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
		lem_in_atoi(line + wspace, &(data->n_ant));
	else
		return (ft_msg_int(2, "Abort1, wrong input (nb ants)\n", -1));
	if (data->n_ant == 0)
		return (ft_msg_int(2, "Abort2, wrong input (nb ants)\n", -1));
	return (1);
}
