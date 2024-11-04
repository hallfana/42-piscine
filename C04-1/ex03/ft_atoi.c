/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:07:31 by samberna          #+#    #+#             */
/*   Updated: 2024/09/10 11:05:26 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
			continue ;
		}
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '+'
				|| str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
			return (res * sign);
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}

/*#include<stdio.h>
int	main(void)
{
	printf("%d\n", ft_atoi("   -61rtr564b"));
	printf("%d\n", ft_atoi("a-65"));
	printf("%d\n", ft_atoi("-asd221"));
	printf("%d\n", ft_atoi("asd5"));
}*/
