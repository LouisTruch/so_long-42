/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:33:19 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 18:40:47 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_free_sprite(t_game *game)
{
	int	i;

	i = 0;
	while (i <= 14)
	{
		mlx_destroy_image(game->mlx, game->sprite_ptr[i]);
		i++;
	}
	free(game->sprite_ptr);
}

void	ft_free_game_map(t_game *game)
{
	int	x;

	x = 0;
	while (game->map[x])
	{
		free (game->map[x]);
		x++;
	}
	free (game->map);
}

void	ft_free_coll_pos(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->coll_max)
	{
		free (game->coll_pos[i]);
		i++;
	}
	free (game->coll_pos);
}

int	ft_exit(t_game *game)
{
	int	i;

	mlx_loop_end(game->mlx);
	ft_free_sprite(game);
	ft_free_coll_pos(game);
	ft_free_game_map(game);
	free(game->player_pos);
	free(game->c_moves);
	free(game->enemy_pos);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit (0);
}
