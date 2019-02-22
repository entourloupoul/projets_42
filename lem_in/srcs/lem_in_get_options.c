/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_get_options.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:35:17 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 16:30:15 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	lem_in_get_options(int argc, char **argv, t_lem_in_data *data)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] != '-')
			return (ft_msg_int(2, "Abort, wrong option.\n", -1));
		else if (argv[i][1] == 'o' && argv[i][2] == '\0')
			data->options = (data->options | 1);
		else if (argv[i][1] == 's' && argv[i][2] == '\0')
			data->options = (data->options | 1 << 1);
		else if (argv[i][1] == 'g' && argv[i][2] == '\0')
			data->options = (data->options | 1 << 2);
		else if (argv[i][1] == 'p' && argv[i][2] == '\0')
			data->options = (data->options | 1 << 3);
		else
			return (ft_msg_int(2, "Abort, wrong option.\n", -1));
		i++;
	}
	return (1);
}
