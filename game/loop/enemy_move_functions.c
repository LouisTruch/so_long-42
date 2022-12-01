/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:50:28 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/19 16:52:54 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	move_enemy(t_game *game)
{
	int	nb_moves;
	int	direction;

	game->enemy_moves = ft_calloc(sizeof(int), 4);
	if (!game->enemy_moves)
		return ;
	nb_moves = check_enemy_surrounding_up_down(game);
	direction = rand() % 4;
	while (game->enemy_moves[direction] == 0)
		direction = rand() % 4;
	if (direction == 0)
		move_enemy_up(game);
	if (direction == 1)
		move_enemy_down(game);
	if (direction == 2)
		move_enemy_left(game);
	if (direction == 3)
		move_enemy_right(game);
	free (game->enemy_moves);
}

void	move_enemy_up(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[5],
		game->enemy_pos[1] * 64, (game->enemy_pos[0] - 1) * 64);
	replace_background_enemy(game);
	game->enemy_pos[0] -= 1;
}

void	move_enemy_down(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[5],
		game->enemy_pos[1] * 64, (game->enemy_pos[0] + 1) * 64);
	replace_background_enemy(game);
	game->enemy_pos[0] += 1;
}

void	move_enemy_left(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[5],
		(game->enemy_pos[1] - 1) * 64, (game->enemy_pos[0]) * 64);
	replace_background_enemy(game);
	game->enemy_pos[1] -= 1;
}

void	move_enemy_right(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[5],
		(game->enemy_pos[1] + 1) * 64, (game->enemy_pos[0]) * 64);
	replace_background_enemy(game);
	game->enemy_pos[1] += 1;
}
