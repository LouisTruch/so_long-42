/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:11:22 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/18 01:19:20 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

/* Swap player sprite when all collectibles have been picked                 *
 * Put game->character to 1, destroying and loading sprite                   */

void	swap_player_sprite(t_game *game)
{
	int	length;
	int	width;

	mlx_destroy_image(game->mlx, game->sprite_ptr[4]);
	game->sprite_ptr[4] = mlx_xpm_file_to_image(game->mlx,
			"assets/player2.xpm", &length, &width);
	game->character = 1;
}

void	set_percent_fbool(t_game *game)
{
	if (game->percent_picked >= 25 && game->percent_picked <= 49)
		game->percent_fbool = 1;
	if (game->percent_picked >= 50 && game->percent_picked <= 74)
		game->percent_fbool = 3;
	if (game->percent_picked >= 75 && game->percent_picked <= 99)
		game->percent_fbool = 5;
	if (game->percent_picked == 100)
	{
		game->percent_fbool = 7;
		game->percent_picked = 101;
	}
}

/* Swap scoreboard .xpm every 25%                                            *
 * percent_fbool is used to avoid destroying and loading image constantly    */

void	swap_scoreboard_upperhalf(t_game *game)
{
	int	length;
	int	width;

	if (game->percent_fbool == 5)
	{
		mlx_destroy_image(game->mlx, game->sprite_ptr[14]);
		game->sprite_ptr[14] = mlx_xpm_file_to_image(game->mlx,
				"assets/scorebg3.xpm", &length, &width);
		game->percent_fbool = 6;
	}
	if (game->percent_fbool == 7)
	{
		mlx_destroy_image(game->mlx, game->sprite_ptr[14]);
		game->sprite_ptr[14] = mlx_xpm_file_to_image(game->mlx,
				"assets/scorebg4.xpm", &length, &width);
		game->percent_fbool = 8;
	}
}

void	swap_scoreboard(t_game *game)
{
	int	length;
	int	width;

	set_percent_fbool(game);
	if (game->percent_fbool == 1)
	{
		mlx_destroy_image(game->mlx, game->sprite_ptr[14]);
		game->sprite_ptr[14] = mlx_xpm_file_to_image(game->mlx,
				"assets/scorebg1.xpm", &length, &width);
		game->percent_fbool = 2;
	}
	if (game->percent_fbool == 3)
	{
		mlx_destroy_image(game->mlx, game->sprite_ptr[14]);
		game->sprite_ptr[14] = mlx_xpm_file_to_image(game->mlx,
				"assets/scorebg2.xpm", &length, &width);
		game->percent_fbool = 4;
	}
	swap_scoreboard_upperhalf(game);
}
