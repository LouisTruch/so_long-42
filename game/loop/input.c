/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:35:24 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:51:44 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int	key_management(int keycode, t_game *game)
{
	if (keycode == 65362 || keycode == 'w')
		move_up(game);
	if (keycode == 65364 || keycode == 's')
		move_down(game);
	if (keycode == 65361 || keycode == 'a')
		move_left(game);
	if (keycode == 65363 || keycode == 'd')
		move_right(game);
	if (keycode == 65307)
		ft_exit(game);
	check_player_pos_coll(game);
	check_player_pos_exit(game);
	if (game->enemy_bool == 1)
		check_player_death(game);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite_ptr[4],
		game->player_pos[1] * 64, game->player_pos[0] * 64);
	return (0);
}

void	move_up(t_game *game)
{
	if (game->map[game->player_pos[0] - 1][game->player_pos[1]] == '1')
		return ;
	else
	{
		replace_background(game);
		game->player_pos[0] -= 1;
		game->moves += 1;
		if (game->enemy_bool == 1)
			move_enemy(game);
		ft_printf(GREEN"Score=%i\n"NC, game->moves);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->player_pos[0] + 1][game->player_pos[1]] == '1')
		return ;
	else
	{
		replace_background(game);
		game->player_pos[0] += 1;
		game->moves += 1;
		if (game->enemy_bool == 1)
			move_enemy(game);
		ft_printf(GREEN"Score=%i\n"NC, game->moves);
	}
}

void	move_left(t_game *game)
{
	if (game->map[game->player_pos[0]][game->player_pos[1] - 1] == '1')
		return ;
	else
	{
		replace_background(game);
		game->player_pos[1] -= 1;
		game->moves += 1;
		if (game->enemy_bool == 1)
			move_enemy(game);
		ft_printf(GREEN"Score=%i\n"NC, game->moves);
	}
}

void	move_right(t_game *game)
{
	if (game->map[game->player_pos[0]][game->player_pos[1] + 1] == '1')
		return ;
	else
	{
		replace_background(game);
		game->player_pos[1] += 1;
		game->moves += 1;
		if (game->enemy_bool == 1)
			move_enemy(game);
		ft_printf(GREEN"Score=%i\n"NC, game->moves);
	}
}
