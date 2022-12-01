/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:03:54 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:46:03 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	map_parsing(char *file)
{
	int		fd;
	char	**map;

	fd = open_map(file);
	map = map_copy(fd);
	close (fd);
	make_every_test(map, file);
}

void	make_every_test(char **map, char *file)
{
	if (map_test_rectangular(map) == 0)
	{
		ft_printf(RED"Error\nMap is not rectangular"NC);
		ft_free_map(map);
		exit (0);
	}
	if (map_test_wall(map) == 0)
	{
		ft_printf(RED"Error\nMap is not surrounded by walls"NC);
		ft_free_map(map);
		exit (0);
	}
	if (map_test_requirements(map) == 0)
	{
		ft_printf(RED"Error\nMap must have 1 exit, 1 start and 1+ collectible");
		ft_free_map(map);
		exit (0);
	}
	if (map_test_valid_path(map, file) == 0)
	{
		ft_printf(RED"Error\nMap does not contain a valid path"NC);
		exit (0);
	}
}
