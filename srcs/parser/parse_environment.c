/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:23 by kbulwer           #+#    #+#             */
/*   Updated: 2021/10/05 17:18:37 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"

int			check_float(char *line)
{
	int i;
	int dot;
	int col;

	i = 0;
	dot = 0;
	col = 0;
	if (line[i] == '-')
		i++;
	if (!ft_isdigit(line[i]))
		return (0);
	while (line[i])
	{
		if (line[i] == '.')
			dot++;
		else if (!(ft_isdigit(line[i])))
			return (0);
		col++;
		i++;
	}
	if (dot > 1 || col > 9)
		return (0);
	return (1);
}

int			parse_ambient(t_scene **scene, char **split, int count)
{
	if ((*scene)->amb != 0)
		return (0);
	if (count != 3)
		return (0);
	if (!((*scene)->amb = init_amb()))
		return (0);
	if (!check_float(split[1]))
		return (0);
	(*scene)->amb->ambint_lighting = ft_atof(split[1]);
	if ((*scene)->amb->ambint_lighting < 0 ||
	(*scene)->amb->ambint_lighting > 1)
		return (0);
	if (((*scene)->amb->ambient_color = parse_color(split[2])) == 0)
		return (0);
	return (1);
}

t_camera	*new_cam(char **split)
{
	t_camera *camera;

	if (!(camera = init_camera()))
		return (0);
	if (!(camera->point = parse_vec(split[1])))
		return (0);
	if (!(camera->vec = parse_vec(split[2])))
		return (0);
	if (!limit_vec(camera->vec))
		return (0);
	camera->fov = ft_atof(split[3]);
	if (camera->fov > 180 || camera->fov < 0)
		return (0);
	camera->fov = (camera->fov * M_PI / 360.0);
	if (camera->fov == 180)
		camera->fov = 179.999;
	camera->matrix = lookat(camera);
	return (camera);
}

int			parse_cameras(t_scene *scene, char **split, int count)
{
	t_camera *camera;

	if (count != 4)
		return (0);
	if (!check_float(split[3]))
		return (0);
	camera = new_cam(split);
	if (!camera)
		return (0);
	ft_lstadd_back_cam(&(scene->camera), camera);
	return (1);
}

t_light		*new_light(char **split)
{
	t_light *light;

	if (!(light = init_light()))
		return (0);
	if (!(light->point = parse_vec(split[1])))
		return (0);
	if (!(light->brightness = ft_atof(split[2])))
		return (0);
	if (!(light->color = parse_color(split[3])))
		return (0);
	if (light->brightness > 1 || light->brightness < 0)
		return (0);
	return (light);
}
