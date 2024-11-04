/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwebe-ir <fwebe-ir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 17:10:16 by fwebe-ir          #+#    #+#             */
/*   Updated: 2024/09/15 17:13:54 by fwebe-ir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The validator will check if the clues are possible to be solved
ex: 4:4 is not possible.
	-	The function will output 0 if is not possible
	-	The function will output 1 if all the clues are possible to be solved.
	-	(bvr - bvl) = Bad View Right/Left 1:1 ex =  (bad view)
	-	(vr - vl) = View Right/Left used to locate the correct viewers in each
					side of the board.
*/

int	validator(int *v)
{
	int	bvr[7] = {1, 2, 3, 3, 4, 4, 4};
	int	bvl[7] = {1, 4, 3, 4, 2, 3, 4};
	int	vr[8] = {0, 1, 2, 3, 4, 5, 6, 7};
	int	vl[8] = {11, 10, 9, 8, 15, 14, 13, 12};
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < 9)
		{
			if (v[vr[i]] == bvr[j] && v[vl[i]] == bvl[j])
			{
				return (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

/*
int	main(void)
{
//	int viewers_positions[16] =  {0,1,2,3,  4,5,6,7,  8,9,10,11,  12,13,14,15};
//	int	bad_clues[16] = {2,2,3,1,   1,3,4,2,  2,1,2, 3,   2, 2, 1, 3};
	int correct_clues[16] = {2,2,3,1,1,3,2,2,2,1,2,3,2,2,1,3};
//	int correct_clues[16] = {2, 3, 2, 1, 1, 2, 2, 3, 3, 2, 1, 2, 2, 1, 3, 3};

	printf("%d", validator(correct_clues));
	return (0);
}
*/