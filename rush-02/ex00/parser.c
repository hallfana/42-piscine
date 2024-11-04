/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:47:09 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 15:47:20 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "util.h"
#include <stdlib.h>

char	*read_file(int fd, int *sz);
int		ft_count(char *s, int n, char *set);
int		ft_find(char *s, int n, char *set);
char	*ft_strdupit(char *start, char *end);

char	*make_key(char *start, char *end)
{
	while (*start == '0' && start + 1 != end)
		++start;
	return (ft_strdupit(start, end));
}

char	*make_value(char *start, char *end)
{
	int	i;

	while (*start == ' ')
		++start;
	while (*(end - 1) == ' ')
		--end;
	i = 0;
	while (start + i != end)
	{
		if (start[i] < 32 || start[i] > 126)
			return (NULL);
		++i;
	}
	return (ft_strdupit(start, end));
}

int	parse_line(char *line, int len, t_dict_entry *ent)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < len && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		++i;
	i += (line[i] == '+');
	if (line[i] < '0' || line[i] > '9')
		return (0);
	k = ft_find(line, len, ":");
	j = i;
	while (i < k && (line[i] >= '0' && line[i] <= '9'))
		++i;
	ent->key = make_key(line + j, line + i);
	i = k + 1;
	while (line[i] == ' ')
		++i;
	ent->value = make_value(line + i, line + len);
	return (ent->value != NULL);
}

/* Returns (NULL) on dict error */
t_dict_entry	*parse_dict(char *buf, int len, int *dict_len)
{
	const int		lines = ft_count(buf, len, "\n");
	t_dict_entry	*entries;
	int				n;
	int				p;

	entries = new_dict(lines);
	if (!entries)
		return (entries);
	p = 0;
	n = ft_find(buf + p, len - p, "\n");
	*dict_len = 0;
	while (n != -1)
	{
		if (n >= 1 && !parse_line(buf + p, n, &entries[*dict_len]))
		{
			free_dict(entries, *dict_len + 1);
			return (NULL);
		}
		*dict_len += (n >= 1);
		p += n + 1;
		n = ft_find(buf + p, len - p, "\n");
	}
	return (entries);
}
