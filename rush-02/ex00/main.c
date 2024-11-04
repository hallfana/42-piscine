/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 13:27:07 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 13:27:08 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "util.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*read_file(int fd, int *sz);
int		*parse_number(t_dict_entry *dict, int dict_len, char *nb, int nb_len);
void	print_value(char *s);
void	print_number(t_dict_entry *dict, int *number);

int	get_dict(char *path)
{
	int	fd;

	if (path)
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			ft_print(2, "Failed to open dictionary: '");
			ft_print(2, path);
			ft_print(2, "'\n");
		}
	}
	else
	{
		fd = open("numbers.dict", O_RDONLY);
		if (fd < 0)
			ft_print(2, "Failed to open dictionary: 'numbers.dict'\n");
	}
	return (fd);
}

char	*validate_number(char *nb, int nb_len)
{
	int	len;
	int	i;

	while (nb[0] == ' ' || (nb[0] > 9 && nb[0] < 13))
	{
		++nb;
		nb_len--;
	}
	while (nb[0] == '0' && nb_len != 1 && nb++)
		nb_len--;
	len = ft_strlen(nb);
	if (!len)
		return (ft_print(2, "Error\n"), NULL);
	while (len && (nb[len - 1] == ' ' || (nb[len - 1] > 9 && nb[len - 1] < 13)))
		--len;
	nb[len] = '\0';
	i = 0;
	while (nb[i] >= '0' && nb[i] <= '9')
		++i;
	if (len != i)
		return (ft_print(2, "Error\n"), NULL);
	if (len >= 40)
		return (ft_print(2, "Dict Error\n"), NULL);
	return (nb);
}

int	get_number(char *buf, int buf_len, char *nb, int nb_len)
{
	int				dict_len;
	t_dict_entry	*dict;
	int				*number;

	dict = parse_dict(buf, buf_len, &dict_len);
	if (!dict)
	{
		ft_print(2, "Dict Error\n");
		return (1);
	}
	nb = validate_number(nb, nb_len);
	if (nb)
		number = parse_number(dict, dict_len, nb, ft_strlen(nb));
	if (!nb || !number)
	{
		free_dict(dict, dict_len);
		return (1);
	}
	print_number(dict, number);
	free_dict(dict, dict_len);
	free(number);
	return (0);
}

int	get_input(int argc, char **argv, char **data, int *len)
{
	int	fd;

	if (argc >= 3)
		fd = get_dict(argv[2]);
	else
		fd = get_dict(NULL);
	if (fd < 0)
		return (0);
	*data = read_file(fd, len);
	return (1);
}

int	main(int argc, char **argv)
{
	char			*input[2];
	int				input_len[2];
	int				errsv;

	if (argc >= 3)
		ft_swap(argv + 1, argv + 2);
	if (argc <= 1)
		input[1] = read_file(0, &input_len[1]);
	else
	{
		input[1] = argv[1];
		input_len[1] = ft_strlen(input[1]);
	}
	errsv = 1;
	if (get_input(argc, argv, &input[0], &input_len[0]))
	{
		errsv = get_number(input[0], input_len[0], input[1], input_len[1]
				- (argc <= 1));
		free(input[0]);
	}
	if (argc <= 1)
		free(input[1]);
	return (errsv);
}
