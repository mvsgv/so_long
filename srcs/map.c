// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   map.c                                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/01 13:23:10 by mavissar          #+#    #+#             */
// /*   Updated: 2024/12/06 18:53:15 by mavissar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "so_long.h"

// static void	while_loop(int fd)
// {
// 	char	*line;
// 	int		j;
	
// 	j = 0;
// 	while (1)
// 	{
//     	line = get_next_line(fd);
//     	if (!line)
//         	break;
//     	free(line);
//     	j++;
// 	}
// }

// char	**get_map(int fd, t_game *game)
// {
// 	int		i;
// 	char	*line;
// 	int		nb_lines;
// 	int		j;
	
// 	i = 0;
// 	j = 0;
// 	nb_lines = 0;
// 	if (fd < 0)
// 		ft_error("Error\nCan't open the file");
// 	while_loop(fd);
// 	free(line);
// 	game->map = (char **)malloc(sizeof(char *) * j);
// 	if (!game->map)
// 		ft_error("Error\nMempry alocation failed\n");
// 	lseek(fd, 0, SEEK_SET);
// 	while(1)
// 	{
// 		line = get_next_line(fd);
//     	if (!line)
//         	break;
//     	game->map = &line;
// 		j++;
// 	}
// 	exit(0);
// }


// void	*free_map(t_game *game)
// {
// 	int		i;

// 	i = 0;
	
// 	while (game->map[i] != NULL)
// 	{
// 		free(game->map[i]);
// 		i++;
// 	}
// 	free(game->map);
// 	game->map = NULL;
// 	return (0);
// }

// char	**parsing(int fd, t_game *game)
// {
// 	int		i;

// 	i = 1;
// 	game->map = get_map(fd, game->map);
// 	content_checker(game);
// 	if (!(format_checker(game->map)))
// 		return (free_map(game));
// 	if (!(lines_checker(game->map[0], game->content.wall_s)))
// 		return (free_map(game));
// 	while (game->map[i] != NULL)
// 	{
// 		if (!(column_checker(game->map[i], game->content.wall_s, game)))
// 			return (free_map(game));
// 		else if (!(good_behavior_checker(game->map[i], &(game->content))))
// 			return (free_map(game));
// 		i++;
// 	}
// 	game->height = i;
// 	if (!(lines_checker(game->map[i - 1], game->content.wall_s)))
// 		return (free_map(game));
// 	return (game->map);
// }

// char	**map_init(char **str, t_game *game)
// {
// 	int		fd;
// 	int		len;
	
// 	fd = 0;
// 	game->map = NULL;
// 	len = ft_strlen((str[1]));
// 	if ((ft_strncmp(str[1] + len - 4, ".ber", 4)) != 0)
// 		return ft_error("ERROR\nMap format is invalid!\n");
// 	else
// 	{
// 		fd = open(str[1], O_RDONLY);
// 		if (fd > 0)
// 			game->map = parsing(fd, game);
// 		else
// 			return (ft_error("Error\nFailed to open file\n"));
// 		if ((game->content.counted_c == 0 || game->content.counted_e != 1
// 				|| game->content.counted_p != 1) && game->map != NULL)
// 		{
// 			free_map(game);
// 			return (ft_error("Error\nNeed 1 Player/Exit and at least 1 Object\n"));
// 		}
// 	}
// 	return (game->map);
// }

// void	*ft_error(char *str)
// {
// 	write(2, str, ft_strlen(str));
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:10 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/06 18:50:41 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_line_width(char *line, int *map_width, int y, t_game *game)
{
	int	x;

	x = ft_strlen(line);
	// -- pour qu'elles fassent toutes la meme taille, (la derniere ligne n'a pas de /n)
	if (line[x - 1] == '\n')
		x--;
	// si map_width = -1, c'est qu'on est sur la premiere ligne donc on setup la largeur.
	if (*map_width == -1)
	{
		*map_width = x;
		game->width = *map_width;
	}
	//ensuite, on compare toutes les autres lignes a la premiere ligne definie precedemment
	else if (x != *map_width)
	{
		printf("Error\nSize of line %d.\n", y + 1);
		free(line);
		exit(1);
	}
	return (0);
}


void	get_map(int fd, t_game *game)
{
	int		i;
	char	*line;
	int		nb_lines;
	int		j;
	int		y;
	static int	map_width = -1;
	
	j = 0;
	y = 0;
	i = 0;
	nb_lines = 0;
	if ( fd < 0)
		ft_error("Error\nCan't open file");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (check_line_width(line, &map_width, y, game) == -1)
		{
			free(line);
			close(fd);
			exit(1);
		}	
		free(line);
		y++;
	}
	free(line);
	game->height = y;
	//int x = 0;
	game->map = (char **)malloc(sizeof(char *) * y);
	if (!game->map)
		ft_error("Erro\nMemory allocation failed\n");
	lseek(fd, 0, SEEK_SET);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map[j] = line;
		printf("%s", game->map[j]);
		// free(line);
		j++;
	}
	j = 0;
}

void	*free_map(t_game *game)
{
	int		i;

	i = 0;
	
	while (game->map[i] != NULL)
	{
		if (i == game->height - 1)
			break;
		free(game->map[i]);
		i++;
	}
	free(game->map);
	game->map = NULL;
	return (0);
}
void errooor(t_game *game, char *str)
{
	printf("Error\n%s\n", str);
	//exit(1);
	free_map(game);
	exit(1);
}
char	**parsing(int fd, t_game *game)
{
	int		i;

	i = 1;
	get_map(fd, game);
	content_checker(game);
	if (!(format_checker(game)))
		return (free_map(game));
	if (!(lines_checker(game->map[0], game->content.wall_s, game)))
		return (free_map(game));
	if (!good_behavior_checker(game))
		errooor(game, "Arg intru");
	if (!find_wall(game))
		errooor(game, "Wall error");
		
	
	game->height = i;
	if (!(lines_checker(game->map[i - 1], game->content.wall_s, game)))
		return (free_map(game));
	//exit(0);
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
