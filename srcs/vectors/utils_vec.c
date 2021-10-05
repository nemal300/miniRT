/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_vec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:56:25 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 14:35:21 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*vec_fill(double x, double y, double z)
{
	t_vec	*vec;

	if (!(vec = (t_vec *)malloc(sizeof(t_vec))))
		return (0);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

double	vec_len(t_vec *vec)
{
	double	len;

	len = sqrtf(powf(vec->x, 2) + powf(vec->y, 2) + powf(vec->z, 2));
	return (len);
}

t_vec	*vec_norm(t_vec *vec)
{
	double len;

	len = 0;
	len = sqrtf(powf(vec->x, 2) + powf(vec->y, 2) + powf(vec->z, 2));
	vec->x = vec->x / len;
	vec->y = vec->y / len;
	vec->z = vec->z / len;
	return (vec);
}

t_vec	*vec_mult(t_vec *vec, double multiplier)
{
	vec->x = vec->x * multiplier;
	vec->y = vec->y * multiplier;
	vec->z = vec->z * multiplier;
	return (vec);
}

t_vec	*vec_cross(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = vec_fill(0, 0, 0);
	if (!res)
		return (0);
	res->x = vec1->y * vec2->z - vec1->z * vec2->y;
	res->y = vec1->z * vec2->x - vec1->x * vec2->z;
	res->z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (res);
}
