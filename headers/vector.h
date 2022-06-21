/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:59:29 by anemesis          #+#    #+#             */
/*   Updated: 2022/06/19 21:25:00 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include "minirt.h"

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}	t_vec;

float	dot_product(t_vec vec1, t_vec vec2);
float	vector_len(t_vec vec);
t_vec	unit_vector(t_vec vec);

#endif