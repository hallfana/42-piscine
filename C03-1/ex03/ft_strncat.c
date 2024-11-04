/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 02:56:17 by samberna          #+#    #+#             */
/*   Updated: 2024/09/08 03:08:25 by samberna         ###   ########.fr       */
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

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	int				size;

	i = 0;
	size = ft_strlen(dest);
	while (src[i] != '\0' && i < nb)
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

/*#include<stdio.h>
int	main(void)
{
	char	*s = "TESTESTESTESTETSTET";
	char	ss[10];

	ft_strncat(ss, s, 5);
	printf("%s", ft_strncat(ss, " HEADER", 7));
}*/
