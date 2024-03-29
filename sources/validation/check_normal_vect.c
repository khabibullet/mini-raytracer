/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_normal_vect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 12:09:30 by enoye             #+#    #+#             */
/*   Updated: 2022/08/08 21:19:36 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"
#include "../../headers/collision.h"

void	check_normal_vect(char *line)
{
	t_vec	norm;
	char	**xyz;
	float	len;

	check_coords(line);
	xyz = ft_split(line, ',');
	norm.x = ft_atof(xyz[0]);
	norm.y = ft_atof(xyz[1]);
	norm.z = ft_atof(xyz[2]);
	free(xyz[0]);
	free(xyz[1]);
	free(xyz[2]);
	free(xyz);
	len = vector_len(&norm);
	if (len > 1.0F + EPSILON)
		exit_error("Invalid input: invalid normal vector");
}
