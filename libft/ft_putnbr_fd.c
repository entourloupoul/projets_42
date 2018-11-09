/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:08:14 by pmasson           #+#    #+#             */
/*   Updated: 2018/11/08 18:37:52 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		a;
	char	c;

	i = 0;
	a = 1000000000;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	while (n / a == 0)
		a = a / 10;
	while (a != 0)
	{
		c = (n / a) + 48;
		write(fd, &c, 1);
		n = n - (n / a) * a;
		a = a / 10;
	}
}
