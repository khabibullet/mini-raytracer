/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_hor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:23:46 by enoye             #+#    #+#             */
/*   Updated: 2022/06/21 16:38:42 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minirt.h"

t_vec	find_normal_hor(t_vec vec)
{
	t_vec	var;

	var.x = vec.y;
	var.y = -vec.x;
	var.z = 0;
	return (var);
}