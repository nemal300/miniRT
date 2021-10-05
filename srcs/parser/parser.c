/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:55:44 by kbulwer           #+#    #+#             */
/*   Updated: 2021/10/05 23:09:20 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "libft.h"
#include "mlx.h"

int		parse_splitted(t_scene **scene, char **split, int count)
{
	if (count < 3)
		return (0);
	else if (ft_strcmp(split[0], "R") == 0)
		return (parse_resolution(scene, split, count));
	else if (ft_strcmp(split[0], "A") == 0)
		return (parse_ambient(scene, split, count));
	else if (ft_strcmp(split[0], "c") == 0)
		return (parse_cameras((*scene), split, count));
	else if (ft_strcmp(split[0], "l") == 0)
		return (parse_light((*scene), split, count));
	else if (ft_strcmp(split[0], "sp") == 0)
		return (parse_sphere((*scene), split, count));
	else if (ft_strcmp(split[0], "pl") == 0)
		return (parse_plane((*scene), split, count));
	else if (ft_strcmp(split[0], "sq") == 0)
		return (parse_square((*scene), split, count));
	else if (ft_strcmp(split[0], "tr") == 0)
		return (parse_triangle((*scene), split, count));
	else if (ft_strcmp(split[0], "cy") == 0)
		return (parse_cylinder((*scene), split, count));
	return (0);
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int		line_processing(int check, char *line, t_scene *scene, char **split)
{
	if (!line)
		return (0);
	while (ft_isspace(*line))
		line++;
	if (*line == 0)
		return (1);
	split = ft_splitf(line);
	check = count_words(line);
	check = parse_splitted(&scene, split, check);
	free_split(split);
	if (check == 0)
		return (0);
	return (1);
}

t_scene	*parser(int fd)
{
	t_scene	*scene;
	char	**split;
	char	*line;
	int		check;

	scene = init_scene();
	split = NULL;
	while ((check = get_next_line(fd, &line)) > 0)
	{
		if (!(line_processing(check, line, scene, split)))
			return (free_scene(scene));
		free(line);
	}
	if (!(line_processing(check, line, scene, split)))
		return (free_scene(scene));
	free(line);
	if (!(scene->camera) || !(scene->amb) || !(scene->res->y))
		return (free_scene(scene));
	scene->hw = (double)scene->res->y / scene->res->x;
	scene->wh = (double)scene->res->x / scene->res->y;
	scene->main_cam = scene->camera;
	return (scene);
}
