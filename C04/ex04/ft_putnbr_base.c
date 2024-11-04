/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 19:53:35 by samberna          #+#    #+#             */
/*   Updated: 2024/09/09 20:52:17 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	while (str[i] != '\0')
		i++;

	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return;
	}

	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}

}
int	main(void)
{
	ft_putnbr_base(5486, "0123456789abcdef");
}
