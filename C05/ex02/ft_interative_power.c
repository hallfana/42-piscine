/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interative_power.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:36:11 by samberna          #+#    #+#             */
/*   Updated: 2024/09/11 16:52:36 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	r;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 1;
	r = nb;
	while (i < power)
	{
		r *= nb;
		i++;
	}
	return (r);
}

/*#include<stdio.h>
int main(){printf("%d",ft_iterative_power(5, 5));}*/
