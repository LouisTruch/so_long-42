/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:16:54 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 17:56:31 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/parsing.h"
#include "game/game.h"

int	main(int ac, char **av)
{
	t_game		*game;

	if (ac != 2)
	{
		ft_printf(RED"Error\nMust only use 2 parameters"NC);
		exit (0);
	}
	map_parsing(av[1]);
	game = ft_calloc(sizeof(t_game), 1);
	if (!game)
		return (0);
	initialise_map(av[1], game);
	initialise_window(game);
	ft_load(game);
	mlx_hook(game->window, KeyPress, KeyPressMask, key_management, game);
	mlx_hook(game->window, DestroyNotify, StructureNotifyMask, ft_exit, game);
	mlx_loop_hook(game->mlx, load_animations, game);
	mlx_loop(game->mlx);
	return (0);
}
