/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 11:08:35 by samberna          #+#    #+#             */
/*   Updated: 2024/09/04 16:18:01 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putc(int inputa)
{
	char	zero;
	char	a;
	char	b;

	zero = '0';
	if (inputa > 10)
	{
		a = zero + (inputa / 10);
		b = zero + (inputa % 10);
	}
	else
	{
		a = zero;
		b = zero + inputa;
	}
	write(1, &a, 1);
	write(1, &b, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			ft_putc(i);
			write(1, " ", 1);
			ft_putc(j);
			if (j == 99 && i == 98)
				write(1, "\n", 1);
			else
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

/*int	main(void)
{
	ft_print_comb();
}*/
