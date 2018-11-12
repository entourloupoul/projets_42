#include "libft.h"

int	ft_valid_base(const char *base)
{
	int i;
	int k;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i] != '\0')
	{
		k = 0;
		while (base[k] != '\0')
		{
			if (base[k] == base[i])
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int	ft_valid_input(const char *base, char *str)
{
	int i;
	int k;

	i = 0;
	while (str[i] != '\0')
	{
		k = 0;
		while (str[i] != base[k] && base[k] != '\0')
			k++;
		if (base[k] == '\0')
			return (0);
		i++;
	}
	return (1);
}

unsigned long	ft_basetoi(const char *base, char *str)
{
	unsigned long	n;
	unsigned long	l;
	unsigned long	i;
	unsigned long	j;

	n = ft_strlen(base);
	i = n;
	while (i > 0)
	{
		j = 0;
		


char	*ft_convert_base(const char *base1, const char *base2, char *str)
{
	char	*ret;

	if (ft_valid_base(base1) == 0)
	{
		ft_putstr("base1 is not a valid base.");
		return (NULL);
	}
	if (ft_valid_base(base2) == 0)
	{
		ft_putstr("base2 is not a valid base.");
		return (NULL);
	}
	if (ft_valid_input(base1, str) == 0)
	{
		ft_putstr("Input is not valid in base 1.");
		return (NULL);
	}
	ret = ft_ltobase(base2, ft_basetol(base1, str));
	return (ret);
}

