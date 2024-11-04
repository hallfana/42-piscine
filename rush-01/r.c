/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 13:46:07 by samberna          #+#    #+#             */
/*   Updated: 2024/09/15 17:39:17 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "table_func.h"
#include "parse_pattern.h"

int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	*beautify_clues(int	*clues_unformated)
{
	int	*clues;

	clues = malloc(16 * sizeof(int));
	clues[0] = clues_unformated[0];
	clues[1] = clues_unformated[1];
	clues[2] = clues_unformated[2];
	clues[3] = clues_unformated[3];
	clues[4] = clues_unformated[12];
	clues[5] = clues_unformated[13];
	clues[6] = clues_unformated[14];
	clues[7] = clues_unformated[15];
	clues[8] = clues_unformated[7];
	clues[9] = clues_unformated[6];
	clues[10] = clues_unformated[5];
	clues[11] = clues_unformated[4];
	clues[12] = clues_unformated[11];
	clues[13] = clues_unformated[10];
	clues[14] = clues_unformated[9];
	clues[15] = clues_unformated[8];
	return (clues);
}

int	*parse_argv(char *av, int	*error)
{
	int	i;
	int	j;
	int	*clues;

	clues = malloc(16 * sizeof(int));
	if (len(av) != 31)
		*error = 1;
	i = 0;
	j = 0;
	while (av[i] && *error == 0)
	{
		if (av[i] == ' ' && i % 2 == 1)
			i++;
		if (av[i] == '1' || av[i] == '2' || av[i] == '3' || av[i] == '4')
		{
			clues[j] = av[i] - '0';
			j++;
			i++;
			continue ;
		}
		*error = 1;
	}
	return (clues);
}

void	wi(char s)
{
	write(1, &s, 1);
}

int	main(int argc, char **argv)
{
	int	*clues;
	int	error;
	int	**tab;
	int	i;

	i = 0;
	error = 0;
	tab = gen_tab();
	clues = parse_argv(argv[1], &error);
	if (error != 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	clues = beautify_clues(clues);
	return (argc);
}
