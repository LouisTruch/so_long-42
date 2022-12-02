/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:59:55 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/02 16:58:56 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	open_map(char *file)
{
	int		fd;

	if (check_file_extension(file) == 0)
	{
		ft_printf(RED"Error\nFile must be of .ber type"NC);
		exit (0);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf(RED"Error\nInvalid fd, can't open map file"NC);
		exit (0);
	}
	return (fd);
}

int	check_file_extension(char *file)
{
	char	*ext;

	if (ft_strlen(file) < 4)
		return (0);
	ext = ft_strchr(file, '.');
	if (ft_strlen(ext) != 4)
		return (0);
	if (ft_strncmp(ext, ".ber", 4) != 0)
		return (0);
	return (1);
}
