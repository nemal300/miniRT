/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:56:22 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/30 18:40:56 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*mat_mult_vec(double **mat, t_vec *vec)
{
	t_vec	*res;

	res = init_vec();
	if (!res)
		return (0);
	res->x = vec->x * mat[0][0] + vec->y * mat[1][0] + vec->z * mat[2][0];
	res->y = vec->x * mat[0][1] + vec->y * mat[1][1] + vec->z * mat[2][1];
	res->z = vec->x * mat[0][2] + vec->y * mat[1][2] + vec->z * mat[2][2];
	return (res);
}

double	**lookat(t_camera *camera)
{
	double	**matrix;
	int		i;

	if (!(matrix = (double **)malloc(sizeof(double *) * 3)))
		return (0);
	i = 0;
	while (i < 3)
	{
		matrix[i] = (double *)malloc(sizeof(double) * 3);
		i++;
	}
	camera->forward = get_forward(camera);
	camera->right = get_right(camera->forward);
	camera->up = get_up(camera->forward, camera->right);
	matrix[0][0] = camera->right->x;
	matrix[0][1] = camera->right->y;
	matrix[0][2] = camera->right->z;
	matrix[1][0] = camera->up->x;
	matrix[1][1] = camera->up->y;
	matrix[1][2] = camera->up->z;
	matrix[2][0] = camera->forward->x;
	matrix[2][1] = camera->forward->y;
	matrix[2][2] = camera->forward->z;
	return (matrix);
}
