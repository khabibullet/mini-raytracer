/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_normal_ver.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:30:10 by enoye             #+#    #+#             */
/*   Updated: 2022/08/07 13:02:54 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/vector.h"

inline t_vec	find_normal_ver(t_vec *vec)
{
	t_vec	var;

	var.x = vec->x * vec->z;
	var.y = vec->y * vec->z;
	var.z = -(vec->x * vec->x + vec->y * vec->y);
	return (unit_vector(var));
}
