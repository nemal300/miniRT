/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:30:55 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 14:23:17 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			is_shadowed(t_vec *dir, t_vec *o, t_scene *scene, t_light *light)
{
	t_camera	*cam;
	double		t;
	double		len;
	t_vec		*dist;

	t = 0;
	dist = vec_sub(light->point, o);
	len = vec_len(dist);
	cam = init_camera();
	cam->point = vec_fill(o->x, o->y, o->z);
	search_shadow(scene->obj, dir, cam, &t);
	free(dist);
	free_camera(&cam);
	if (len > t)
		return (1);
	else
		return (0);
}

t_vec		*get_amb(t_scene *scene)
{
	t_vec *res;

	res = init_vec();
	res->x = scene->amb->ambint_lighting * (scene->amb->ambient_color->r / 255);
	res->y = scene->amb->ambint_lighting * (scene->amb->ambient_color->g / 255);
	res->z = scene->amb->ambint_lighting * (scene->amb->ambient_color->b / 255);
	return (res);
}

void		light_up(double cos, t_light *light, t_vec **res)
{
	(*res)->x += cos * light->brightness * (light->color->r / 255);
	(*res)->y += cos * light->brightness * (light->color->g / 255);
	(*res)->z += cos * light->brightness * (light->color->b / 255);
}

t_vec		*compute_c_w(t_scene *s, t_vec *ray, t_vec *point, t_obj *obj)
{
	double	cos;
	t_vec	*dir;
	t_light	*light;
	t_vec	*norm;
	t_vec	*res;

	res = get_amb(s);
	light = s->light;
	while (light)
	{
		dir = vec_sub(light->point, point);
		if (!is_shadowed(vec_norm(dir), point, s, light))
		{
			norm = compute_norm(obj, point, vec_norm(ray));
			cos = vec_calculate_cos(norm, dir);
			if (cos < 0)
				cos = 0;
			light_up(cos, light, &res);
			free(norm);
		}
		free(dir);
		light = light->next;
	}
	return (res);
}

t_color		*compute_light(t_scene *scene, t_obj *obj, t_vec *ray, double t)
{
	t_color	*color;
	t_vec	*point;
	t_vec	*res;

	color = create_color(obj->color);
	point = vec_sum(vec_mult(ray, t), scene->camera->point);
	res = compute_c_w(scene, ray, point, obj);
	color->r *= res->x;
	color->g *= res->y;
	color->b *= res->z;
	free(point);
	free(res);
	if (color->r > 255)
		color->r = 255;
	if (color->g > 255)
		color->g = 255;
	if (color->b > 255)
		color->b = 255;
	return (color);
}
