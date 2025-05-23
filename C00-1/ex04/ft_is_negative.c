/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samberna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:56:24 by samberna          #+#    #+#             */
/*   Updated: 2024/09/04 15:43:41 by samberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	nv;
	char	pv;

	nv = 'N';
	pv = 'P';
	if (n >= 0)
	{
		write(1, &pv, 1);
	}
	else
	{
		write(1, &nv, 1);
	}
}
