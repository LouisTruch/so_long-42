/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:44:29 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:47:15 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

void	load_waiting_screen(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->window,
		game->sprite_ptr[15], 0, 0);
	system("paplay assets/coc_startup.ogg");
}
