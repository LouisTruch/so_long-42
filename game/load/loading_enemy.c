/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:01:51 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/30 21:48:38 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

/* Check if there is at least '0' on map, if not set enemy_bool to 0         *
 * to not free it if there is none                                           *
 * Then select a random '0' and put enemy's sprite on map                    */

void	load_enemy(t_game *game)
{
	if (game->empty_space == 0)
	{
		ft_printf(RED"No place for enemy to spawn\n"NC);
		game->enemy_bool = 0;
		return ;
	}
	game->enemy_bool = 1;
	game->enemy_pos = ft_calloc(sizeof(int), 2);
	if (!game->enemy_pos)
		return ;
	select_enemy_spawn_location(game);
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite_ptr[5], game->enemy_pos[1] * 64, game->enemy_pos[0] * 64);
}

/* Select a random line and random cell to spawn enemy on                     */

void	select_enemy_spawn_location(t_game *game)
{
	int		spawn_x;
	int		spawn_y;
	int		f_bool;

	f_bool = 0;
	srand(time(NULL));
	while (f_bool == 0)
	{
		spawn_x = 1 + rand() % (game->width - 2);
		f_bool = try_spawn_line(game, spawn_x);
	}
	game->enemy_pos[0] = spawn_x;
	f_bool = 0;
	while (f_bool == 0)
	{
		spawn_y = 1 + rand() % (game->length - 2);
		f_bool = try_spawn_collumn(game, spawn_x, spawn_y);
	}
	game->enemy_pos[1] = spawn_y;
}

/* Try if the line sent by select_spawn_line contains a '0'                   */

int	try_spawn_line(t_game *game, int x)
{
	int	y;

	y = 0;
	while (game->map[x][y])
	{
		if (game->map[x][y] == '0')
			return (1);
		y++;
	}
	return (0);
}

/* Try if the cell sent by select_spawn_line is a '0'                         */

int	try_spawn_collumn(t_game *game, int x, int y)
{
	if (game->map[x][y] == '0')
		return (1);
	else
		return (0);
}
