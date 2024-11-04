/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:46:34 by samberna          #+#    #+#             */
/*   Updated: 2024/09/05 08:58:20 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_swap(int *a, int *b)
{
	int	defaulta;
	int	defaultb;

	defaulta = *a;
	defaultb = *b;
	*a = defaultb;
	*b = defaulta;
}

/*int	main()
{
	int	i;
	int	j;

	i = 6;
	j = 9;
	ft_swap(&i, &j);

	printf("value of i %d\n", i);
	printf("value of j %d", j);
}*/
