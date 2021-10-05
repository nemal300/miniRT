/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:07 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:10:26 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_camera	*init_camera(void)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		return (0);
	camera->point = 0;
	camera->vec = 0;
	camera->fov = 0;
	camera->forward = 0;
	camera->right = 0;
	camera->up = 0;
	camera->next = 0;
	return (camera);
}

t_light		*init_light(void)
{
	t_light *light;

	if (!(light = (t_light *)malloc(sizeof(t_light))))
		return (0);
	light->point = 0;
	light->brightness = 0;
	light->color = 0;
	light->next = 0;
	return (light);
}

t_obj		*init_obj(void)
{
	t_obj *obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		return (0);
	obj->color = 0;
	obj->d = 0;
	obj->h = 0;
	obj->next = 0;
	obj->p1 = 0;
	obj->p2 = 0;
	obj->p3 = 0;
	obj->p4 = 0;
	obj->pos = 0;
	obj->type = 0;
	obj->vec = 0;
	return (obj);
}

t_vec		*init_vec(void)
{
	t_vec *vec;

	vec = (t_vec *)malloc(sizeof(t_vec));
	if (!vec)
		return (0);
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	return (vec);
}
