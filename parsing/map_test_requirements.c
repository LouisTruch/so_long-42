/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_requirements.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:51:53 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 17:52:12 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_test_requirements(char **map)
{
	int	x;
	int	y;
	int	min[3];

	x = 0;
	min[0] = 0;
	min[1] = 0;
	min[2] = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y++])
		{
			if (map[x][y] == 'E')
				min[0] += 1;
			if (map[x][y] == 'P')
				min[1] += 1;
			if (map[x][y] == 'C')
				min[2] += 1;
		}
		x++;
	}
	if (min[0] != 1 || min[1] != 1 || min[2] < 1)
		return (0);
	return (1);
}
