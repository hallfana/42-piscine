/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:47:06 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 15:47:07 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <stdlib.h>

t_dict_entry	*new_dict(int len)
{
	t_dict_entry	*dict;
	int				i;

	dict = malloc(sizeof(t_dict_entry) * len);
	if (!dict)
		return (dict);
	i = 0;
	while (i < len)
	{
		dict[i].value = NULL;
		dict[i].key = NULL;
		++i;
	}
	return (dict);
}

void	free_dict(t_dict_entry *dict, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (dict[i].key)
			free(dict[i].key);
		if (dict[i].value)
			free(dict[i].value);
		++i;
	}
	free(dict);
}
