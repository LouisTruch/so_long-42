/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:37:34 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:43:48 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	ft_load(t_game *game)
{
	load_sprites(game);
	load_waiting_screen(game);
	load_map_to_window(game);
	load_enemy(game);
}

/* Malloc every .xpm and put them in game                                    */

void	load_sprites(t_game *game)
{
	int			length;
	int			width;

	game->sprite_ptr = ft_calloc(sizeof(void *), 16);
	if (!game->sprite_ptr)
		return ;
	game->sprite_ptr[0] = mlx_xpm_file_to_image(game->mlx,
			"assets/background.xpm", &length, &width);
	game->sprite_ptr[1] = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &length, &width);
	game->sprite_ptr[2] = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &length, &width);
	game->sprite_ptr[3] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar0.xpm", &length, &width);
	game->sprite_ptr[4] = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &length, &width);
	game->sprite_ptr[14] = mlx_xpm_file_to_image(game->mlx,
			"assets/scorebg0.xpm", &length, &width);
	game->sprite_ptr[5] = mlx_xpm_file_to_image(game->mlx,
			"assets/enemy.xpm", &length, &width);
	game->sprite_ptr[15] = mlx_xpm_file_to_image(game->mlx,
			"assets/loading.xpm", &length, &width);
	load_collectible_sprites(game, length, width);
}

void	load_collectible_sprites(t_game *game, int length, int width)
{
	game->sprite_ptr[6] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar0.xpm", &length, &width);
	game->sprite_ptr[7] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar1.xpm", &length, &width);
	game->sprite_ptr[8] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar2.xpm", &length, &width);
	game->sprite_ptr[9] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar3.xpm", &length, &width);
	game->sprite_ptr[10] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar4.xpm", &length, &width);
	game->sprite_ptr[11] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar5.xpm", &length, &width);
	game->sprite_ptr[12] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar6.xpm", &length, &width);
	game->sprite_ptr[13] = mlx_xpm_file_to_image(game->mlx,
			"assets/dollar7.xpm", &length, &width);
}

/* Put sprites in window                                                     */

void	load_map_to_window(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	while (game->map[++x])
	{
		y = -1;
		while (game->map[x][++y])
		{
			if (game->map[x][y] == '0')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite_ptr[0], y * 64, x * 64);
			if (game->map[x][y] == '1')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite_ptr[1], y * 64, x * 64);
			if (game->map[x][y] == 'E')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite_ptr[2], y * 64, x * 64);
			if (game->map[x][y] == 'C')
				mlx_put_image_to_window(game->mlx, game->window,
					game->sprite_ptr[3], y * 64, x * 64);
			load_map_to_window_continue(game, x, y);
		}
	}
}

void	load_map_to_window_continue(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->sprite_ptr[4], y * 64, x * 64);
		game->player_pos[0] = x;
		game->player_pos[1] = y;
	}
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite_ptr[14], 0, game->width * 64);
}
