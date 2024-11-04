/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:51:05 by samberna          #+#    #+#             */
/*   Updated: 2024/09/19 11:13:49 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	sl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_dup(char *str)
{
	int		i;
	char	*gaymen;

	i = 0;
	gaymen = malloc(sl(str) + 1);
	while (str[i])
	{
		gaymen[i] = str[i];
		i++;
	}
	gaymen[i] = '\0';
	return (gaymen);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*s;
	t_stock_str	t;

	i = 0;
	s = (struct s_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (s == NULL)
		return (NULL);
	while (i < ac)
	{
		t.size = sl(av[i]);
		t.str = av[i];
		t.copy = ft_dup(av[i]);
		s[i] = t;
	}
	s[i].str = 0;
	return (s);
}
