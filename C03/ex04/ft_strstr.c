/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 03:11:03 by samberna          #+#    #+#             */
/*   Updated: 2024/09/08 16:13:40 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		if (j == ft_strlen(to_find))
		{
			return (&str[i - j]);
		}
		i++;
	}
	return (0);
}

#include<stdio.h>
#include<string.h>
int	main(void)
{
	char	*str = "Sure fing to like boys :3";
	char	*to_find = "boys";

	printf("%s", ft_strstr(str, to_find));
}
