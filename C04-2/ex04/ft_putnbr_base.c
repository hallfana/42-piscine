/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:57:30 by samberna          #+#    #+#             */
/*   Updated: 2024/09/10 16:19:40 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	clean_base(char *base)
{
	int		i;
	int		k;
	char	c[128];

	i = 0;
	k = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (c[k])
		{
			if (c[k] == base[i])
				return (1);
			else
			{
				c[k] = base[i];
				k++;
			}
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (ft_strlen(base) == 1 || clean_base(base) != 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < ft_strlen(base))
	{
		write(1, &base[nbr], 1);
		return ;
	}
	if (nbr > ft_strlen(base) - 1)
		ft_putnbr_base(nbr / ft_strlen(base), base);
	write(1, &base[nbr % ft_strlen(base)], 1);
}

/*int main() { ft_putnbr_base(9999, "poneyvif"); }*/
