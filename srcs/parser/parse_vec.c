/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:39 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:37:28 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int		check_vec_dop(char *line)
{
	int j;
	int col;

	j = 0;
	col = 0;
	while (line[j])
	{
		if (!ft_isdigit(line[j]))
			return (0);
		if ((ft_isdigit(line[j])))
		{
			j++;
			col++;
		}
		if (col == 0)
			return (0);
		j++;
	}
	return (1);
}

int		check_vec(char **split)
{
	int j;

	j = 0;
	while (split[j])
	{
		if (!check_float(split[j]))
			return (0);
		j++;
	}
	if (j != 3)
		return (0);
	return (1);
}

t_vec	*parse_vec(char *s)
{
	char	**split_vec;
	t_vec	*vec;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (0);
	if (!check_dot(s))
		return (0);
	split_vec = ft_split(s, ',');
	if (!check_vec(split_vec))
		return (0);
	vec->x = ft_atof(split_vec[0]);
	vec->y = ft_atof(split_vec[1]);
	vec->z = ft_atof(split_vec[2]);
	free_split(split_vec);
	return (vec);
}
