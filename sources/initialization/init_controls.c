/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 20:34:58 by anemesis          #+#    #+#             */
/*   Updated: 2022/09/15 15:41:44 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/initialization.h"

void	init_controls(t_minirt *rt)
{
	rt->controls = (t_ctrl){0, 0, 0, 1.0F, 0, 0, 0, 0};
	rt->insert_mode = 0;
}
