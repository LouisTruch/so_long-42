/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_collectible.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:07:56 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/18 01:10:15 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

/* Animate every collectibles on map                                          */

void	animate_collectible(t_game *game)
{
	static int	frame = 6;
	static int	wait = 0;
	int			i;

	if (wait++ < 80)
		return ;
	i = 0;
	while (i < game->coll_max)
	{
		if (frame == 6)
			wait = -400;
		else
			wait = 0;
		if (game->map[game->coll_pos[i][0]][game->coll_pos[i][1]] == 'C')
			mlx_put_image_to_window(game->mlx, game->window,
				game->sprite_ptr[frame], game->coll_pos[i][1] * 64,
				game->coll_pos[i][0] * 64);
		i++;
	}
	frame += 1;
	if (frame == 14)
		frame = 6;
	return ;
}
