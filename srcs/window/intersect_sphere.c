/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:01 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/30 19:30:11 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		intersect_sphere(t_camera *camera, t_obj *obj, t_vec *ray, double *t0)
{
	double	t1;
	t_vec	coef;
	t_vec	*temp;

	vec_norm(ray);
	temp = vec_sub(camera->point, obj->pos);
	coef.x = vec_scal_mult(ray, ray);
	coef.y = 2 * vec_scal_mult(ray, temp);
	coef.z = vec_scal_mult(temp, temp) - (obj->d * obj->d) / 4;
	solvequadratic(coef, t0, &t1);
	vec_norm(ray);
	free(temp);
	if (*t0 < 1)
		*t0 = t1;
	if (*t0 > 1)
		return (1);
	else
		return (0);
}

int		intersect_plane(t_camera *cam, t_obj *plane, t_vec *ray, double *t)
{
	t_vec	*x;
	double	xv;
	double	dv;

	dv = vec_scal_mult(vec_norm(plane->vec), vec_norm(ray));
	if (dv < 0)
	{
		vec_mult(plane->vec, -1);
		dv = vec_scal_mult(vec_norm(plane->vec), vec_norm(ray));
	}
	if (dv > 0.00000001)
	{
		x = vec_sub(plane->pos, cam->point);
		xv = vec_scal_mult(x, plane->vec);
		*t = xv / dv;
		free(x);
		if (*t > 0.0001)
			return (1);
	}
	return (0);
}

double	compute_o(t_vec *point, t_vec *p1, t_vec *p2, t_vec *vec)
{
	double	res;
	t_vec	*v1;
	t_vec	*v2;
	t_vec	*cross;

	vec_norm(vec);
	v1 = vec_sub(p1, point);
	v2 = vec_sub(p2, point);
	cross = vec_cross(v1, v2);
	res = vec_scal_mult(cross, vec);
	free(v1);
	free(v2);
	free(cross);
	return (res);
}

int		get_o(t_obj *obj, t_vec *point)
{
	double	o1;
	double	o2;
	double	o3;
	double	o4;

	o1 = compute_o(point, obj->p1, obj->p2, obj->vec);
	o2 = compute_o(point, obj->p2, obj->p3, obj->vec);
	o3 = compute_o(point, obj->p3, obj->p4, obj->vec);
	o4 = compute_o(point, obj->p4, obj->p1, obj->vec);
	if (o1 <= 0 && o2 <= 0 && o3 <= 0 && o4 <= 0)
		return (1);
	if (o1 >= 0 && o2 >= 0 && o3 >= 0 && o4 >= 0)
		return (1);
	return (0);
}

int		intersect_square(t_camera *cam, t_obj *obj, t_vec *ray, double *t)
{
	t_vec	*point;
	double	r;

	vec_norm(obj->vec);
	r = 0;
	if (!intersect_plane(cam, obj, ray, &r))
	{
		return (0);
	}
	vec_norm(ray);
	point = vec_sum(cam->point, vec_mult(ray, r));
	vec_norm(ray);
	if (get_o(obj, point))
	{
		free(point);
		if (r)
		{
			*t = r;
			return (1);
		}
	}
	free(point);
	return (0);
}
