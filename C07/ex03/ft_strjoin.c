/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 09:19:43 by samberna          #+#    #+#             */
/*   Updated: 2024/09/16 16:38:24 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>

int	sl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	size;

	i = 0;
	size = sl(dest);
	while (src[i] != '\0')
	{
		dest[size + i] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*str;

	if (size <= 0)
		return ((char *)malloc(1));
	i = 0;
	len = 0;
	while (sl(strs[i]) > 0)
	{
		len++;
		len += sl(strs[i]);
		i++;
	}
	i = 0;
	str = (char *)malloc(len * sizeof(char));
	while (sl(strs[i]) > 0)
	{
		str = ft_strcat(str, strs[i]);
		if (sl(strs[i + 1]) > 0)
			str = ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/*int	main(void){
	char	**ptr;
	ptr = malloc(3 * sizeof(char *));
	int i = 0;
	while (i < 4)
	{
		ptr[i] = malloc(3 * sizeof(char));
		i++;
	}

	ptr[0] = "as";
	ptr[1] = "ab";
	ptr[2] = "ag";

	//printf("%s", ptr[0]);
	char *a;

	a = ft_strjoin(0, ptr, "|");
	free(a);
}*/
