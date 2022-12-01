/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:33:47 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:49:00 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_test_valid_path(char **map, char *file)
{
	int		x;
	int		y;
	char	**cpy;
	int		fd;

	fd = open(file, O_RDONLY);
	cpy = map_copy(fd);
	close (fd);
	find_start(map, &x, &y);
	cpy[x][y] = 'P';
	flood_fill_map(cpy);
	if (test_path_to_exit(map, cpy) == 0)
	{
		ft_free_map(map);
		ft_free_map(cpy);
		return (0);
	}
	if (test_path_to_collectibles(map, cpy) == 0)
	{
		return (0);
	}
	return (1);
}

void	flood_fill_map(char **cpy)
{
	int	x;
	int	y;

	find_start(cpy, &x, &y);
	cpy[x][y] = '2';
	if (cpy[x - 1][y] == '0' || cpy[x - 1][y] == 'C' || cpy[x - 1][y] == 'E')
	{
		cpy[x - 1][y] = 'P';
		flood_fill_map(cpy);
	}
	if (cpy[x][y + 1] == '0' || cpy[x][y + 1] == 'C' || cpy[x][y + 1] == 'E')
	{
		cpy[x][y + 1] = 'P';
		flood_fill_map(cpy);
	}
	if (cpy[x + 1][y] == '0' || cpy[x + 1][y] == 'C' || cpy[x + 1][y] == 'E')
	{
		cpy[x + 1][y] = 'P';
		flood_fill_map(cpy);
	}
	if (cpy[x][y - 1] == '0' || cpy[x][y - 1] == 'C' || cpy[x][y - 1] == 'E')
	{
		cpy[x][y - 1] = 'P';
		flood_fill_map(cpy);
	}
}
