/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:46:40 by samberna          #+#    #+#             */
/*   Updated: 2024/09/19 15:24:33 by samberna         ###   ########.fr       */
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

/*int	main(void)
{
	ft_putnbr(-2147483648);
}*/
