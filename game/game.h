/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:45:29 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:46:02 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <X11/X.h>
# include <time.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define NC "\033[0m"

typedef struct s_game
{
	char		**map;
	int			**coll_pos;	
	void		**sprite_ptr;
	void		*mlx;
	void		*window;
	int			*player_pos;
	int			*enemy_pos;
	int			*enemy_moves;
	char		*c_moves;
	int			length;
	int			width;
	int			empty_space;
	int			collectible;
	int			coll_max;
	int			moves;
	int			character;
	int			enemy_bool;
	int			percent_picked;
	int			percent_fbool;
}	t_game;

/* Functions to initialise struct game                                        */

void	initialise_map(char *file, t_game *game);
void	get_game_map(t_game *game, int fd);
int		count_map_collectible(char **map);
void	find_map_collectibles(t_game *game);
void	count_empty_space(t_game *game);
void	initialise_window(t_game *game);

/* Functions to load sprites, map to window and enemy                         */

void	ft_load(t_game *game);
void	load_sprites(t_game *game);
void	load_map_to_window(t_game *game);
void	load_map_to_window_continue(t_game *game, int x, int y);
void	load_collectible_sprites(t_game *game, int length, int width);
void	load_waiting_screen(t_game *game);

void	load_enemy(t_game *game);
void	select_enemy_spawn_location(t_game *game);
int		try_spawn_line(t_game *game, int x);
int		try_spawn_collumn(t_game *game, int x, int y);

/* Functions to manage key input and player deplacement                       */

int		key_management(int keycode, t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	replace_background(t_game *game);

/* Functions for enemy movement                                               */

int		check_enemy_surrounding_up_down(t_game *game);
void	move_enemy(t_game *game);
void	move_enemy_up(t_game *game);
void	move_enemy_down(t_game *game);
void	move_enemy_left(t_game *game);
void	move_enemy_right(t_game *game);
void	replace_background_enemy(t_game *game);

/* Functions for animations and swap sprites                                  */

int		load_animations(t_game *game);
void	animate_collectible(t_game *game);
void	swap_player_sprite(t_game *game);
void	swap_scoreboard(t_game *game);

/* Check functions                                                            */

void	check_player_pos_coll(t_game *game);
void	check_player_pos_exit(t_game *game);
void	check_player_death(t_game *game);

/* Portal gun's functions                                                     */

void	initialise_wall_array(t_game *game);
void	portal_gun_input(int keycode, t_game *game);

/* Free function                                                              */

int		ft_exit(t_game *game);

#endif
