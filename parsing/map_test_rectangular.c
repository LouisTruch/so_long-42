/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test_rectangular.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltruchel <ltruchel@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 17:49:37 by ltruchel          #+#    #+#             */
/*   Updated: 2022/12/01 17:49:47 by ltruchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	map_test_rectangular(char **map)
{
	int	k;
	int	length;
	int	length_next;

	k = 0;
	length = ft_strlen(map[k]);
	k += 1;
	while (map[k])
	{
		length_next = ft_strlen(map[k]);
		if (length != length_next)
			return (0);
		k++;
	}
	return (1);
}
