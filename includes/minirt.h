/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbulwer <kbulwer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 15:21:18 by kbulwer           #+#    #+#             */
/*   Updated: 2021/03/31 15:50:41 by kbulwer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define BUFFER_SIZE	50
# define SP				1
# define PL				2
# define SQ				3
# define CY				4
# define TR				5

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "structs.h"

/*
** gnl
*/
int			get_next_line(int fd, char **line);
char		*str_join(char *temp, char *buf);
char		**ft_splitf(char const *s);
char		*str_sub(char *s);
char		*str_rem(char *s);
int			error_handler(char *s);

/*
** utils
*/
int			count_words(char *line);
int			ft_strcmp(char *s1, char *s2);
double		ft_atof(char *str);
int			ft_isspacew(int c);
int			check_float(char *line);
int			check_dot(char *line);

/*
** parse_environment
*/
int			parse_cameras(t_scene *scene, char **split, int count);
int			parse_resolution(t_scene **scene, char **split, int count);
int			parse_ambient(t_scene **scene, char **split, int count);
int			parse_light(t_scene *scene, char **split, int count);
int			parse_sphere(t_scene *scene, char **split, int count);
int			parse_plane(t_scene *scene, char **split, int count);
int			parse_square(t_scene *scene, char **split, int count);
int			parse_triangle(t_scene *scene, char **split, int count);
t_light		*new_light(char **split);

/*
** parse_objs
*/
t_scene		*parser(int fd);
t_color		*parse_color(char *line);
t_scene		*init_scene(void);
t_amb		*init_amb(void);
t_camera	*init_camera(void);
t_light		*init_light(void);
t_obj		*init_obj(void);
t_vec		*init_vec(void);
t_color		*init_color(void);
t_vec		*parse_vec(char *s);
t_color		*create_color(t_color *color);

void		ft_lstadd_back_cam(t_camera **camera, t_camera *newcamera);
void		ft_lstadd_back_light(t_light **light, t_light *newlight);
void		ft_lstadd_back_obj(t_obj **obj, t_obj *newobj);
void		ft_lstadd_front_obj(t_obj **obj, t_obj *newobj);

void		free_color(t_color *color);
void		free_amb(t_amb *amb);
void		free_res(t_res *res);
t_scene		*free_scene(t_scene *scene);
void		free_split(char **split);
void		free_obj(t_obj **obj);
void		free_camera(t_camera **camera);
void		free_vec(t_vec *vec);
void		free_color(t_color *color);
void		free_light(t_light **light);

/*
** vectors
*/
t_vec		*get_forward(t_camera *camera);
t_vec		*get_right(t_vec *forward);
t_vec		*get_up(t_vec *forward, t_vec *right);
t_vec		*vec_fill(double x, double y, double z);
t_vec		*vec_norm(t_vec *vec);
t_vec		*vec_mult(t_vec *vec, double multiplier);
t_vec		*vec_cross(t_vec *vec1, t_vec *vec2);
double		vec_scal_mult(t_vec *v1, t_vec *v2);
t_vec		*vec_sub(t_vec *vec1, t_vec *vec2);
t_vec		*vec_sum(t_vec *vec1, t_vec *vec2);
double		vec_len(t_vec *vec);
double		vec_calculate_cos(t_vec *vec1, t_vec *vec2);
t_vec		*compute_norm(t_obj *obj, t_vec *point, t_vec *ray);
t_vec		*norm_cylinder(t_vec *point, t_vec *pos, t_vec *vec);

/*
** window
*/
int			render(t_mlxwin *mlxwin);
int			create_trgb(int r, int g, int b);
void		my_put_pixel(t_data *data, int x, int y, int color);
void		save_bmp(t_mlxwin *mlxwin);
t_color		*trace(int x, int y, t_scene *scene);
int			limit_vec(t_vec *vec);

double		**lookat(t_camera *camera);
t_vec		*mat_mult_vec(double **mat, t_vec *vec);

t_obj		*search_first_obj(t_obj *obj, t_vec *ray, t_camera *cam, double *t);
t_obj		*search_shadow(t_obj *obj, t_vec *ray, t_camera *cam, double *t);
double		solvequadratic(t_vec coef, double *t0, double *t1);
int			intersect_sphere(t_camera *camera, t_obj *obj,
			t_vec *ray, double *t0);
int			intersect_plane(t_camera *cam, t_obj *obj, t_vec *ray, double *t);
int			intersect_square(t_camera *cam, t_obj *obj, t_vec *ray, double *t);
int			intersect_triangle(t_camera *cam, t_obj *obj,
			t_vec *ray, double *t);
int			intersect_cylinder(t_camera *cam, t_obj *obj,
			t_vec *ray, double *t0);
int			parse_cylinder(t_scene *scene, char **split, int count);
t_color		*compute_light(t_scene *scene, t_obj *obj, t_vec *ray, double t);

double		compute_o(t_vec *point, t_vec *p1, t_vec *p2, t_vec *vec);

int			ft_close(t_mlxwin *mlxwin);
void		new_render(t_mlxwin *mlxwin);
void		switch_camera(t_mlxwin *mlxwin);
int			key_hook(int key, t_mlxwin *mlxwin);

#endif
