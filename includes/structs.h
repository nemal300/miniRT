/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:36:27 by kbulwer           #+#    #+#             */
/*   Updated: 2021/10/05 17:35:24 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct	s_res
{
	int x;
	int y;
}				t_res;

typedef struct	s_amb
{
	double	ambint_lighting;
	t_color	*ambient_color;
}				t_amb;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

typedef struct	s_vec
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct	s_camera
{
	t_vec			*point;
	t_vec			*vec;
	double			fov;
	t_vec			*forward;
	t_vec			*up;
	t_vec			*right;
	double			**matrix;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_light
{
	t_vec			*point;
	double			brightness;
	t_color			*color;
	struct s_light	*next;
}				t_light;

typedef struct	s_obj
{
	int				type;
	t_vec			*pos;
	t_vec			*vec;
	t_color			*color;
	double			d;
	double			h;
	t_vec			*p1;
	t_vec			*p2;
	t_vec			*p3;
	t_vec			*p4;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_scene
{
	t_res		*res;
	t_amb		*amb;
	t_light		*light;
	t_camera	*camera;
	t_obj		*obj;
	t_camera	*main_cam;
	double		hw;
	double		wh;
}				t_scene;

typedef struct	s_ray
{
	t_vec	*org;
	t_vec	*dir;
}				t_ray;

typedef struct	s_mlxwin
{
	void	*mlx;
	void	*win;
	t_data	*img;
	t_scene	*scene;
}				t_mlxwin;

#endif
