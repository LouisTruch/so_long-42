/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:14:32 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:59:43 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	get_game_map(t_game *game, int fd)
{
	char	*line;
	char	*map_cpy;
	char	*tmp;

	map_cpy = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strdup(map_cpy);
		free (map_cpy);
		map_cpy = ft_strjoin(tmp, line);
		free (line);
		free (tmp);
		line = get_next_line(fd);
	}
	game->map = ft_split(map_cpy, '\n');
	if (!game->map)
		return ;
	free (map_cpy);
}

int	count_map_collectible(char **map)
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

void	find_map_collectibles(t_game *game)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	while (game->map[++x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'C')
			{
				game->coll_pos[i] = ft_calloc(sizeof(int), 2);
				if (!game->coll_pos[i])
					return ;
				game->coll_pos[i][0] = x;
				game->coll_pos[i][1] = y;
				i++;
			}
			y++;
		}
	}
	return ;
}

void	count_empty_space(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->empty_space = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '0')
				game->empty_space += 1;
			y++;
		}
		x++;
	}
}
