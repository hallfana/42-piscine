/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:27:07 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 13:27:08 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "dict.h"
#include "util.h"

void	print_value(char *s)
{
	int	i;
	int	insp;

	i = 0;
	insp = 1;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			if (!insp)
				write(1, " ", 1);
			insp = 1;
		}
		else
		{
			insp = 0;
			write(1, s + i, 1);
		}
		++i;
	}
}

int	nb_log10(char *nb)
{
	int	count;

	//printf("%s\n", nb);
	if (*nb != '1')
		return (0);
	++nb;
	count = 0;
	while (nb[count] == '0')
		++count;
	return (count * (nb[count] == '\0'));
}

void	print_number(t_dict_entry *dict, int *number)
{
	t_dict_entry	*last;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (number[j] != -1)
		j++;
	while (number[i] != -1)
	{
		if (i != 0)
		{
			if (last->value[ft_strlen(last->value) - 1] == 'y'
				|| last->value[ft_strlen(last->value) - 1] == 'Y')
				write(1, "-", 1);
			else if (ft_strcmp(last->key, "100") == 0 
					&& nb_log10(dict[number[i]].key) < 2 && (j - i) < 3)
				write(1, " and ", 5);
			else
				write(1, " ", 1);
		}
		print_value(dict[number[i]].value);
		last = &dict[number[i]];
		++i;
	}
	write(1, "\n", 1);
}
