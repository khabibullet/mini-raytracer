/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:32:25 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/24 00:17:46 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "collision.h"
# include "ray.h"

typedef struct s_color		t_color;
typedef struct s_vec		t_vec;
typedef struct s_color		t_color;
typedef struct s_cam		t_cam;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_plane		t_plane;
typedef struct s_poly		t_poly;
typedef struct s_num		t_num;

typedef struct s_sphere
{
	int		id;
	t_color	color;
	t_vec	center;
	float	radius;
}	t_sphere;

typedef struct s_cam
{
	t_vec	coords;
	t_vec	direction;
	int		fov;
	float	focal;
}	t_cam;

typedef struct s_cyl
{
	int		id;
	t_color	color;
	t_vec	center;
	t_vec	axis;
	float	radius;
	float	heigth;
	float	rot[3][3];
	float	rev[3][3];
}	t_cyl;

typedef struct s_plane
{
	int		id;
	t_color	color;
	t_vec	coords;
	t_vec	normal;
}	t_plane;

typedef struct s_light
{
	t_color	color;
	t_vec	coords;
	float	brightless;
}	t_light;

typedef struct s_amb
{
	t_color	color;
	float	ratio;
}	t_amb;

typedef struct s_poly
{
	int		id;
	t_color	color;
	t_vec	peak1;
	t_vec	peak2;
	t_vec	peak3;
}	t_poly;

typedef struct s_num
{
	int		primitives;
	int		planes;
	int		spheres;
	int		cylinders;
	int		polygons;
	int		lights;
}	t_num;

typedef struct s_scene
{
	t_cam			cam;
	t_cam			cam_default;
	t_color			ambient;
	t_sphere		*spheres;
	t_cyl			*cylinders;
	t_plane			*planes;
	t_poly			*polygons;
	t_light			*lights;
	t_num			num_of;
}	t_scene;

#endif