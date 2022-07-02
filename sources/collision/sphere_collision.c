/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:19:14 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/29 18:21:39 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "../../headers/ray.h"
#include "../../headers/scene.h"
#include "../../headers/vector.h"

/**
**	1)	If d (descriminant is below zero), then t1 (t[0]) and t2 (t[1]) are
**		imaginary numbers, which means ray does not intersect sphere.
**	2)	If t1 and 2 are positive numbers, then it means ray belongs the line, that
**		intersects sphere, but ray does not intersect sphere.
**		it means, that ray's origin is inside the sphere and ray intersect sphere
**		only once.
**	4)	If both t1 and t2 are positive, ray intersects sphere twice.
**/

int	collide_sphere(t_ray *ray, t_sphere *sphere)
{
	float	coeffs[3];
	float	d;
	float	t[2];
	t_vec	co;

	co = subtract_vecs(ray->origin, sphere->center);
	coeffs[0] = dot_product(ray->coords, ray->coords);
	coeffs[1] = 2 * dot_product(ray->coords, co);
	coeffs[2] = dot_product(co, co) - (sphere->radius * sphere->radius);
	d = (coeffs[1] * coeffs[1]) - (4 * coeffs[0] * coeffs[2]);
	if (d < 0)
		return (0);
	if (d == 0)
		return (add_vecs(ray->coords,
				vec_multiply_nbr(ray->origin, -coeffs[1] * coeffs[0])));
	d = sqrtf(d);
	coeffs[0] = 1 / (2.0 * coeffs[0]);
	t[0] = (-coeffs[1] + d) * coeffs[0];
	t[1] = (-coeffs[1] - d) * coeffs[0];
	if (t[0] <= 0 && t[1] <= 0)
		return (0);
	if (t[0] <= 0 || t[0] >= t[1])
		t[0] = t[1];
	return (add_vecs(ray->coords, vec_multiply_nbr(ray->origin, t[0])));
}
