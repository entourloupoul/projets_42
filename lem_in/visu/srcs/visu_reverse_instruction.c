/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_reverse_instruction.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 15:19:51 by erli              #+#    #+#             */
/*   Updated: 2019/02/10 17:29:53 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static	int		visu_match_ant(char *old, char *ant, int i)
{
	int j;

	i++;
	j = 0;
	while (old[i] == ant[j] && ant[j] != '\0')
	{
		i++;
		j++;
	}
	if (ant[j] == '\0' && old[i] == '-')
		return (1);
	return (0);
}

static	void	visu_cpy(char *line, char *orig, int *j, int *found)
{
	int i;

	i = 0;
	line[*j] = '-';
	*j += 1;
	while (orig[i] != '\0')
	{
		line[*j] = orig[i];
		i++;
		*j += 1;
	}
	*found = 1;
}

static	void	visu_skip(char *old, char *line, int *i, int *j)
{
	while (old[*i] != ' ' && old[*i] != '\0')
	{
		line[*j] = old[*i];
		*i += 1;
		*j += 1;
	}
	if (old[*i] == ' ')
	{
		line[*j] = old[*i];
		*i += 1;
		*j += 1;
	}
}

static	int		visu_transform(char *old, char *line, int ant_id, char *orig)
{
	char	*ant;
	int		found;
	int		i;
	int		j;

	if (!(ant = ft_itoa(ant_id)))
		return (-2);
	i = 0;
	found = 0;
	j = 0;
	while (old[i] != '\0')
	{
		if (old[i] == 'L' && found == 0 && visu_match_ant(old, ant, i) == 1)
		{
			while (old[i] != '-')
				line[j++] = old[i++];
			while (old[i] != ' ' && old[i] != '\0')
				i++;
			visu_cpy(line, orig, &j, &found);
		}
		visu_skip(old, line, &i, &j);
	}
	line[j] = '\0';
	free(ant);
	return (1);
}

int				visu_reverse_instruction(t_visu_data *data, int ant_id,
					int orig, int dest)
{
	int		cursor;
	char	*old_line;
	char	*line;
	int		len;
	int		diff;

	if (data->cursor == -1)
		cursor = 0;
	else if (VI_PLAY_FORWARD(data->play_param))
		cursor = data->cursor + 1;
	else
		cursor = data->cursor;
	old_line = data->history[cursor];
	len = ft_strlen(old_line);
	diff = ft_strlen(data->anthill[orig].name)
		- ft_strlen(data->anthill[dest].name);
	if (!(line = (char *)malloc(sizeof(char) * (len + diff + 1)))
		|| visu_transform(old_line, line, ant_id, data->anthill[orig].name) < 0)
		return (ft_msg_int(2, "Failed malloc\n", -2));
	free(old_line);
	data->history[cursor] = line;
	return (0);
}
