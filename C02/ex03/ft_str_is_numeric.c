/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:01:56 by samberna          #+#    #+#             */
/*   Updated: 2024/09/05 17:10:24 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_str_is_numeric(char *str)
{
	int		i;
	char	c;

	if (ft_strlen(str) <= 0)
		return (1);
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c >= '0' && c <= '9')
		{
			i++;
			continue ;
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*int	main(void)
{
	printf("%d", ft_str_is_numeric(""));
}*/
