/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press_release.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:16:23 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/11 21:25:04 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/event.h"

int	mouse_press(int button, int x, int y, t_minirt *rt)
{
	if (button != 1)
		return (0);
	mlx_mouse_hide();
	if ((y <= 50 || y > rt->screen.heigth) && (x <= 0 || x > rt->screen.width))
		return (0);
	rt->controls.mouse_press = 1;
	rt->controls.motion++;
	return (0);
}

int	mouse_release(int button, int x, int y, t_minirt *rt)
{
	if (button != 1)
		return (0);
	mlx_mouse_show();
	if ((y <= 50 || y > rt->screen.heigth) && (x <= 0 || x > rt->screen.width))
		return (0);
	rt->controls.motion--;
	rt->controls.mouse_press = 0;
	return (0);
}
