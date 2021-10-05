/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 14:27:32 by kbulwer           #+#    #+#             */
/*   Updated: 2021/10/05 18:59:48 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "minirt.h"

int			ft_close(t_mlxwin *mlxwin)
{
	mlx_destroy_image(mlxwin->mlx, mlxwin->img->img);
	mlx_clear_window(mlxwin->mlx, mlxwin->win);
	mlx_destroy_window(mlxwin->mlx, mlxwin->win);
	free_scene(mlxwin->scene);
	free(mlxwin->img);
	free(mlxwin);
	mlxwin = 0;
	exit(0);
}

int			key_hook(int key, t_mlxwin *mlxwin)
{
	t_mlxwin *newwin;
	t_camera *camera;

	newwin = mlxwin;
	if (key == 49)
	{
		camera = mlxwin->scene->camera;
		camera = camera->next;
		if (!camera)
			camera = mlxwin->scene->main_cam;
		mlxwin->scene->camera = camera;
		mlx_destroy_image(mlxwin->mlx, mlxwin->img->img);
		mlxwin->img->img = mlx_new_image(mlxwin->mlx,
		mlxwin->scene->res->x, mlxwin->scene->res->y);
		mlxwin->img->addr = mlx_get_data_addr(mlxwin->img->img,
		&mlxwin->img->bits_per_pixel,
		&mlxwin->img->line_lenght, &mlxwin->img->endian);
		// render(mlxwin);
		mlx_put_image_to_window(mlxwin->mlx,
		mlxwin->win, mlxwin->img->img, 0, 0);
	}
	if (key == 53)
		ft_close(mlxwin);
	return (0);
}

t_mlxwin	*init_mlxwin(t_scene *scene)
{
	t_mlxwin	*mlxwin;
	t_data		*img;

	if (!scene)
		return (0);
	mlxwin = (t_mlxwin *)malloc(sizeof(t_mlxwin));
	if (!mlxwin)
		return (0);
	img = (t_data *)malloc(sizeof(t_data));
	if (!img)
		return (0);
	mlxwin->mlx = mlx_init();
	mlxwin->win = 0;
	img->img = mlx_new_image(mlxwin->mlx, scene->res->x, scene->res->y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_lenght, &img->endian);
	mlxwin->win = mlx_new_window(mlxwin->mlx, scene->res->x,
	scene->res->y, "miniRT");
	mlxwin->img = img;
	mlxwin->scene = scene;
	return (mlxwin);
}

int			check_filename(int *fd, char *filename)
{
	int i;

	i = 0;
	while (filename[i] && filename[i] != '.')
		i++;
	if (!filename[i])
		return (error_handler("incorrect name"));
	else if (ft_strcmp(&filename[i], ".rt"))
		return (error_handler("incorrect name"));
	else if ((*fd = open(filename, O_RDONLY)) < 0)
		return (error_handler("no open"));
	return (1);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_scene		*scene;
	t_mlxwin	*mlxwin;

	if (argc < 2 || argc > 3)
		return (error_handler("incorrect args"));
	if (!check_filename(&fd, argv[1]))
		return (error_handler("scene no open"));
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		return (error_handler("incorrect args3"));
	if (!(scene = parser(fd)))
		return (error_handler("incorrect scene"));
	mlxwin = init_mlxwin(scene);
	render(mlxwin);
	if (argc == 3 && !(ft_strcmp(argv[2], "--save")))
		save_bmp(mlxwin);
	mlx_put_image_to_window(mlxwin->mlx, mlxwin->win, mlxwin->img->img, 0, 0);
	mlx_hook(mlxwin->win, 17, 0, ft_close, mlxwin);
	mlx_key_hook(mlxwin->win, key_hook, mlxwin);
	mlx_loop(mlxwin->mlx);
	return (1);
}
