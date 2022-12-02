/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_check_move_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:52:25 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 13:29:25 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

/* Check every cell around enemy to count how many possibilities it has       */

int	check_enemy_surrounding_left_right(t_game *game, int nb_moves)
{
	if (game->map[game->enemy_pos[0]][game->enemy_pos[1] - 1] == '0' ||
			game->map[game->enemy_pos[0]][game->enemy_pos[1] - 1] == 'P')
	{
		nb_moves += 1;
		game->enemy_moves[2] = 1;
	}
	else
		game->enemy_moves[2] = 0;
	if (game->map[game->enemy_pos[0]][game->enemy_pos[1] + 1] == '0' ||
			game->map[game->enemy_pos[0]][game->enemy_pos[1] + 1] == 'P')
	{
		nb_moves += 1;
		game->enemy_moves[3] = 1;
	}
	else
		game->enemy_moves[3] = 0;
	return (nb_moves);
}

int	check_enemy_surrounding_up_down(t_game *game)
{
	int	nb_moves;

	nb_moves = 0;
	if (game->map[game->enemy_pos[0] - 1][game->enemy_pos[1]] == '0' ||
			game->map[game->enemy_pos[0] - 1][game->enemy_pos[1]] == 'P')
	{
		nb_moves += 1;
		game->enemy_moves[0] = 1;
	}
	else
		game->enemy_moves[0] = 0;
	if (game->map[game->enemy_pos[0] + 1][game->enemy_pos[1]] == '0' ||
			game->map[game->enemy_pos[0] + 1][game->enemy_pos[1]] == 'P')
	{
		nb_moves += 1;
		game->enemy_moves[1] = 1;
	}
	else
		game->enemy_moves[1] = 0;
	return (check_enemy_surrounding_left_right(game, nb_moves));
}
