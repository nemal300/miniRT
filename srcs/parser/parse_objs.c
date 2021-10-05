/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:21:08 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 13:25:10 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_obj	*new_sphere(char **split)
{
	t_obj *sphere;

	if (!(sphere = init_obj()))
		return (0);
	sphere->type = SP;
	if (!(sphere->pos = parse_vec(split[1])))
		return (0);
	if (!(sphere->d = ft_atof(split[2])))
		return (0);
	if (!(sphere->color = parse_color(split[3])))
		return (0);
	return (sphere);
}

int		parse_sphere(t_scene *scene, char **split, int count)
{
	t_obj *sphere;

	if (count != 4)
		return (0);
	sphere = new_sphere(split);
	if (!sphere)
		return (0);
	ft_lstadd_front_obj(&(scene->obj), sphere);
	return (1);
}

t_obj	*new_plane(char **split)
{
	t_obj *plane;

	if (!(plane = init_obj()))
		return (0);
	plane->type = PL;
	if (!(plane->pos = parse_vec(split[1])))
		return (0);
	if (!(plane->vec = parse_vec(split[2])))
		return (0);
	if (!limit_vec(plane->vec))
		return (0);
	if (!(plane->color = parse_color(split[3])))
		return (0);
	return (plane);
}

int		parse_plane(t_scene *scene, char **split, int count)
{
	t_obj *plane;

	if (count != 4)
		return (0);
	plane = new_plane(split);
	if (!plane)
		return (0);
	ft_lstadd_back_obj(&(scene->obj), plane);
	return (1);
}
