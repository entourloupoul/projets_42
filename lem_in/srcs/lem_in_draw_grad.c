/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_draw_grad.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:21:06 by erli              #+#    #+#             */
/*   Updated: 2019/02/05 17:53:02 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	t_colour	lem_in_colour(int z)
{
	int	mod;

	mod = z % 11;
	if (mod == 0)
		return (mlx_str_to_colour("0x00af00af"));
	else if (mod == 1)
		return (mlx_str_to_colour("0x00e1d7c0"));
	else if (mod == 2)
		return (mlx_str_to_colour("0x00ff8484"));
	else if (mod == 3)
		return (mlx_str_to_colour("0x0000afff"));
	else if (mod == 4)
		return (mlx_str_to_colour("0x00ff5f00"));
	else if (mod == 5)
		return (mlx_str_to_colour("0x00cc0000"));
	else if (mod == 6)
		return (mlx_str_to_colour("0x00ffffff"));
	else if (mod == 7)
		return (mlx_str_to_colour("0x00f2d388"));
	else if (mod == 8)
		return (mlx_str_to_colour("0x0000d3df"));
	else if (mod == 9)
		return (mlx_str_to_colour("0x00f1be13"));
	else
		return (mlx_str_to_colour("0x00ff3b3f"));
}

static	void		lem_in_draw_grad_2(t_lem_in_data *data,
						t_mlxwin_ptr *mlxwin, int *dxy, int *dpxy)
{
	t_pixcoord		pix[2];

	pix[0].px = GRAPH_BORDER;
	pix[0].py = HEIGHT - GRAPH_BORDER + 20;
	pix[0].pz = 6;
	pix[1].px = GRAPH_BORDER;
	pix[1].py = 20;
	pix[1].pz = 6;
	mlx_line_put(mlxwin, pix, pix + 1, &lem_in_colour);
	mlx_string_put(data->mlx_ptr, data->win_ptr, pix[1].px + 20,
		pix[1].py + 20, mlx_str_to_colour("0x00ffffff"), "n_steps");
	pix[0].px = GRAPH_BORDER + data->n_ant * dxy[0] / dpxy[0];
	pix[0].py = HEIGHT - GRAPH_BORDER + 20;
	pix[0].pz = 5;
	pix[1].px = pix[0].px;
	pix[1].py = 20;
	pix[1].pz = 5;
	mlx_line_put(mlxwin, pix, pix + 1, &lem_in_colour);
}

void				lem_in_draw_grad(t_lem_in_data *data)
{
	int				dxy[2];
	int				dpxy[2];
	t_pixcoord		pix[2];
	t_mlxwin_ptr	mlxwin[1];

	dpxy[0] = 1;
	dpxy[1] = 1;
	dxy[0] = (WIDTH - 3 * GRAPH_BORDER * dpxy[0]) / data->n_ant;
	dxy[1] = (HEIGHT - 3 * GRAPH_BORDER * dpxy[1]) / data->max_steps;
	while (dxy[0] == 0)
		dxy[0] = (WIDTH - 3 * GRAPH_BORDER * ++(dpxy[0])) / data->n_ant;
	while (dxy[1] == 0)
		dxy[1] = (HEIGHT - 3 * GRAPH_BORDER * ++(dpxy[1])) / data->n_ant;
	mlxwin->mlx_ptr = data->mlx_ptr;
	mlxwin->win_ptr = data->win_ptr;
	pix[0].px = GRAPH_BORDER - 20;
	pix[0].py = HEIGHT - GRAPH_BORDER;
	pix[0].pz = 6;
	pix[1].px = WIDTH - 20;
	pix[1].py = HEIGHT - GRAPH_BORDER;
	pix[1].pz = 6;
	mlx_string_put(data->mlx_ptr, data->win_ptr, pix[1].px - 50,
		pix[1].py + 7, mlx_str_to_colour("0x00ffffff"), "n_ant");
	mlx_line_put(mlxwin, pix, pix + 1, &lem_in_colour);
	lem_in_draw_grad_2(data, mlxwin, dxy, dpxy);
}
