/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 03:53:34 by samberna          #+#    #+#             */
/*   Updated: 2024/09/17 17:43:21 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{

}*/

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				size_dest;

	i = 0;
	size_dest = ft_strlen(dest);
	while (src[i] != '\0' && i < ft_strlen(src) && i < size)
	{
		dest[size_dest + i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
	return (ft_strlen(dest));
}

#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	dest[150] = "Bonjour";
	char	src[] = "la ville";
	char	dest1[150] = "Bonjour";
	char	src1[] = "la ville";

	printf("Voici int vrai strlcat : %u\n", ft_strlcat(dest, src, 120));
	printf("Voici dest concat vrai strlcat : %s\n", dest);
	printf("Voici int vrai strlcat : %ld\n", strlcat(dest1, src1, 120));
	printf("Voici dest concat vrai strlcat : %s\n", dest1);
	return (0);
}
