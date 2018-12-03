/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 09:57:03 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/30 18:11:11 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef	struct	s_coord
{
	int	*a1;
	int	*a2;
}				t_coord;
typedef	struct	s_line
{
	int				*x;
	int				*y;
	int				*alt;
	int				*color;
	int				offset;
	int				sep;
	int				colonne;
	struct s_line	*next;
}				t_line;
typedef	struct	s_image
{
	void	*ima;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		width;
	int		heigth;
}				t_image;
typedef	struct	s_mat
{
	double	**mat_tr_init;
	double	**mat_tr;
	double	**mat_rot;
	double	**mat_sc;
	double	**mat_proj;
}				t_mat;
typedef	struct	s_param
{
	void	*mlx;
	void	*win;
	t_line	*line;
	t_image *image;
	t_mat	*mat;
	int		proj;
}				t_param;
typedef	struct	s_infseg
{
	int dx;
	int dy;
	int color1;
	int color2;
}				t_infseg;
int				ft_trace_seg_image(t_coord *a, t_image *image,\
		int color1, int color2);
void			ft_free_elem_correct(t_line *tmp);
void			ft_free_work_line(int **infline, char ***tab);
void			ft_free_tmp1(char ***tmp);
void			ft_free_create_elem(int **alt, int **color);
void			ft_free_lst1(t_line **line);
void			ft_free_coord_a(t_coord *a);
void			ft_free_line(t_line *line);
void			ft_free_param1(t_param *param);
void			ft_free_param(t_param *param);
void			ft_free_mat(double **mat, int i);
int				ft_putstr_inf(t_param *param);
int				ft_destroy(t_param *param);
char			*ft_convert_base_fdf(const char *base1, const char *base11,\
		const char *base2, char *str);
int				ft_tab_length(char **tab);
t_line			*ft_fdf_get_file(char *file);
int				ft_correct_file(t_line **line);
double			*ft_calc_mat(t_line *tmp, int i, double **mat, double *ret);
double			**ft_calc_mat2(double **mat, double **mat2);
t_mat			*ft_calc_mat_proj(t_mat *mat);
double			*ft_calc_coord_iso(t_line *tmp, int i, t_mat *mat, double *ret);
double			**ft_create_matrice(char *rts, char axe, double val);
t_mat			*ft_mat_first_proj(t_line *line);
int				ft_paral_proj(t_line **line, double coef,\
		double **mat, t_image *image);
int				ft_iso_proj(t_line **line, t_mat *mat, t_image *image);
int				ft_put_seg1_im(int *a1, int *a2, t_image *image, t_infseg *inf);
int				ft_put_seg2_im(int *a1, int *a2, t_image *image, t_infseg *inf);
int				ft_put_seg3_im(int *a1, int *a2, t_image *image, t_infseg *inf);
int				ft_put_seg4_im(int *a1, int *a2, t_image *image, t_infseg *inf);
void			ft_deal_key_rot(int key, t_param *param);
void			ft_deal_key_trans(int key, t_param *param);
void			ft_deal_key_scale(int key, t_param *param);
void			ft_deal_key_proj(t_param *param);
#endif
