/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:26 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/30 16:14:14 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int			limit_vec(t_vec *vec)
{
	if (vec->x > 1 || vec->y > 1 || vec->z > 1)
		return (0);
	if (vec->x < -1 || vec->y < -1 || vec->z < -1)
		return (0);
	return (1);
}

int			check_res(char **split)
{
	int j;

	j = 0;
	while (split[1][j])
	{
		if (ft_isalpha(split[1][j]) || split[1][j] == '.')
			return (0);
		j++;
	}
	j = 0;
	while (split[2][j])
	{
		if (ft_isalpha(split[2][j]) || split[2][j] == '.')
			return (0);
		j++;
	}
	return (1);
}

int			parse_resolution(t_scene **scene, char **split, int count)
{
	if ((*scene)->res->x != 0 || (*scene)->res->y != 0)
		return (0);
	if (!check_res(split))
		return (0);
	if (count != 3)
		return (0);
	(*scene)->res->x = ft_atoi(split[1]);
	(*scene)->res->y = ft_atoi(split[2]);
	if ((*scene)->res->x <= 0)
		return (0);
	if ((*scene)->res->y <= 0)
		return (0);
	if ((*scene)->res->x > 2560)
		(*scene)->res->x = 2560;
	if ((*scene)->res->y > 1440)
		(*scene)->res->y = 1440;
	return (1);
}

int			parse_light(t_scene *scene, char **split, int count)
{
	t_light *light;

	if (count != 4)
		return (0);
	if (!check_float(split[2]))
		return (0);
	light = new_light(split);
	if (!light)
		return (0);
	ft_lstadd_back_light(&(scene->light), light);
	return (1);
}
