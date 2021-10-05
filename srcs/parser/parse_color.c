/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:16 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:18:07 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int		check_color_dop(char *line)
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

int		check_color(char **split)
{
	int j;

	j = 0;
	while (split[j])
	{
		if (!check_color_dop(split[j]))
			return (0);
		j++;
	}
	if (j != 3)
		return (0);
	return (1);
}

int		check_dot(char *line)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (line[i])
	{
		if (line[i] == ',')
			res++;
		i++;
	}
	if (res != 2)
		return (0);
	return (1);
}

t_color	*parse_color(char *line)
{
	char	**split_color;
	t_color	*color;

	if (!(color = (t_color *)malloc(sizeof(t_color))))
		return (0);
	if (!check_dot(line))
		return (0);
	split_color = ft_split(line, ',');
	if (!check_color(split_color))
		return (0);
	color->r = ft_atoi(split_color[0]);
	color->g = ft_atoi(split_color[1]);
	color->b = ft_atoi(split_color[2]);
	free_split(split_color);
	if (color->r > 255 || color->g > 255 || color->b > 255)
		return (0);
	return (color);
}
