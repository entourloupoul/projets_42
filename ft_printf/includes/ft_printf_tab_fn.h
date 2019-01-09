/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tab_fn.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:15:27 by pmasson           #+#    #+#             */
/*   Updated: 2018/12/11 17:04:32 by etlagors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TAB_FN_H
# define FT_PRINTF_TAB_FN_H

typedef	struct	s_function
{
	char	c;
	int		(*ft)(va_list *, char *, t_print **list);

}				t_function;
int				ft_printf_string(va_list *ap, char *flag, t_print **list);
int				ft_printf_uchar(va_list *ap, char *flag, t_print **list);
int				ft_printf_int(va_list *ap, char *flag, t_print **list);
int				ft_printf_address(va_list *ap, char *flag, t_print **list);
int				ft_printf_uint2(va_list *ap, char *flag, t_print **list);
int				ft_printf_uint3(va_list *ap, char *flag, t_print **list);
int				ft_printf_uint4(va_list *ap, char *flag, t_print **list);
int				ft_printf_double(va_list *ap, char *flag, t_print **list);
int				ft_printf_uint1(va_list *ap, char *flag, t_print **list);
int				ft_printf_percentage(va_list *ap, char *flag, t_print **list);
t_function	g_function[] =
{
	{'s', &ft_printf_string},\
	{'d', &ft_printf_int},\
	{'i', &ft_printf_int},\
	{'f', &ft_printf_double},\
	{'c', &ft_printf_uchar},\
	{'u', &ft_printf_uint1},\
	{'U', &ft_printf_uint1},\
	{'o', &ft_printf_uint2},\
	{'x', &ft_printf_uint3},\
	{'X', &ft_printf_uint4},\
	{'p', &ft_printf_address},\
	{'%', &ft_printf_percentage},\
	{'\0', NULL}\
};
#endif
