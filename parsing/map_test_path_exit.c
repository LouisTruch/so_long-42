/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_path_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:40:34 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:27:32 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	find_start(char **map, int *x, int *y)
{
	*x = 0;
	while (map[*x])
	{
		*y = 0;
		while (map[*x][*y])
		{
			if (map[*x][*y] == 'P')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}

int	test_path_to_exit(char **map, char **cpy)
{
	int	x;
	int	y;

	find_map_exit(map, &x, &y);
	if (cpy[x][y] == '2')
		return (1);
	return (0);
}

void	find_map_exit(char **map, int *x, int *y)
{
	*x = 0;
	while (map[*x])
	{
		*y = 0;
		while (map[*x][*y])
		{
			if (map[*x][*y] == 'E')
				return ;
			(*y)++;
		}
		(*x)++;
	}
}
