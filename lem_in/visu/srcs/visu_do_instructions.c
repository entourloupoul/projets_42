/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_do_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:52:21 by erli              #+#    #+#             */
/*   Updated: 2019/02/08 18:47:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_get_ant_id(t_visu_data *data, char *line, int *ant_id,
					int *i)
{
	int nb;

	nb = 0;
	while (ft_isdigit(line[*i]) == 1)
	{
		nb = 10 * nb + line[*i] - '0';
		if (nb > data->n_ant)
			return (ft_msg_int(2, "Invalid ant id.\n", -1));
		*i += 1;
	}
	if (line[*i] != '-')
		return (ft_msg_int(2, "Not an instruction.\n", -1));
	*i += 1;
	*ant_id = nb;
	return (0);
}

static	void	visu_remove_ant(t_ant **ants, t_ant **arrived_ant)
{
	t_ant	*previous;

	if (*ants == 0)
		return ;
	if ((*ants)->id == (*arrived_ant)->id)
		*ants = (*arrived_ant)->next;
	else
	{
		previous = *ants;
		while (previous->next != 0 && previous->next->id != (*arrived_ant)->id)
			previous = previous->next;
		previous->next = (*arrived_ant)->next;
	}
	previous = *arrived_ant;
	*arrived_ant = (*arrived_ant)->next;
	free(previous);
}

static	void	visu_end_turn(t_visu_data *data)
{
	t_ant *ant;

	ant = data->ants;
	while (ant != 0)
	{
		if ((ant->location == data->end && VI_PLAY_FORWARD(data->play_param)))
			visu_remove_ant(&(data->ants), &ant);
		else if (ant->location == data->start
			&& VI_PLAY_BACKWARD(data->play_param))
		{
			if (data->pioneers[ant->id - 1] != 0)
			{
				data->current_pheromon -= 1;
				data->pioneers[ant->id - 1] = 0;
			}
			visu_remove_ant(&(data->ants), &ant);
		}
		else
		{
			ant->moved = 0;
			ant = ant->next;
		}
	}
}

int				visu_do_instructions(t_visu_data *data, char *line)
{
	int i;
	int	i_start;
	int	ant_id;

	i = 1;
	while (line[i] != '\0')
	{
		if (visu_get_ant_id(data, line, &ant_id, &i) < 0)
			return (-1);
		i_start = i;
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		if (visu_manage_ants(data, line + i_start, ant_id, i - i_start) < 0)
			return (-1);
		if (line[i] == ' ')
			i++;
		if (line[i] == 'L')
			i++;
		else if (line[i] != '\0')
			return (ft_msg_int(2, "Invalid instruction\n", -1));
	}
	visu_end_turn(data);
	visu_draw_anthill(data);
	return (1);
}
