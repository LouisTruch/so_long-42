/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:07:51 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/19 19:13:46 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "../../parsing/parsing.h"

void	initialise_map(char *file, t_game *game)
{
	int		fd;

	fd = open(file, O_RDONLY);
	get_game_map(game, fd);
	game->length = ft_strlen(game->map[0]);
	game->width = ft_map_len(game->map);
	game->collectible = count_map_collectible(game->map);
	game->coll_max = count_map_collectible(game->map);
	game->coll_pos = ft_calloc(sizeof(int *), game->collectible);
	game->player_pos = ft_calloc(sizeof(int), 2);
	if (!game->coll_pos || !game->player_pos)
		return ;
	find_map_collectibles(game);
	count_empty_space(game);
	game->moves = 0;
	game->character = 0;
	game->percent_fbool = 0;
	game->c_moves = ft_calloc(0, 0);
}

void	initialise_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->length * 64, (game->width * 64) + 64, "MY GAME");
}
