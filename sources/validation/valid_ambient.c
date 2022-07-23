/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ambient.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anemesis <anemesis@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:08:09 by enoye             #+#    #+#             */
/*   Updated: 2022/07/23 18:23:59 by anemesis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/validation.h"

void	valid_ambient(char *line)
{
	while (*line == ' ')
		line++;
	check_ratio(line);
	while (*line != ' ')
		line++;
	while (*line == ' ')
		line++;
	check_rgb(line);
	// while (*line != ' ' && *line != '\n' && *line != '\0')
	// 	line++;
	// while (*line == ' ')
	// 	line++;
	// if (*line != '\n' && *line != '\0')
	// 	exit()
}
