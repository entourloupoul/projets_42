/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxadd.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <erli@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:56:03 by erli              #+#    #+#             */
/*   Updated: 2019/01/16 17:50:05 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXADD_H
# define MLXADD_H

# define ISO_COEFF1 500
# define ISO_COEFF2 500
# define PARA_COEFF 500

# include "mlx.h"

typedef	unsigned int	t_colour;

typedef struct			s_pixcoord
{
	int	px;
	int	py;
	int	pz;
}						t_pixcoord;

typedef	struct			s_mapcoord
{
	int mx;
	int my;
	int mz;
}						t_mapcoord;

typedef	struct			s_img
{
	void	*ptr;
	int		bpp;
	int		bypp;
	int		size_line;
	int		nb_line;
	int		endian;
	char	*str;
}						t_img;

typedef	struct			s_mlxwin_ptr
{
	void	*mlx_ptr;
	void	*win_ptr;
}						t_mlxwin_ptr;

t_img					*mlx_img_create(void *mlx_ptr, int width, int height);
void					mlx_pixel_put_img(t_img *img, int x, int y,
							t_colour colour);
void					mlx_line_put(t_mlxwin_ptr *mlxwin, t_pixcoord *q,
							t_pixcoord *b, t_colour (*f)(int));
void					mlx_line_put_img(t_img *img, t_pixcoord *q,
							t_pixcoord *b, t_colour (*f)(int));
t_colour				mlx_str_to_colour(char *str);
t_colour				mlx_colour_blue(int z);
t_colour				mlx_colour_gradiant(int z);
t_pixcoord				*mlx_iso_proj(t_mapcoord *mapcoord);
t_pixcoord				*mlx_para_proj(t_mapcoord *mapcoord);

#endif
