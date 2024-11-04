/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:33:28 by samberna          #+#    #+#             */
/*   Updated: 2024/09/11 15:01:20 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1 || index == 2)
		return (1);
	if (index == 3)
		return (2);
	return ((ft_fibonacci(index - 1) + ft_fibonacci(index - 2)));
}

/*#include<stdio.h>
int main(){printf("%d",ft_fibonacci(10));}*/
