/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:45:06 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:40:10 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free (map);
}

void	ft_free_parsing(char **map, char **cpy, int **coll)
{
	int	i;
	int	x;

	x = 0;
	while (cpy[x])
	{
		free(cpy[x]);
		x++;
	}
	free(cpy);
	i = 0;
	while (i < count_map_collectibles(map))
	{
		free (coll[i]);
		i++;
	}
	free (coll);
	x = 0;
	ft_free_map(map);
}
