/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:50:49 by samberna          #+#    #+#             */
/*   Updated: 2024/09/11 16:52:09 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	r;

	i = 1;
	r = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (i < nb + 1)
	{
		r *= i;
		i++;
	}
	return (r);
}

#include<stdio.h>
int main(){printf("%d",ft_iterative_factorial(3));}
