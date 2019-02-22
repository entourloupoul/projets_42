/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_parse_edit_new_room.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:37:44 by erli              #+#    #+#             */
/*   Updated: 2019/02/11 17:21:52 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_nb_is_int(int nb, char *str, int i, int sgn)
{
	if (nb > 214748364 || (nb == 214748364 && (str[i] > '8'
					|| (str[i] == '8' && sgn == 1))))
		return (ft_msg_int(2, "Invalid coordinates\n", -1));
	i += 1;
	if (str[i] >= '0' && str[i] <= '9')
		return (ft_msg_int(2, "Invalid coordinates\n", -1));
	return (1);
}

static	int		visu_get_coord(char *str, int *coord, int *i, int nb)
{
	int	sgn;
	int	pow;

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
		if (pow == 10 && visu_nb_is_int(nb, str, *i, sgn) < 0)
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

int				visu_parse_edit_new_room(char *line, t_visu_data *data,
		t_parse *new, int len)
{
	int	coord;

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
	if (!VI_OPT_COORD(data->options))
	{
		if (visu_get_coord(line, &coord, &len, 0) < 0)
			return (-1);
		new->x = coord;
		if (visu_get_coord(line, &coord, &len, 0) < 0)
			return (-1);
		new->y = coord;
	}
	return (0);
}
