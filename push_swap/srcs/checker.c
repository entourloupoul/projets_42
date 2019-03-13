/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:59:36 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/30 08:46:40 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push_swap_checker_chose(t_stack **a, int *f, char *file)
{
	int	fd;

	fd = 0;
	if (f[2] == 1)
	{
		if ((fd = open(file, O_RDONLY)) < 0)
			return (-1);
	}
	if (f[0] == 1)
		return (push_swap_checker_visual(a, f[1], fd));
	else
		return (push_swap_checker_normal(a, fd));
}

int		push_swap_get_stack(t_stack **a, char **argv, int *f, char **file)
{
	t_stack	*tmp;

	tmp = *a;
	while (f[3] < f[5] && f[4] > 0)
	{
		if (f[3] == 1 && ft_strcmp(argv[f[3]], "-v") == 0)
			f[0] = 1;
		else if (f[3] <= 2 && ft_strcmp(argv[f[3]], "-c") == 0)
			f[1] = 1;
		else if (f[3] <= 3 && ft_strcmp(argv[f[3]], "-o") == 0)
		{
			f[2] = 1;
			if (f[3] + 1 < f[5])
			{
				if (!(*file = ft_strdup(argv[f[3] + 1])))
					return (-1);
				f[3]++;
			}
		}
		else
			f[4] = ft_push_swap_create_stack(a, &tmp, argv[f[3]]);
		f[3]++;
	}
	return (f[4]);
}

int		main(int argc, char **argv)
{
	int		tr;
	t_stack	*a;
	int		f[6];
	char	*file;

	file = NULL;
	f[0] = 0;
	f[1] = 0;
	f[2] = 0;
	f[3] = 1;
	f[4] = 1;
	f[5] = argc;
	if (argc < 2)
		return (0);
	a = NULL;
	tr = push_swap_get_stack(&a, argv, f, &file);
	if (tr > 0)
		tr = push_swap_checker_chose(&a, f, file);
	if (tr < 0)
		write(2, "Error\n", 6);
	if (file != NULL)
		free(file);
	return (0);
}
