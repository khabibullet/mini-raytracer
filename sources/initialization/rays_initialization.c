/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 19:22:28 by anemesis          #+#    #+#             */
/*   Updated: 2022/07/16 15:15:56 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../../headers/minirt.h"
#include "../../headers/ray.h"

void	init_rays(t_minirt *rt)
{
	int	i;
	int	j;

	rt->screen.rays = malloc(sizeof(*rt->screen.rays) * rt->screen.heigth);
	i = 0;
	while (i < rt->screen.heigth)
	{
		rt->screen.rays[i] = malloc(sizeof(**rt->screen.rays) \
															* rt->screen.width);
		j = 0;
		while (i < rt->screen.width)
		{
			rt->screen.rays[i][j].collis.surface = NULL;
			rt->screen.rays[i][j].collis.distance = 1.0F / 0.0F;
			rt->screen.rays[i][j].color = (t_color){0.0F, 0.0F, 0.0F};
			j++;
		}
		i++;
	}
}
