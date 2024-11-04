/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:03:52 by samberna          #+#    #+#             */
/*   Updated: 2024/09/07 20:44:25 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		counter;
	int		iner_counter;
	char	c;
	char	cc;

	counter = 0;
	iner_counter = 0;
	while (str[counter] != '\0')
	{
		if (str[counter] > 64 && str[counter] < 91)
			str[counter] += 32;
		c = str[counter];
		if ((c > 96 && c < 123) || (c > 64 && c < 91) || (c > 47 && c < 58))
			iner_counter++;
		else
		{
			cc = str[counter - iner_counter];
			if (cc > 96 && cc < 123)
				str[counter - iner_counter] = cc - 32;
			iner_counter = 0;
		}
		counter++;
	}
	return (str);
}

int main(void)
{
	char	str[] = " salut, ? 42mots quARARnte-deux; cinquante+et+un :3";

	printf("%s", ft_strcapitalize(str));
}
