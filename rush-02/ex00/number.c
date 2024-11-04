/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:56:37 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 12:56:38 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "util.h"
#include <stdlib.h>
#include <unistd.h>

int	number_999(int *result, t_dict_entry *dict, int dict_len, t_slice nb);

int	fetch_number(t_dict_entry *dict, int dict_len, char *key)
{
	int	i;

	i = 0;
	while (i < dict_len)
	{
		if (!ft_strcmp(dict[i].key, key))
			return (i);
		++i;
	}
	return (-1);
}

/* Get the index of a power of 10 in the dictionary */
int	get_power_of_10(t_dict_entry *dict, int dict_len, int power)
{
	int	i;
	int	j;

	i = -1;
	while (++i < dict_len)
	{
		if (!dict[i].key || dict[i].key[0] != '1')
			continue ;
		j = 1;
		while (j < power + 1 && dict[i].key[j] == '0')
			++j;
		if (j == power + 1 && !dict[i].key[j])
			return (i);
	}
	return (-1);
}

int	is_pow_ten(t_dict_entry *ent)
{
	int	i;

	if (!ent->key)
		return (0);
	else if (ent->key[0] != '1')
		return (0);
	i = 1;
	while (ent->key[i])
	{
		if (ent->key[i] != '0')
			return (0);
		++i;
	}
	return (i > 3);
}

int	*parse_number(t_dict_entry *dict, int dict_len, char *nb, int nb_len)
{
	int		*result;
	int		i;
	int		j;
	int		flag;

	result = malloc(4 * (1 + nb_len * 2));
	if (!result)
		return (result);
	else if (nb_len == 1 && nb[0] == '0')
		return (result[0] = fetch_number(dict, dict_len, "0"), result[1] = -1,
			result);
	i = 0;
	j = 0;
	while (i < nb_len)
	{
		j += number_999(result + j, dict, dict_len, (t_slice){nb + i,
				nb_len - i});
		flag = nb_len - i > 3;
		i += (i == 0 && nb_len % 3) * (nb_len % 3)
			+ (i != 0 || nb_len % 3 == 0) * 3;
		if (flag && (j == 0 || !is_pow_ten(&dict[result[j - 1]])))
			result[j++] = get_power_of_10(dict, dict_len, nb_len - i);
	}
	result[j] = -1;
	return (result);
}
