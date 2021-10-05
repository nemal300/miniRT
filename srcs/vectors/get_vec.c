/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:30:11 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:42:46 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*get_forward(t_camera *camera)
{
	t_vec	*forward;

	if (camera->vec->x == 0 && camera->vec->z == 0
	&& (camera->vec->y == 1 || camera->vec->y == -1))
		camera->vec->x = 0.001;
	forward = vec_fill(camera->vec->x, camera->vec->y, camera->vec->z);
	vec_norm(forward);
	vec_mult(forward, -1);
	return (forward);
}

t_vec	*get_right(t_vec *forward)
{
	t_vec	*right;
	t_vec	*temp;

	temp = vec_fill(0, 1, 0);
	vec_norm(temp);
	right = vec_cross(temp, forward);
	free(temp);
	vec_norm(right);
	return (right);
}

t_vec	*get_up(t_vec *forward, t_vec *right)
{
	t_vec	*up;

	up = vec_cross(forward, right);
	vec_norm(up);
	return (up);
}
