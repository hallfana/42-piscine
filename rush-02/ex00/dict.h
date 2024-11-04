/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgamba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 22:19:06 by lgamba            #+#    #+#             */
/*   Updated: 2024/09/22 15:47:40 by lgamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

typedef struct s_dict_entry
{
	/* The number */
	char	*key;
	/* It's written form */
	char	*value;
}	t_dict_entry;

typedef struct s_slice
{
	char	*str;
	int		len;
}	t_slice;

t_dict_entry	*new_dict(int len);
void			free_dict(t_dict_entry *dict, int len);

/* Comparison function for dictionnary entries */
int				dict_cmp(t_dict_entry *a, t_dict_entry *b);

t_dict_entry	*parse_dict(char *buf, int len, int *dict_len);

#endif // DICT_H
