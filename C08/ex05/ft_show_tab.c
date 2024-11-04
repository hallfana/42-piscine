/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:40:40 by samberna          #+#    #+#             */
/*   Updated: 2024/09/18 16:36:21 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "a.h"

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	pc(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 10)
		pc('0' + nbr);
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		pc('0' + nbr % 10);
	}
}

void	ft_show_tab(struct s_stock_str *ptr)
{
	int	i;

	i = 0;
	while (ptr[i].str != 0)
	{
		putstr(ptr[i].str);
		putnbr(pt[i].size);
		write(1, "\n", 1);
		putstr(ptr[i].copy);
	}
}
