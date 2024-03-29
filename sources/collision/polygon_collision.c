/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon_collision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 17:51:41 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/15 18:34:38 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"
#include "../../headers/ray.h"

/**
**	"Fast, Minimum Storage Ray-Triangle Intersection" algorithm
**	by Moller and Trumbore
**/

static inline void	init_basic(t_poly *poly, t_vec ab_ac[2], t_vec *n)
{
	ab_ac[0] = subtract_vecs(&poly->peak2, &poly->peak1);
	ab_ac[1] = subtract_vecs(&poly->peak3, &poly->peak1);
	*n = cross_product(&ab_ac[0], &ab_ac[1]);
}

static inline void	update_collision(t_collision *collis, void *poly, \
														float distance, t_vec n)
{
	collis->surface = (void *)poly;
	collis->distance = distance;
	collis->surf_normal = n;
	collis->surf_type = POLY;
}

static inline void	check_normal(float *denom, t_vec *n, t_vec ab_ac[2])
{
	if (*denom > 0)
	{
		*n = (t_vec){-n->x, -n->y, -n->z};
		*denom = -*denom;
		ab_ac[0] = (t_vec){-ab_ac[0].x, -ab_ac[0].y, -ab_ac[0].z};
		ab_ac[1] = (t_vec){-ab_ac[1].x, -ab_ac[1].y, -ab_ac[1].z};
	}
}

int	collide_poly(t_ray *ray, t_poly *poly, int mode)
{
	t_vec	n;
	t_vec	ao;
	t_vec	ab_ac[2];
	float	t_u_v[3];
	float	denom;

	init_basic(poly, ab_ac, &n);
	denom = dot_product(ray->coords, n);
	check_normal(&denom, &n, ab_ac);
	if (denom == 0)
		return (0);
	denom = 1.0F / denom;
	ao = subtract_vecs(&ray->origin, &poly->peak1);
	t_u_v[0] = -denom * dot_product(ao, n);
	t_u_v[1] = denom * mix_product(&ray->coords, &ao, &ab_ac[1]);
	t_u_v[2] = denom * mix_product(&ray->coords, &ab_ac[0], &ao);
	if (t_u_v[0] <= 0.0F || t_u_v[1] < 0.0F || t_u_v[2] < 0.0F \
			|| (t_u_v[1] + t_u_v[2]) > 1.0F \
			|| t_u_v[0] - EPSILON >= ray->collis.distance)
		return (0);
	if (mode == FAST)
		return (1);
	update_collision(&ray->collis, (void *)poly, t_u_v[0] - EPSILON, n);
	return (1);
}
