/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_modif.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmasson <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:42:32 by pmasson           #+#    #+#             */
/*   Updated: 2019/06/11 12:45:42 by pmasson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_modif(char *str, int *d)
{
	int		i;
	long	a;
	long	coeff;

	i = 0;
	a = 0;
	coeff = 1;
	if (str == 0)
		return (0);
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\v')
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		a = str[i] == '+' ? a : a + coeff * (str[i] - 48);
		coeff = coeff * 10;
		if (a > 2147483648 || (a == 2147483648 && str[0] != '-')\
				|| coeff > 10000000000)
			return (0);
		i--;
	}
	*d = a;
	return (1);
}
