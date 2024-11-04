/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:23:31 by samberna          #+#    #+#             */
/*   Updated: 2024/09/16 16:40:00 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	j;

	if (min >= max)
		return (0);
	i = 0;
	j = min;
	tab = malloc((max - min) * 4);
	while (i < max - min)
	{
		tab[i] = j;
		j++;
		i++;
	}
	return (tab);
}

/*#include<stdio.h>
int main(void)
{
	int	*tablota;

	tablota = ft_range(-42, 69);

	for(int uwu; uwu < 150; uwu++)
		printf("%d\n", tablota[uwu]);
}*/
