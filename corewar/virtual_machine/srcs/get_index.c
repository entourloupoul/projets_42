/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfinnis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 16:40:31 by dfinnis           #+#    #+#             */
/*   Updated: 2019/02/21 13:11:47 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_index(t_game *game, int seek, int size, short *index)
{
	*index = read_bytes(game, seek % MEM_SIZE, size);
	*index = *index % IDX_MOD;
}

void	index_sum(int index1, int index2, short *total)
{
	int total_4;

	total_4 = index1 + index2;
	*total = total_4 % 65536;
	*total = *total % IDX_MOD;
}

int		index_mod(int index)
{
	index = index % MEM_SIZE;
	if (index < 0)
		index = MEM_SIZE + index;
	return (index);
}

int		move_index(int index, t_arg_type *args, int op_id)
{
	t_op	op_tab;
	int		i;

	op_tab = get_op(op_id - 1);
	i = 0;
	if (op_tab.ocp)
		index++;
	while (i < op_tab.argc)
	{
		if (args[i] == REG_CODE)
			index++;
		else if (args[i] == DIR_CODE && !op_tab.dir_size)
			index += DIR_SIZE;
		else if (args[i] == DIR_CODE && op_tab.dir_size)
			index += DIR_SIZE / 2;
		else if (args[i] == IND_CODE)
			index += IND_SIZE;
		i++;
	}
	return (index % MEM_SIZE);
}

int		check_args(t_game *game, int index, t_arg_type *args, int op_id)
{
	t_op			op_tab;
	unsigned int	size[2];

	op_tab = get_op(op_id - 1);
	if (args[0] == REG_CODE)
		if (!(game->arena[(index + 1) % MEM_SIZE] >= 1
		&& game->arena[(index + 1) % MEM_SIZE] <= REG_NUMBER))
			return (0);
	if (args[1] == REG_CODE)
	{
		get_size(&size[0], args[0], op_tab.dir_size + 1);
		if (!(game->arena[(index + size[0] + 1) % MEM_SIZE] >= 1
		&& game->arena[(index + size[0] + 1) % MEM_SIZE] <= REG_NUMBER))
			return (0);
	}
	if (args[2] == REG_CODE)
	{
		get_size(&size[0], args[0], op_tab.dir_size + 1);
		get_size(&size[1], args[1], op_tab.dir_size + 1);
		if (!(game->arena[(index + size[0] + size[1] + 1) % MEM_SIZE] >= 1
			&& game->arena[(index + size[0] + size[1] + 1) % MEM_SIZE]
			<= REG_NUMBER))
			return (0);
	}
	return (1);
}
