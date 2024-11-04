/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:07:14 by samberna          #+#    #+#             */
/*   Updated: 2024/09/12 17:07:36 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_placable(int *tab, int col, int row)
{
	return (1);
}

#include <stdio.h>
int	main()
{
	int a[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			a[i][j] = 0;
		}
	}

	a[2][5] = 1;

	for (int ii = 0; ii < 10; ii++)
	{
		for (int jj = 0; jj < 10; jj++)
		{
			printf("%d", a[ii][jj]);
		}
		printf("\n");
	}
}
