/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:17:11 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 16:56:14 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_print
{
	char			*str;
	int				len;
	int				trigger;
	struct s_print	*next;
}				t_print;
typedef	struct	s_flag
{
	int			minus;
	int			plus;
	int			hashtag;
	int			space;
	int			zero;
	int			min_width;
	int			precision;
	int			l;
	int			ll;
	int			h;
}				t_flag;
int				ft_lstprintnew(char *str, int len, t_print **list);
void			ft_freelst_printf(t_print **list);
int				ft_display_printf(t_print **list, int total, int i, int j);
int				ft_is_not_flag(const char *format, int i, t_print **list);
int				ft_get_g_printf(const char *format, int *i);
int				ft_strchr_printf(char c);
int				ft_g_minus_one(char *flag, const char *format);
int				ft_printf(const char *format, ...);
t_flag			*ft_flag_printf(char *flag);
int				ft_flag_options_s(char **str, t_flag *parse);
int				ft_flag_options_p(char **str, t_flag *parse, int g);
int				ft_flag_options_d(char **str, t_flag *parse, long long n);
int				ft_flag_options_c(char **str, t_flag *parse);
int				ft_flag_options_o(char **str, t_flag *parse,\
		unsigned long long n);
int				ft_flag_options_x(char **str, t_flag *parse,\
		unsigned long long n);
int				ft_flag_options_xx(char **str, t_flag *parse,\
		unsigned long long n);
int				ft_flag_options_f(char **str, t_flag *parse, long double f);
int				ft_flag_options_u(char **str, t_flag *parse,\
		unsigned long long n);
char			*ft_printf_lftoa_no_signe(long double f, int precision);
#endif
