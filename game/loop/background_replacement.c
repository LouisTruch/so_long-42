/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_replacement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:46:57 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/18 00:59:45 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	replace_background(t_game *game)
{
	if (game->map[game->player_pos[0]][game->player_pos[1]] == '0' ||
			game->map[game->player_pos[0]][game->player_pos[1]] == 'P' ||
			game->map[game->player_pos[0]][game->player_pos[1]] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[0],
			game->player_pos[1] * 64, (game->player_pos[0]) * 64);
	}
	if (game->map[game->player_pos[0]][game->player_pos[1]] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[2],
			game->player_pos[1] * 64, (game->player_pos[0]) * 64);
	}
}

void	replace_background_enemy(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[0],
		game->enemy_pos[1] * 64, (game->enemy_pos[0]) * 64);
}
