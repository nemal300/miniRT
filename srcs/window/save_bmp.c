/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:16 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/30 15:27:57 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print(int fd, int value, int byte_count)
{
	char	*ptr;
	int		j;

	ptr = (char *)&value;
	j = 0;
	while (j < byte_count)
	{
		write(fd, ptr + j, 1);
		j++;
	}
}

void	fill_header(int fd, t_mlxwin *mlxwin)
{
	int	size;

	size = 300 + mlxwin->scene->res->y *
	(mlxwin->scene->res->x * mlxwin->img->bits_per_pixel / 8) + 54;
	ft_print(fd, 'B', 1);
	ft_print(fd, 'M', 1);
	ft_print(fd, size, 4);
	ft_print(fd, 0, 2);
	ft_print(fd, 0, 2);
	ft_print(fd, 0x36, 4);
	ft_print(fd, 0x28, 4);
	ft_print(fd, mlxwin->scene->res->x, 4);
	ft_print(fd, mlxwin->scene->res->y, 4);
	ft_print(fd, 1, 2);
	ft_print(fd, mlxwin->img->bits_per_pixel, 2);
	ft_print(fd, 0, 4);
	ft_print(fd, 0, 4);
	ft_print(fd, 0, 4);
	ft_print(fd, 0, 4);
	ft_print(fd, 0, 4);
	ft_print(fd, 0, 4);
}

void	save_bmp(t_mlxwin *mlxwin)
{
	int	fd;
	int	height;
	int	w;

	if ((fd = open("screen.bmp", O_CREAT | O_RDWR | O_TRUNC, 0644)) <= 0)
		ft_close(mlxwin);
	height = mlxwin->scene->res->y;
	fill_header(fd, mlxwin);
	while (height > 0)
	{
		height--;
		w = 0;
		while (w < mlxwin->scene->res->x)
		{
			write(fd, mlxwin->img->addr + (mlxwin->img->bits_per_pixel * w / 8)
			+ mlxwin->img->line_lenght
			* height, mlxwin->img->bits_per_pixel / 8);
			w++;
		}
	}
	ft_close(mlxwin);
}
