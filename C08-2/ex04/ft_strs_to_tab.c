/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:51:05 by samberna          #+#    #+#             */
/*   Updated: 2024/09/26 10:23:59 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

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
		i++;
	}
	s[i].str = 0;
	return (s);
}

/* TEST CODE */
/*#include <unistd.h>

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	pc(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nbr < 10)
		pc('0' + nbr);
	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		pc('0' + nbr % 10);
	}
}

void	ft_show_tab(struct s_stock_str *ptr)
{
	int	i;

	i = 0;
	while (ptr[i].str != 0)
	{
		putstr(ptr[i].str);
		ft_putnbr(ptr[i].size);
		write(1, "\n", 1);
		putstr(ptr[i].copy);
		i++;
	}
}

int main(){
	char *av[69] = {"hello1", "hello2", "hello3", "hello4"};
	int ac = 4;

	struct s_stock_str *a = ft_strs_to_tab(ac, av);
	ft_show_tab(a);
	(void)a;
}*/
