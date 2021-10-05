/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:54:51 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:11:22 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_matrix(double **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_camera(t_camera **camera)
{
	t_camera *temp;
	t_camera *next;

	next = *camera;
	while (next)
	{
		temp = next;
		next = next->next;
		free_vec(temp->point);
		free_vec(temp->vec);
		free_vec(temp->forward);
		free_vec(temp->up);
		free_vec(temp->right);
		free(temp);
		temp = 0;
	}
	*camera = 0;
}

t_scene	*free_scene(t_scene *scene)
{
	if (!scene)
		return (0);
	if (scene->res)
		free_res(scene->res);
	if (scene->amb)
		free_amb(scene->amb);
	if (scene->light)
		free_light(&(scene->light));
	if (scene->camera)
		free_camera(&(scene->camera));
	if (scene->obj)
		free_obj(&(scene->obj));
	scene = 0;
	return (0);
}

void	free_obj(t_obj **obj)
{
	t_obj *temp;
	t_obj *next;

	next = *obj;
	while (next)
	{
		temp = next;
		next = next->next;
		free_color(temp->color);
		free_vec(temp->pos);
		free_vec(temp->vec);
		free_vec(temp->p1);
		free_vec(temp->p2);
		free_vec(temp->p3);
		free_vec(temp->p4);
		free(temp);
		temp = 0;
	}
	*obj = 0;
}
