/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:54:55 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:16:15 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_color(t_color *color)
{
	if (color)
		free(color);
	color = 0;
}

void	free_vec(t_vec *vec)
{
	if (vec)
		free(vec);
	vec = 0;
}

void	free_amb(t_amb *amb)
{
	if (amb)
		free_color(amb->ambient_color);
	amb = 0;
}

void	free_res(t_res *res)
{
	free(res);
	res = 0;
}

void	free_light(t_light **light)
{
	t_light *temp;
	t_light *next;

	next = *light;
	while (next)
	{
		temp = next;
		next = next->next;
		free_color(temp->color);
		free_vec(temp->point);
		free(temp);
	}
	*light = 0;
}
