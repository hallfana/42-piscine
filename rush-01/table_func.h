/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_func.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:58:18 by samberna          #+#    #+#             */
/*   Updated: 2024/09/15 17:38:22 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**gen_tab(void)
{
	int	i;
	int	j;
	int	**tab;

	i = 0;
	tab = malloc(4 * sizeof(int *));
	while (i < 4)
	{
		tab[i] = malloc(4 * sizeof(4));
		i++;
	}
	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (tab);
}

int	**gen_pairs(int	*clues)
{
	int	**pairs;
	int	i;

	i = 0;
	pairs = malloc(4 * sizeof(int *));
	while (i < 4)
	{
		pairs[i] = malloc(2 * sizeof(int));
		i++;
	}
	pairs[0][0] = clues[15];
	pairs[0][1] = clues[4];
	pairs[1][0] = clues[14];
	pairs[1][1] = clues[5];
	pairs[2][0] = clues[13];
	pairs[2][1] = clues[6];
	pairs[3][0] = clues[12];
	pairs[3][1] = clues[7];
	return (pairs);
}
