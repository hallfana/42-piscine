/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 08:58:59 by samberna          #+#    #+#             */
/*   Updated: 2024/09/05 12:07:01 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main()
{
	int	a, b, c, d;
	int *div;
	int	*mod;
	a = 4;
	b = 2;
	c = 99;
	d = 99;
	div = &c;
	mod = &d;
	ft_div_mod(a, b, div, mod);
	printf("valeur de *div: %d, valeur de *mod: %d", *div, *mod);
}*/
