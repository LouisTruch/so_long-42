/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:28:28 by ltruchel          #+#    #+#             */
/*   Updated: 2022/11/19 22:52:31 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	**map_copy(int fd)
{
	char	*line;
	char	*map_cpy;
	char	*tmp;
	char	**map;

	map_cpy = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strdup(map_cpy);
		free (map_cpy);
		map_cpy = ft_strjoin(tmp, line);
		free (line);
		free (tmp);
		line = get_next_line(fd);
	}
	map = ft_split(map_cpy, '\n');
	if (!map)
		return (0);
	free (map_cpy);
	return (map);
}
