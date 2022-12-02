/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:18:01 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 17:40:38 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../libft/libft.h"
# include <fcntl.h>

# define GREEN "\033[1;32m"
# define RED "\033[1;31m"
# define NC "\033[0m"

/* Base functions of parsing                                                  */

void	map_parsing(char *file);
int		open_map(char *file);
int		check_file_extension(char *file);
char	**map_copy(int fd);
void	exit_empty_map(char *line, char *map);
void	make_every_test(char **map, char *file);

/* Functions to make map's basic tests                                        */

int		map_test_rectangular(char **map);
int		map_test_wall(char **map);
int		count_map_line(char **map);
int		map_test_requirements(char **map);

/* Functions to test path to exit and path to collectible                     */

int		map_test_valid_path(char **map, char *file);
void	find_start(char **map, int *x, int *y);
void	flood_fill_map(char **cpy);
int		test_path_to_exit(char **map, char **cpy);
void	find_map_exit(char **map, int *x, int *y);
int		test_path_to_collectibles(char **map, char **cpy);
int		count_map_collectibles(char **map);
int		**find_collectibles(char **map, int ***coll);

/* Free functions                                                             */

void	ft_free_map(char **map);
void	ft_free_parsing(char **map, char **cpy, int **coll);

#endif
