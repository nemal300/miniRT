/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:20 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:20:20 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*new_cylinder(char **split)
{
	t_obj *cylinder;

	if (!(cylinder = init_obj()))
		return (0);
	cylinder->type = CY;
	if (!(cylinder->pos = parse_vec(split[1])))
		return (0);
	if (!(cylinder->vec = parse_vec(split[2])))
		return (0);
	if (!limit_vec(cylinder->vec))
		return (0);
	if (!(cylinder->d = ft_atof(split[3])))
		return (0);
	cylinder->d = cylinder->d;
	if (!(cylinder->h = ft_atof(split[4])))
		return (0);
	if (!(cylinder->color = parse_color(split[5])))
		return (0);
	return (cylinder);
}

int		parse_cylinder(t_scene *scene, char **split, int count)
{
	t_obj *cylinder;

	if (count != 6)
		return (0);
	cylinder = new_cylinder(split);
	if (!cylinder)
		return (0);
	ft_lstadd_back_obj(&(scene->obj), cylinder);
	return (1);
}
