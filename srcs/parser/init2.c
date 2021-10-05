/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:12 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:12:29 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_res		*init_res(void)
{
	t_res *res;

	res = (t_res *)malloc(sizeof(t_res));
	if (!res)
		return (0);
	res->x = 0;
	res->y = 0;
	return (res);
}

t_amb		*init_amb(void)
{
	t_amb *amb;

	amb = (t_amb *)malloc(sizeof(t_amb));
	if (!amb)
		return (0);
	amb->ambient_color = 0;
	amb->ambint_lighting = 0;
	return (amb);
}

t_scene		*init_scene(void)
{
	t_scene *scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (0);
	scene->res = init_res();
	scene->amb = 0;
	scene->light = 0;
	scene->camera = 0;
	scene->obj = 0;
	scene->main_cam = 0;
	return (scene);
}
