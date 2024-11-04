/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:47:11 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 15:47:20 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	*ft_realloc(void *old, size_t oldSz, size_t newSz)
{
	size_t	i;
	char	*new;

	new = malloc(newSz);
	if (!new)
		return (new);
	i = 0;
	while (i < oldSz)
	{
		((char *)new)[i] = ((char *)old)[i];
		++i;
	}
	free(old);
	return (new);
}

char	*read_file(int fd, int *sz)
{
	int		n;
	char	*buf;

	buf = malloc(8192);
	if (!buf)
		return (NULL);
	*sz = 0;
	n = read(fd, buf + *sz, 8192);
	while (n > 0)
	{
		*sz += n;
		buf = ft_realloc(buf, *sz, *sz + 8192);
		if (!buf)
			return (NULL);
		n = read(fd, buf + *sz, 8192);
	}
	if (n < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

int	ft_count(char *s, int n, char *set)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < n)
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				++count;
			++j;
		}
		++i;
	}
	return (count);
}

int	ft_find(char *s, int n, char *set)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (set[j])
		{
			if (s[i] == set[j])
				return (i);
			++j;
		}
		++i;
	}
	return (-1);
}

char	*ft_strdupit(char *start, char *end)
{
	char	*r;
	int		i;

	r = malloc(end - start + 1);
	if (!r)
		return (r);
	i = 0;
	while (start + i != end)
	{
		r[i] = start[i];
		++i;
	}
	r[i] = 0;
	return (r);
}
