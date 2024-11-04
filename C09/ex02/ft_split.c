/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:24:50 by samberna          #+#    #+#             */
/*   Updated: 2024/09/25 16:51:36 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	in_set(char c, char *charset)
{
	int	i;

	i = 0;
	if (charset == 0)
		return (0);
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_word(char *src, char *charset)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 1;
	k = 0;
	if (src == 0)
		return (0);
	while (src[i])
	{
		if (!in_set(src[i], charset))
		{
			if (j == 1)
				k++;
			j = 0;
		}
		else
			j = 1;
		i ++;
	}
	return (k);
}

char	*ft_dup(char *s, int l)
{
	char	*d;
	int		i;

	i = -1;
	d = (char *)malloc((l + 1) * sizeof(char));
	if (!d)
		return (NULL);
	while (s[++i] != s[l])
		d[i] = s[i];
	d[i] = '\0';
	return (d);
}

char	**ft_split(char *str, char *charset)
{
	char	**r;
	int		i;
	int		jl[2];

	i = -1;
	jl[0] = 0;
	jl[1] = 0;
	r = (char **)malloc(count_word(str, charset) * sizeof(char *));
	if (!r || str == 0 || str == charset)
		return (NULL);
	while (str[++i])
	{
		if (!in_set(str[i], charset))
			jl[1]++;
		if (in_set(str[i], charset) && jl[1] > 0)
		{
			r[jl[0]] = ft_dup(&str[i - jl[1]], jl[1]);
			jl[0]++;
			jl[1] = 0;
		}
	}
	if (jl[1] != 0)
		r[jl[0]] = ft_dup(&str[i - jl[1]], jl[1]);
	r[jl[0] + 1] = 0;
	return (r);
}

#include <stdio.h>
int main() {
	char	*s = "HEY_ITS_GARRY";
	char	*sep = "_";
	char	**r;
	printf("test1\n");
	r = ft_split(s,sep);
	printf("test2\n");
	r = ft_split(0, 0);
	printf("test3\n");
	r = ft_split(0, "");
	printf("test4\n");
	r = ft_split("", 0);
	printf("test5\n");
	r = ft_split("", "");
	printf("test6\n");
	r = ft_split("asd", "");
	printf("test7\n");
	r = ft_split("", "asd");
	printf("test8\n");
	r = ft_split("asd", "asd");
	printf("test9\n");
	r = ft_split("HEY_ITS_GARRY", "_");
	if (r == 0)
	{
		printf(":3 \n");
		return 0;
	}
	r = ft_split(s, sep);
	printf("count word: %d\n", count_word(s,sep));
	for (int i = 0; i < count_word(s,sep) + 1; i++)
		printf("WORD: %s\n", r[i]);
}
