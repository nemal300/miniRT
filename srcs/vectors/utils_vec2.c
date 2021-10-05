/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:56:28 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/30 20:36:50 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vec_scal_mult(t_vec *v1, t_vec *v2)
{
	double	res;

	res = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	return (res);
}

t_vec	*vec_sum(t_vec *vec1, t_vec *vec2)
{
	t_vec	*vec;

	vec = init_vec();
	if (!vec)
		return (0);
	vec->x = vec1->x + vec2->x;
	vec->y = vec1->y + vec2->y;
	vec->z = vec1->z + vec2->z;
	return (vec);
}

t_vec	*vec_sub(t_vec *vec1, t_vec *vec2)
{
	t_vec	*vec;

	vec = init_vec();
	if (!vec)
		return (0);
	vec->x = vec1->x - vec2->x;
	vec->y = vec1->y - vec2->y;
	vec->z = vec1->z - vec2->z;
	return (vec);
}

double	vec_calculate_cos(t_vec *vec1, t_vec *vec2)
{
	double	res;
	double	len;

	res = vec_scal_mult(vec1, vec2);
	len = vec_len(vec1) * vec_len(vec2);
	return (res / len);
}

t_vec	*compute_norm(t_obj *obj, t_vec *point, t_vec *ray)
{
	t_vec	*norm;

	norm = 0;
	if (obj->type == SP)
		norm = vec_sub(point, obj->pos);
	else if (obj->type == PL)
		norm = vec_fill(obj->vec->x, obj->vec->y, obj->vec->z);
	else if (obj->type == SQ)
		norm = vec_fill(obj->vec->x, obj->vec->y, obj->vec->z);
	else if (obj->type == TR)
		norm = vec_fill(obj->vec->x, obj->vec->y, obj->vec->z);
	else if (obj->type == CY)
		norm = norm_cylinder(point, obj->pos, obj->vec);
	vec_norm(norm);
	if (vec_calculate_cos(norm, ray) > 0)
		vec_mult(norm, -1);
	return (norm);
}
