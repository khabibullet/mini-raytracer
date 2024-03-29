/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 21:46:07 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/14 23:16:41 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INITIALIZATION_H
# define INITIALIZATION_H

# include "minirt.h"
# include "utils.h"
# include "../libraries/libft/libft.h"
# define BULB 1

void	initialize_raytracing(t_minirt *minirt);
void	set_screen_properties(t_screen *screen, int heigth, int width);
void	init_window_and_buffers(t_minirt *rt);
void	init_pixels(t_minirt *rt);
void	init_rays(t_minirt *rt);
void	init_controls(t_minirt *rt);
void	init_scene(t_minirt *rt);

#endif