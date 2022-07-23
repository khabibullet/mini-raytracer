/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nearest_colisions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:26:38 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/23 22:16:05 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/collision.h"

void	get_nearest_collisions(t_minirt *rt)
{
	int			i;
	int			j;

	i = 0;
	while (i < rt->screen.heigth)
	{
		j = 0;
		while (j < rt->screen.width)
		{
			current_ray_nearest_collision(&rt->screen.rays[i][j], &rt->scene);
			j++;
		}
		i++;
	}
}
