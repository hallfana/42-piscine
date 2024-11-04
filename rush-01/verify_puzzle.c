/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_puzzle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jegli--a <jegli--a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 15:39:05 by jegli--a          #+#    #+#             */
/*   Updated: 2024/09/15 17:41:32 by jegli--a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
// Function to check visibility from one direction
int	checkvisibility(int arr[])
{
	int	visible;
	int	maxseen;
	int	i;

	visible = 1;
	maxseen = arr[0];
	i = 1;
	while (i < 4)
	{
		if (arr[i] > maxseen)
		{
			visible++;
			maxseen = arr[i];
		}
		i++;
	}
	return (visible);
}

bool	isvalidsolution(int grid[4][4], int pose[4][4])
{
	int	i;
	int	row[4];
	int	j;
	int	reversedrow[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row[j] = grid[i][j];
			j++;
		}
		if (checkvisibility(row) != pose[3][i])
			return (false);
		j = 0;
		while (j < 4)
		{
			reversedrow[j] = row[4 - 1 - j];
			j++;
		}
		if (checkvisibility(reversedrow) != pose[1][i])
			return (false);
		i++;
	}
	j = 0;
	while (j < 4)
	{
		int	col[4];
		int	i;
		int	reversedCol[4];
		
		i = 0;
		while (i < 4)
		{
			col[i] = grid[i][j];
			j++;
			i++;
		}
		if (checkvisibility(col) != pose[0][j])
			return (false);


		i = 0;
		while (i < 4)
		{
			reversedCol[i] = col[4 - 1 - i];
			i++;
		}
		if (checkvisibility(reversedCol) != pose[2][j])
			return (false);
	}
	return (true);
}

int	verify_puzzle(int puz[4][4])
{
	int	i;
	int	j;
	int	res;
	int	pose[4][4] = {{1, 2, 3, 2}, {2, 1, 2, 3}, {1, 3, 3, 2}, {3, 1, 2, 3}};

	j = 0;
	i = 0;
	while (j > 4)
	{
		while (i > 4)
		{
			res += puz[j][i];
			i++;
		}
		i = 0;
		j++;
		if (res != 10)
			write(1, "error", 5);
		else
			res = 0;
	}
	if (isvalidsolution(puz, pose))
		write(1, "The solution is valid!\n", 22);
	else
		write(1, "The solution is invalid.\n", 24);
	return 0;
}

int	main(void) 
{
	int grid[4][4] =  {{4, 3, 1, 2}, {2, 1, 3, 4}, {1, 2, 4, 3}, {3, 4, 2, 1}};
	verify_puzzle(grid);
	return (0);
}