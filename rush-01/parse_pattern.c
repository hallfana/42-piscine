/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pattern.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwebe-ir <fwebe-ir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:03:34 by samberna          #+#    #+#             */
/*   Updated: 2024/09/15 17:12:17 by fwebe-ir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- get_varient : Will contain out Gdata. Stored in char datatype.
				      will call atoi_varient and output and array of ints.
	- atoi_varient : will parse an array of char (each varient) to an array of
				   ints.
*/
/*
	- var = varient of a pattern fetched by ft get_varient.
	- will convert the varient from char(c_var) to int(i_var).
*/

void	atoi_varient(char *c_var, int *i_var)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (c_var[i] != '\0')
	{
		if (c_var[i] >= '1' && c_var[i] <= '4' && j < 4)
		{
			i_var[j] = c_var[i] - '0';
			j++;
		}
		i++;
	}
}
/*
	- *reverse will output a char pointer with a string
	- static char is for allocating memory of the string in the memory
	  otherwise the variable will be always outputed empty.
*/

char	*reverse(char *str)
{
	int				i;
	int				j;
	static char		rstr[7];

	i = 6;
	j = 0;
	while (i >= 0)
	{
		rstr[j] = str[i];
		j++;
		i--;
	}
	rstr[j] = '\0';
	return (rstr);
}
/*
	- char (vl:vr) = View Left/Right ex 2:2 or 1:4;
	- int varient = is the numerical patter of each couple of viewers
	- int *i_var = is the an array of ints with the demanded pattern.
	- [REMINDER] all the mirror varients are being treated with reverse function
*/

void	get_varient(int vl, int vr, int var, int *i_var)
{
	char	*v13[] = {"4,3,1,2", "4,1,3,2"};
	char	*v14[] = {"4,3,2,1"};
	char	*v21[] = {"3,2,1,4", "3,1,2,4"};
	char	*v22[] = {"2,1,4,3", "1,4,2,3", "2,4,1,3", "3,2,4,1", "3,1,4,2", "3,4,1,2"};
	char	*v23[] = {"1,4,3,2", "2,4,3,1", "3,4,2,1"};

	if (vl == 1 && vr == 3 && var < 3)
		atoi_varient(v13[var], i_var);
	if (vl == 1 && vr == 4 && var == 0)
		atoi_varient(v14[0], i_var);
	if (vl == 2 && vr == 1 && var < 3)
		atoi_varient(v21[var], i_var);
	if (vl == 2 && vr == 2 && var < 6)
		atoi_varient(v22[var], i_var);
	if (vl == 2 && vr == 3 && var < 4)
		atoi_varient(v23[var], i_var);
	if (vl == 3 && vr == 1 && var < 3)
		atoi_varient(reverse(v13[var]), i_var);
	if (vl == 4 && vr == 1 && var == 0)
		atoi_varient(reverse(v14[0]), i_var);
	if (vl == 1 && vr == 2 && var < 3)
		atoi_varient(reverse(v21[var]), i_var);
	if (vl == 3 && vr == 2 && var < 4)
		atoi_varient(reverse(v23[var]), i_var);
}

// int	main(void)
// {
// 	int		i_var[4] = {0};
// 	int		i;
// 	i = 0;

// 	get_varient(1,3,1, i_var);
// 	while (i < 4)
//     {
// 		i++;
//     }

// 	return (0);
// }
