/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 10:48:09 by samberna          #+#    #+#             */
/*   Updated: 2024/09/05 11:14:48 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	ac;

	i = 0;
	while (i <= size - 1)
	{
		ac = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = ac;
		i++;
		size--;
	}
}

/*int main()
{
	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	for(int i = 0; i <= 8; i++)
	{
		printf("%d", tab[i]);
	}

	printf("\n");

	ft_rev_int_tab(tab, 9);
	for(int i = 0; i <= 8; i++)
	{
		printf("%d", tab[i]);
	}
}*/
