/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 22:57:13 by kbulwer           #+#    #+#             */
/*   Updated: 2021/10/05 17:03:29 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "minirt.h"

void	my_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel) / 8);
	*(unsigned int*)dst = color;
}

int		create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int		render(t_mlxwin *mlxwin)
{
	int		x;
	int		y;
	t_color	*color;
	int		colint;

	y = 0;
	while (y < mlxwin->scene->res->y)
	{
		x = -1;
		while (++x < mlxwin->scene->res->x)
		{
			if (!(color = trace(x, y, mlxwin->scene)))
				continue;
			colint = create_trgb(color->r, color->g, color->b);
			my_put_pixel(mlxwin->img, x, y,
			create_trgb(color->r, color->g, color->b));
			free(color);
			color = 0;
		}
		y++;
	}
	return (0);
}
