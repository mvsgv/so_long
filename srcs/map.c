/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:10 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/06 18:53:15 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	while_loop(int fd)
{
	char	*line;
	int		j;
	
	j = 0;
	while (1)
	{
    	line = get_next_line(fd);
    	if (!line)
        	break;
    	free(line);
    	j++;
	}
}

char	**get_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	int		nb_lines;
	int		j;
	
	i = 0;
	j = 0;
	nb_lines = 0;
	if (fd < 0)
		ft_error("Error\nCan't open the file");
	while_loop(fd);
	free(line);
	game->map = (char **)malloc(sizeof(char *) * j);
	if (!game->map)
		ft_error("Error\nMempry alocation failed\n");
	lseek(fd, 0, SEEK_SET);
	while(1)
	{
		line = get_next_line(fd);
    	if (!line)
        	break;
    	game->map = &line;
		j++;
	}
	exit(0);
}


void	*free_map(t_game *game)
{
	int		i;

	i = 0;
	
	while (game->map[i] != NULL)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
	return (0);
}

char	**parsing(int fd, t_game *game)
{
	int		i;

	i = 1;
	game->map = get_map(fd, game->map);
	content_checker(game);
	if (!(format_checker(game->map)))
		return (free_map(game));
	if (!(lines_checker(game->map[0], game->content.wall_s)))
		return (free_map(game));
	while (game->map[i] != NULL)
	{
		if (!(column_checker(game->map[i], game->content.wall_s, game)))
			return (free_map(game));
		else if (!(good_behavior_checker(game->map[i], &(game->content))))
			return (free_map(game));
		i++;
	}
	game->height = i;
	if (!(lines_checker(game->map[i - 1], game->content.wall_s)))
		return (free_map(game));
	return (game->map);
}

char	**map_init(char **str, t_game *game)
{
	int		fd;
	int		len;
	
	fd = 0;
	game->map = NULL;
	len = ft_strlen((str[1]));
	if ((ft_strncmp(str[1] + len - 4, ".ber", 4)) != 0)
		return ft_error("ERROR\nMap format is invalid!\n");
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			game->map = parsing(fd, game);
		else
			return (ft_error("Error\nFailed to open file\n"));
		if ((game->content.counted_c == 0 || game->content.counted_e != 1
				|| game->content.counted_p != 1) && game->map != NULL)
		{
			free_map(game);
			return (ft_error("Error\nNeed 1 Player/Exit and at least 1 Object\n"));
		}
	}
	return (game->map);
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}
