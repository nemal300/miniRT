/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:36 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:19:33 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_triangle_norm(t_obj *triangle)
{
	t_vec *vec1;
	t_vec *vec2;

	vec1 = vec_sub(triangle->p3, triangle->p2);
	vec2 = vec_sub(triangle->p2, triangle->p1);
	triangle->vec = vec_cross(vec1, vec2);
	free(vec1);
	free(vec2);
	return ;
}

t_obj	*new_triangle(char **split)
{
	t_obj *triangle;

	if (!(triangle = init_obj()))
		return (0);
	triangle->type = TR;
	if (!(triangle->p1 = parse_vec(split[1])))
		return (0);
	if (!(triangle->p2 = parse_vec(split[2])))
		return (0);
	if (!(triangle->p3 = parse_vec(split[3])))
		return (0);
	if (!(triangle->color = parse_color(split[4])))
		return (0);
	get_triangle_norm(triangle);
	return (triangle);
}

int		parse_triangle(t_scene *scene, char **split, int count)
{
	t_obj *triangle;

	if (count != 5)
		return (0);
	triangle = new_triangle(split);
	if (!triangle)
		return (0);
	ft_lstadd_back_obj(&(scene->obj), triangle);
	return (1);
}
