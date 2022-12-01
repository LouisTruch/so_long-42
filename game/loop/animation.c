/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:05:30 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/19 19:21:17 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	show_score(t_game *game)
{
	free(game->c_moves);
	game->c_moves = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite_ptr[14], 0, game->width * 64);
	mlx_string_put(game->mlx, game->window, 10,
		(game->width * 64) + 40, 0XFF0000, "SCORE:");
	mlx_string_put(game->mlx, game->window, 46,
		(game->width * 64) + 40, 0XFF0000, game->c_moves);
}

int	load_animations(t_game *game)
{
	usleep(1000);
	animate_collectible(game);
	if (game->character == 0 && game->collectible == 0)
	{
		swap_player_sprite(game);
		mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[4],
			game->player_pos[1] * 64, (game->player_pos[0]) * 64);
	}
	if (game->percent_picked >= 25)
		swap_scoreboard(game);
	show_score(game);
	return (0);
}
