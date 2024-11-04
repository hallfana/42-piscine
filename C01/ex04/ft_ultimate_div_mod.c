/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:27:57 by samberna          #+#    #+#             */
/*   Updated: 2024/09/05 12:05:48 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	r;
	int	m;

	m = *a % *b;
	r = *a / *b;
	*a = r;
	*b = m;
}

/*int	main()
{
	int a,b;
	a = 10;
	b = 3;
	ft_ultimate_div_mod(&a, &b);
	printf("value a: %d, value b: %d", a, b);
}*/
