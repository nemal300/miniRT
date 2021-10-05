/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:28 by kbulwer           #+#    #+#             */
/*   Updated: 2021/10/05 17:42:27 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		convert_to_screen(double *x, double *y, t_scene *scene)
{
	double width;
	double height;
	double pcx;
	double pcy;

	width = (double)scene->res->x;
	height = (double)scene->res->y;
	pcx = (2 * (*x + 0.5) / width - 1) * scene->camera->fov;
	pcy = (1 - 2 * (*y + 0.5) / height) * scene->camera->fov;
	if (width > height)
		pcx = pcx * scene->wh;
	else
		pcy = pcy * scene->hw;
	*x = pcx;
	*y = pcy;
	return ;
}

t_vec		*get_ray(double x, double y, t_scene *scene)
{
	t_vec	*ray;
	t_vec	*temp;

	convert_to_screen(&x, &y, scene);
	ray = vec_fill(x, y, -1);
	temp = ray;
	ray = mat_mult_vec(scene->camera->matrix, temp);
	vec_norm(ray);
	free(temp);
	return (ray);
}

t_color		*create_color(t_color *color)
{
	t_color	*new;

	new = (t_color *)malloc(sizeof(t_color));
	if (!new)
		return (0);
	new->r = color->r;
	new->g = color->g;
	new->b = color->b;
	return (new);
}

t_color		*init_color(void)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (!color)
		return (0);
	color->r = 0;
	color->g = 0;
	color->b = 0;
	return (color);
}

t_color		*trace(int x, int y, t_scene *scene)
{
	t_vec	*ray;
	t_color	*color;
	t_obj	*obj;
	double	t;

	t = 0;
	ray = get_ray((double)x, (double)y, scene);
	obj = search_first_obj(scene->obj, ray, scene->camera, &t);
	if (obj)
	{
		color = compute_light(scene, obj, ray, t);
		free(ray);
		return (color);
	}
	free(ray);
	return (0);
}
