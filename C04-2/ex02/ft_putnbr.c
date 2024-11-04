/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:59:25 by samberna          #+#    #+#             */
/*   Updated: 2024/09/10 11:03:50 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putdigit(int d)
{
	char	zero;
	char	t;

	zero = '0';
	t = zero + d;
	write(1, &t, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putdigit(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putdigit(nb % 10);
	}
}

/*int main() { ft_putnbr(2147483648); }*/
