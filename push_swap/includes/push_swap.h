/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:43:28 by pmasson           #+#    #+#             */
/*   Updated: 2019/01/29 09:49:15 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "push_swap_get_next_line.h"
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_stack
{
	int				nb;
	int				place;
	struct s_stack	*next;
}				t_stack;
typedef	struct	s_ps
{
	t_stack	*a;
	t_stack	*b;
	int		numb[52];
	int		elemb;
	int		elema0;
	int		elema1;
	int		fd;
	int		elem;
	int		ra;
}				t_ps;
typedef	struct	s_ps_window
{
	void		*mlx;
	void		*win;
	void		*ima;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			heigth;
	int			color;
	t_stack		*a;
	t_stack		*b;
	int			elem;
	int			max;
	int			min;
	int			jumpa;
	int			jumpb;
	int			step;
	int			fd;
	int			minsize;
	int			range;
	int			play;
	int			c_stack;
}				t_ps_window;
int				ft_push_swap_create_stack(t_stack **a, t_stack **tmp,\
		char *str);
void			ft_push_swap_do_command(char *command, t_stack **a,\
		t_stack **b);
void			ft_push_swap_free_stack(t_stack **a);
int				push_swap_create_window(t_ps_window *window);
void			push_swap_display(t_stack **a, t_stack **b,\
		t_ps_window *window, char *command);
int				push_swap_checker_normal(t_stack **a, int fd);
int				push_swap_checker_visual(t_stack **a, int c, int fd);
int				push_swap_visual_command(t_ps_window *window);
int				push_swap_destroy_window(t_ps_window *window);
void			push_swap_display_check(t_stack **a, t_stack **b,\
		t_ps_window *window);
int				push_swap_create_command(t_stack **a, int f, char *file);
void			push_swap_med_sort(t_ps *all);
void			push_swap_write_do(char	*command, t_ps *all);
void			push_swap_med2(t_ps *all);
void			push_swap_med_tob(t_ps *all, int i);
void			push_swap_med_sort2(t_ps *all, int i);
void			push_swap_med_sort_zero(t_ps *all, int i);
void			push_swap_med_backb1(t_ps *all, int med, int i, int cpt);
void			push_swap_med_backb15(t_ps *all, int i);
void			push_swap_med_backb16(t_ps *all, int *nb, int *cpt);
#endif
