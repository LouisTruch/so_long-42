/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_path_collectible.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:47:03 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:39:12 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	test_path_to_collectibles(char **map, char **cpy)
{
	int	i;
	int	**coll;

	i = 0;
	coll = ft_calloc(sizeof(int *), (count_map_collectibles(map)));
	if (!coll)
		return (0);
	find_collectibles(map, &coll);
	while (i < count_map_collectibles(map))
	{
		if (cpy[coll[i][0]][coll[i][1]] != '2')
		{
			ft_free_parsing(map, cpy, coll);
			return (0);
		}
		i++;
	}
	ft_free_parsing(map, cpy, coll);
	return (1);
}

int	count_map_collectibles(char **map)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	count = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C')
				count++;
			y++;
		}
		x++;
	}
	return (count);
}

int	**find_collectibles(char **map, int ***coll)
{
	int	x;
	int	y;
	int	i;

	x = -1;
	i = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (map[x][y] == 'C')
			{
				(*coll)[++i] = ft_calloc(sizeof(int), 2);
				if (!(*coll)[i])
					return (0);
				(*coll)[i][0] = x;
				(*coll)[i][1] = y;
			}
		}
	}
	return (*coll);
}
