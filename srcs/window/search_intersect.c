/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:20 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 13:02:26 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		intersect_exists(t_obj *obj, t_camera *cam, t_vec *ray, double *t)
{
	if (obj->type == SP)
		return (intersect_sphere(cam, obj, ray, t));
	if (obj->type == PL)
		return (intersect_plane(cam, obj, ray, t));
	if (obj->type == SQ)
		return (intersect_square(cam, obj, ray, t));
	if (obj->type == TR)
		return (intersect_triangle(cam, obj, ray, t));
	if (obj->type == CY)
		return (intersect_cylinder(cam, obj, ray, t));
	return (0);
}

t_obj	*search_shadow(t_obj *obj, t_vec *ray, t_camera *cam, double *t)
{
	t_obj	*check_obj;
	double	near;
	t_obj	*near_obj;

	near = INFINITY;
	near_obj = 0;
	check_obj = obj;
	while (check_obj)
	{
		if (intersect_exists(check_obj, cam, ray, t))
		{
			if (*t < near)
			{
				near = *t;
				near_obj = check_obj;
				return (near_obj);
			}
		}
		check_obj = check_obj->next;
	}
	*t = near;
	return (near_obj);
}

t_obj	*search_first_obj(t_obj *obj, t_vec *ray, t_camera *cam, double *t)
{
	t_obj	*check_obj;
	double	near;
	t_obj	*near_obj;

	near = INFINITY;
	near_obj = 0;
	check_obj = obj;
	while (check_obj)
	{
		if (intersect_exists(check_obj, cam, ray, t))
		{
			if (*t < near)
			{
				near = *t;
				near_obj = check_obj;
			}
		}
		check_obj = check_obj->next;
	}
	*t = near;
	return (near_obj);
}
