/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_999.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 12:56:32 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 12:56:33 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "util.h"
#include <stdlib.h>
#include <unistd.h>

int	fetch_number(t_dict_entry *dict, int dict_len, char *key);

int	number_9(int *result, t_dict_entry *dict, int dict_len, char *nb)
{
	char	tmp[2];

	if (nb[0] == '0')
		return (0);
	tmp[0] = '0';
	tmp[1] = 0;
	if (nb[0] == '0')
		return (1);
	tmp[0] = nb[0];
	result[0] = fetch_number(dict, dict_len, tmp);
	if (result[0] < 0)
		return (0);
	return (1);
}

int	number_99(int *result, t_dict_entry *dict, int dict_len, char *nb)
{
	char	tmp[3];

	tmp[0] = '0';
	tmp[1] = '0';
	tmp[2] = 0;
	if (nb[0] <= '1')
	{
		tmp[0] = '1';
		tmp[1] = nb[1];
		result[0] = fetch_number(dict, dict_len, tmp);
		return (result[0] > 0);
	}
	else
	{
		tmp[0] = nb[0];
		tmp[1] = '0';
		result[0] = fetch_number(dict, dict_len, tmp);
		if (result[0] < 0)
			return (0);
		return (1 + number_9(result + 1, dict, dict_len, nb + 1));
	}
}

int	number_999(int *result, t_dict_entry *dict, int dict_len, t_slice nb)
{
	if (nb.str[0] == '0' && nb.str[1] == '0' && nb.str[2] == '0')
		return (0);
	else if (nb.str[0] == '0' && nb.str[1] == '0')
		return (number_999(result, dict, dict_len, (t_slice){nb.str + 2,
				nb.len - 2}));
	else if (nb.str[0] == '0')
		return (number_999(result, dict, dict_len, (t_slice){nb.str + 1,
				nb.len - 1}));
	if (nb.len % 3 == 1)
		return (number_9(result, dict, dict_len, nb.str));
	else if (nb.len % 3 == 2)
		return (number_99(result, dict, dict_len, nb.str));
	else
	{
		if (number_9(result, dict, dict_len, nb.str) < 0)
			return (0);
		result[1] = fetch_number(dict, dict_len, "100");
		if (result[1] < 0)
			return (0);
		if (nb.str[1] == '0' && nb.str[2] == '0')
			return (2);
		else if (nb.str[1] == '0')
			return (2 + number_9(result + 2, dict, dict_len, nb.str + 2));
		return (2 + number_99(result + 2, dict, dict_len, nb.str + 1));
	}
}
