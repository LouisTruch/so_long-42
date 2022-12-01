/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:50:55 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:19:53 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_test_wall(char **map)
{
	int	x;
	int	y;
	int	last_line;
	int	last_col;

	last_line = count_map_line(map) - 1;
	last_col = ft_strlen(map[0]) - 1;
	y = 0;
	while (map[0][y])
	{
		if (map[0][y] != '1' || map[last_line][y] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (map[x])
	{
		if (map[x][0] != '1' || map[x][last_col] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	count_map_line(char **map)
{
	int	k;

	k = 0;
	while (map[k])
		k++;
	return (k);
}
