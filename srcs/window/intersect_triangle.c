/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:05 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/30 14:52:51 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_otr(t_obj *obj, t_vec *point)
{
	double	o1;
	double	o2;
	double	o3;

	o1 = compute_o(point, obj->p1, obj->p2, obj->vec);
	o2 = compute_o(point, obj->p2, obj->p3, obj->vec);
	o3 = compute_o(point, obj->p3, obj->p1, obj->vec);
	if (o1 <= 0 && o2 <= 0 && o3 <= 0)
		return (1);
	if (o1 >= 0 && o2 >= 0 && o3 >= 0)
		return (1);
	return (0);
}

int	intersect_plane_tr(t_camera *cam, t_obj *tr, t_vec *ray, double *t)
{
	t_vec	*x;
	double	xv;
	double	dv;

	dv = vec_scal_mult(vec_norm(tr->vec), vec_norm(ray));
	if (dv < 0)
	{
		vec_mult(tr->vec, -1);
		dv = vec_scal_mult(vec_norm(tr->vec), vec_norm(ray));
	}
	if (dv > 0.00000001)
	{
		x = vec_sub(tr->p1, cam->point);
		xv = vec_scal_mult(x, tr->vec);
		*t = xv / dv;
		free(x);
		if (*t > 0.0001)
			return (1);
	}
	return (0);
}

int	intersect_triangle(t_camera *cam, t_obj *obj, t_vec *ray, double *t)
{
	t_vec	*point;
	double	r;

	vec_norm(obj->vec);
	r = 0;
	if (!intersect_plane_tr(cam, obj, ray, &r))
		return (0);
	vec_norm(ray);
	point = vec_sum(cam->point, vec_mult(ray, r));
	vec_norm(ray);
	if (get_otr(obj, point))
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
