/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sqr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:33 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/29 23:30:34 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	*get_perpen(t_obj *square)
{
	t_vec *vec;
	t_vec *temp;

	temp = vec_fill(0, 1, 0);
	vec = vec_cross(square->vec, temp);
	if (vec->x == 0 && vec->y == 0 && vec->z == 0)
	{
		free(temp);
		free(vec);
		vec_fill(1, 0, 0);
		vec = vec_cross(square->vec, temp);
		vec_norm(vec);
		return (vec);
	}
	free(temp);
	vec_norm(vec);
	return (vec);
}

void	get_points(t_obj *square)
{
	t_vec	*perpen;
	double	temp;
	t_vec	*ttemp;

	temp = square->d / sqrt(2);
	perpen = get_perpen(square);
	vec_mult(perpen, temp);
	square->p1 = vec_sum(square->pos, perpen);
	vec_mult(perpen, -1);
	square->p3 = vec_sum(square->pos, perpen);
	ttemp = vec_cross(perpen, square->vec);
	vec_norm(ttemp);
	vec_mult(ttemp, temp);
	square->p2 = vec_sum(square->pos, ttemp);
	vec_mult(ttemp, -1);
	square->p4 = vec_sum(square->pos, ttemp);
	free(ttemp);
	free(perpen);
}

t_obj	*new_square(char **split)
{
	t_obj *square;

	if (!(square = init_obj()))
		return (0);
	square->type = SQ;
	if (!(square->pos = parse_vec(split[1])))
		return (0);
	if (!(square->vec = parse_vec(split[2])))
		return (0);
	if (!limit_vec(square->vec))
		return (0);
	if (!(square->d = ft_atof(split[3])))
		return (0);
	if (!(square->color = parse_color(split[4])))
		return (0);
	vec_norm(square->vec);
	get_points(square);
	return (square);
}

int		parse_square(t_scene *scene, char **split, int count)
{
	t_obj *square;

	if (count != 5)
		return (0);
	square = new_square(split);
	if (!square)
		return (0);
	ft_lstadd_back_obj(&(scene->obj), square);
	return (1);
}
