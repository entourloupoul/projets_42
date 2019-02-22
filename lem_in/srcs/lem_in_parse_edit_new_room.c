/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_parse_edit_new_room.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:59:21 by pmasson           #+#    #+#             */
/*   Updated: 2019/02/11 17:19:34 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	parse_nb_is_int(int nb, char *str, int i, int sgn)
{
	if (nb > 214748364 || (nb == 214748364 && (str[i] > '8'
					|| (str[i] == '8' && sgn == 1))))
		return (-1);
	i += 1;
	if (str[i] >= '0' && str[i] <= '9')
		return (-1);
	return (1);
}

static int	parse_get_coord(char *str, int *coord, int *i, int nb)
{
	int sgn;
	int pow;

	sgn = 1;
	pow = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\r'
			|| str[*i] == '\v' || str[*i] == '\f')
		*i += 1;
	if (str[*i] == '+' || str[*i] == '-')
		sgn = 44 - str[(*i)++];
	if (ft_isdigit(str[*i]) == 0)
		return (-1);
	while (ft_isdigit(str[*i]) == 1)
	{
		if (pow == 10 && parse_nb_is_int(nb, str, *i, sgn) < 0)
			return (-1);
		nb = (10 * nb) + str[*i] - '0';
		pow = (nb != 0 ? pow + 1 : pow);
		*i += 1;
	}
	if (str[*i] != ' ' && str[*i] != '\0')
		return (-1);
	*coord = nb * sgn;
	return (1);
}

int			lem_in_parse_edit_new_room(char *line, t_lem_in_data *data,
		t_parse *new, int len)
{
	int coord;

	if (data->start == 1 && data->end == 1)
		return (ft_msg_int(2, "Abort, no room after ##start or ##end.\n", -1));
	new->state = data->start == 1 ? 1 : 0;
	new->state = data->end == 1 ? 2 : new->state;
	data->start = data->start == 1 ? 2 : data->start;
	data->end = data->end == 1 ? 2 : data->end;
	data->n_room = data->n_room + 1;
	len = 1;
	while (line[len] != ' ')
		len++;
	new->size = len;
	len++;
	if (parse_get_coord(line, &coord, &len, 0) < 0)
		return (-1);
	if (parse_get_coord(line, &coord, &len, 0) < 0)
		return (-1);
	return (0);
}
