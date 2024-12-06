/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 19:02:26 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/06 18:51:48 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	wall_top(int width, char **map)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1')
		{
			printf("Top wall error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	walls(int height, int width, char **map)
{
	int	i;

	i = 0;
	while (i < (height - 1))
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
		{
			printf("Wall error line %d\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	wall_bot(int height, int width, char **map)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[height - 1][i] != '1')
		{
			printf("Bottom wall error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	find_wall(t_game *game)
{
	char	**map;
	int		width;
	int		height;

	height = game->height;
	width = game->width;
	map = game->map;
	if (!wall_top(width, map))
		return (0);
	if (!walls(height, width, map))
		return (0);
	if (!wall_bot(height, width, map))
		return (0);
	return (1);
}
