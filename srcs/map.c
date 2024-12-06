/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:10 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/06 15:45:21 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	// 1 loop qui utilise gnl + un int qui va tenir le compte
	//	-> nb de lignes
	// 1 loop sur la derniere ligne que renvoie gnl + un int qui tient le copte
	// 		--> nb de char / lignes
	
	// les malloc

	// la copie de la map dans char**

char	**get_map(int fd)
{
	char	**map;
	int		i;
	char	*line;
	int		nb_lines;
	int		nbr_char;
	int		j;
	
	j = 0;
	map = NULL;
	i = 0;
	nbr_char = 0;
	nb_lines = 0;
	if ( fd < 0)
		ft_error("Error\nCan't open file");
	while((line = get_next_line(fd)) != NULL)
		nb_lines++;
	map[i] = malloc(sizeof(char) * (nb_lines));
	if (!map)
		ft_error("Erro\nMemory allocation failed\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		while(line[nbr_char])
			nbr_char++;
		map[j] = malloc(sizeof(char) * (nbr_char + 1));
		if (!map[j])
			ft_error("Error\nMemory allocation failed");
		while (i < nbr_char)
		{
			map[i][j] = line[j];
			j++;
		}
		map[j][i] = '\0';
		free(line);
		j++;
	}
	return (map);
}

// char **lines;
// lines = malloc(nb_lines);

// j = 0
// while (j < nb_lines) {
// 	lines[j] = malloc(i);
// }



// 	char **map;

// 	// 1 loop avec gnl pour avoir nb de ligne et nb de char/ligne

// 	// 2 malloc du nombre de ligne sur map
// 	// 3 malloc(nb de char) sur chaque map[i]

// 	// 4 meme loop que dans 1 avec gnl, mais pour copier ce que gnl recupere 
// 	return map;
	
// }

// char	*get_map(int fd)
// {
// 	char	*line_map;
// 	char	*buff;
// 	int		char_count;
// 	char	*tmp_buff;

// 	line_map = ft_strdup("");
// 	buff = ft_strdup("");
// 	char_count = get_next_line(fd);
// 	if (char_count > 0)
// 	{
// 		tmp_buff = buff;
// 		while (char_count > 0)
// 		{
// 			buff = ft_strjoin(buff, line_map);
// 			free(tmp_buff);
// 			free(line_map);
// 			line_map = ft_strdup("");
// 			char_count = get_next_line(fd);
// 			tmp_buff = buff;
// 			//printf("begining : %s", tmp_buff);
// 		}
// 		return (buff);
// 	}
// 	ft_error("Error\nWrong lecture map\n");
// 	return (NULL);
// }

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
	game->map = get_map(fd);
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
