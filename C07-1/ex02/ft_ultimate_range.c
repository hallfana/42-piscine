/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 10:56:02 by samberna          #+#    #+#             */
/*   Updated: 2024/09/18 15:10:46 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	s;

	if (min >= max)
		return (0);
	*range = malloc((max - min) * 4);
	if (*range == NULL)
		return (-1);
	s = 0;
	while (min < max)
	{
		(*range)[s] = min;
		min++;
		s++;
	}
	return (s);
}

int main(void)
{
	int *test_subject;

	printf("return value from ft_ultimate_range: %d\n",
			ft_ultimate_range(&test_subject, -42, 69));

	for (int deux_point_troie = 0; deux_point_troie < 111;
			deux_point_troie++)
	{
		printf("%d, ", test_subject[deux_point_troie]);
	}
}
