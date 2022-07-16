/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_all_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@clown.ru>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:32:51 by enoye             #+#    #+#             */
/*   Updated: 2022/07/07 13:23:56 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/parsing.h"
#include "../../headers/utils.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	find_elements_in_line(char *line, t_elements *elements)
{
	while (*line == ' ')
		line++;
	if (*line == 'A' && *(line + 1) == ' ')
		elements->ambient++;
	else if (*line == 'C' && *(line + 1) == ' ')
		elements->camera++;
	else if (*line == 'L' && *(line + 1) == ' ')
		elements->light++;
	else if (*line == 's' && *(line + 1) == 'p' && *(line + 2) == ' ')
		elements->object++;
	else if (*line == 'p' && *(line + 1) == 'l' && *(line + 2) == ' ')
		elements->object++;
	else if (*line == 'c' && *(line + 1) == 'y' && *(line + 2) == ' ')
		elements->object++;
	else if (*line == 'p' && *(line + 1) == 'o' && *(line + 2) == ' ')
		elements->object++;
}

static int	check_elements(t_elements *elements)
{
	if (elements->camera != 1)
	{
		printf("netu cameri, libo ih slishkom mnogo!\n");
		return (0);
	}
	if (elements->ambient == 0 && elements->light == 0)
	{
		printf("net istochnikov sveta\n");
		return (0);
	}
	if (elements->ambient > 1)
	{
		printf("ambient max = 1\n");
		return (0);
	}
	if (elements->object == 0)
	{
		printf("kak minimum 1 object na scene doljen bit\n");
		return (0);
	}
	return (1);
}

int	is_all_valid(int fd, char *name)
{
	char		*line;
	t_elements	elements;

	printf("START IS ALL VALID\n");
	line = "lol";
	elements.camera = 0;
	elements.object = 0;
	elements.light = 0;
	elements.ambient = 0;
	if (is_file_valid(name) == 0)
		return (0);
	while (line != 0)
	{
		line =  get_next_line(fd);
		if (line != 0)
		{
			find_elements_in_line(line, &elements);
			free(line);
		}
	}
	if (check_elements(&elements) == 0)
		return (0);
	line = "kek";
	close(fd);
	fd = open(name, O_RDONLY, 0644);
	while (line != 0)
	{
		line = get_next_line(fd);
		if (line != 0)
		{
			if (is_line_valid(line) == 0)
			{
				free(line);
				return (0);
			}
			free(line);
		}
	}
	close (fd);
	return (1);
}