/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:28:28 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 17:40:55 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**map_copy(int fd)
{
	char	*line;
	char	*map_cpy;
	char	*tmp;
	char	**map;

	map_cpy = ft_strdup("");
	line = get_next_line(fd);
	if (line == NULL)
		exit_empty_map(line, map_cpy);
	while (line)
	{
		tmp = ft_strdup(map_cpy);
		free (map_cpy);
		map_cpy = ft_strjoin(tmp, line);
		free (line);
		free (tmp);
		line = get_next_line(fd);
	}
	map = ft_split(map_cpy, '\n');
	if (!map)
		return (0);
	free (map_cpy);
	return (map);
}

void	exit_empty_map(char *line, char *map)
{
	free (line);
	free (map);
	ft_printf(RED"Error\nMap file is empty\n"NC);
	exit (0);
}
