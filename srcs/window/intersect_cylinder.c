/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:56:36 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 14:38:36 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*get_d(t_vec *vec, t_vec *pos, t_vec *point)
{
	t_vec	*v;
	t_vec	*d;
	double	m;

	vec_norm(vec);
	v = vec_sub(point, pos);
	m = vec_scal_mult(v, vec) / vec_scal_mult(vec, vec);
	d = vec_sum(pos, vec_mult(vec, m));
	vec_norm(vec);
	free(v);
	return (d);
}

t_vec	*norm_cylinder(t_vec *point, t_vec *pos, t_vec *vec)
{
	t_vec	*norm;
	t_vec	*d;

	d = get_d(vec, pos, point);
	norm = vec_sub(point, d);
	free(d);
	vec_norm(norm);
	return (norm);
}

int		in_height(t_camera *o, t_obj *obj, t_vec *ray, double *t)
{
	t_vec	*p;
	t_vec	*vec;
	double	len;
	double	comp;

	if (*t < 0)
		return (0);
	vec_norm(ray);
	p = vec_sum(o->point, vec_mult(ray, *t));
	vec = vec_sub(p, obj->pos);
	len = vec_len(vec);
	comp = sqrt(pow(len, 2) - pow((obj->d / 2), 2));
	free(vec);
	free(p);
	vec_norm(ray);
	if (comp <= obj->h)
		return (1);
	else
		return (0);
}

void	init_coef(t_vec *ray, t_obj *obj, t_vec *coef, t_camera *cam)
{
	t_vec *x;

	vec_norm(obj->vec);
	vec_norm(ray);
	x = vec_sub(cam->point, obj->pos);
	coef->x = vec_scal_mult(ray, ray)
	- pow(vec_scal_mult(ray, obj->vec), 2);
	coef->y = 2 * (vec_scal_mult(ray, x) -
	vec_scal_mult(ray, obj->vec) * vec_scal_mult(x, obj->vec));
	coef->z = vec_scal_mult(x, x) -
	pow(vec_scal_mult(x, obj->vec), 2) - pow((obj->d / 2), 2);
	free(x);
}

int		intersect_cylinder(t_camera *cam, t_obj *obj, t_vec *ray, double *t0)
{
	t_vec	coef;
	double	t1;

	init_coef(ray, obj, &coef, cam);
	solvequadratic(coef, t0, &t1);
	vec_norm(ray);
	if (*t0 < 1)
		*t0 = t1;
	if (*t0 > 1)
		if (in_height(cam, obj, ray, t0))
		{
			vec_norm(ray);
			return (1);
		}
	if ((t1 > 0.0001) && in_height(cam, obj, ray, &t1))
	{
		vec_norm(ray);
		*t0 = t1;
		return (1);
	}
	return (0);
}
