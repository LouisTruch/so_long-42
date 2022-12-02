/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:39:51 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:52:01 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

/* Check if player is on a collectible, update game->collectible and %       *
 * and update game->map                                                      */

void	check_player_pos_coll(t_game *game)
{
	if (game->map[game->player_pos[0]][game->player_pos[1]] == 'C')
	{
		game->map[game->player_pos[0]][game->player_pos[1]] = '0';
		game->collectible -= 1;
		game->percent_picked
			= (game->coll_max - game->collectible) * 100 / game->coll_max;
	}
}

/* Check if player is on exit, if he is check                                *
 * if he has all collectible then exit                                       */

void	check_player_pos_exit(t_game *game)
{
	if (game->map[game->player_pos[0]][game->player_pos[1]] == 'E')
	{
		if (game->collectible == 0)
			ft_exit(game);
	}
}

/* Compare player_pos with enemy_pos, if they are the same, game ends         */

void	check_player_death(t_game *game)
{
	if (game->player_pos[0] == game->enemy_pos[0]
		&& game->player_pos[1] == game->enemy_pos[1])
	{
		ft_printf(RED"YOU LOST\n"NC);
		ft_exit(game);
	}
}
