/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:10 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/04 19:04:48 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	int		char_count;
	char	*tmp_buff;

	line_map = ft_strdup("");
	buff = ft_strdup("");
	char_count = get_next_line(fd, &line_map);
	if (char_count > 0)
	{
		tmp_buff = buff;
		while (char_count > 0)
		{
			buff = ft_strjoin(buff, line_map);
			line_map = ft_strdup("");
			char_count = get_next_line(fd, &line_map);
			tmp_buff = buff;
		}
		return (buff);
	}
	ft_error("Error\nWrong lecture map\n");
	return (NULL);
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
	game->map = ft_split(get_map(fd), '\n');
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

	fd = 0;
	game->map = NULL;
	if (ft_strchr(str[1], ".ber") == 0)
		return (ft_error("Error\nNo correct format map founded\n"));
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
// char	*get_map(int fd)
// {
// 	char	*line_map;
// 	char	*buff;
// 	int		char_count;
// 	char	*tmp_buff;

// 	line_map = ft_strdup("");
// 	buff = ft_strdup("");
// 	char_count = get_next_line(fd, &line_map);
// 	if (char_count > 0)
// 	{
// 		tmp_buff = buff;
// 		while (char_count > 0)
// 		{
// 			buff = ft_strjoin(buff, line_map);
// 			// free(tmp_buff);
// 			// free(line_map);
// 			line_map = ft_strdup("");
// 			char_count = get_next_line(fd, &line_map);
// 			tmp_buff = buff;
// 		}
// 		return (buff);
// 	}
// 	ft_error("Error\nWrong lecture map\n");
// 	return (NULL);
// }

// char    **parsing(int fd, t_game *game)
// {
//     int     i;

//     i = 1;
//     game->map = ft_split(get_map(fd), '\n');
//     content_checker(game);
//     if (!(format_checker(game->map)))
//         return (free_map(game));
//     if (!(lines_checker(game->map[0], game->content.wall_s)))
//         return (free_map(game));
//     while (game->map[i] != NULL)
//     {
//         if (!(column_checker(game->map[i], game->content.wall_s, game)))
//             return (free_map(game));
//         else if (!(good_behavior_checker(game->map[i], &(game->content))))
//             return (free_map(game));
//         i++;
//     }
//     game->height = i;
//     if (!(lines_checker(game->map[i - 1], game->content.wall_s)))
//         return (free_map(game));
//     return (game->map);
// }

// char    **map_init(char **argv, t_game *game)
// {
//     int     fd;

//     fd = 0;
//     game->map = NULL;
//     if (ft_strchr(argv[1], ".ber") == 0)
//         return (ft_error("Error\nNo correct format map founded\n"));
//     else
//     {
//         fd = open(argv[1], O_RDONLY);
//         if (fd > 0)
//             game->map = parsing(fd, game);
//         else
//             return (ft_error("Error\nCan't open the file\n"));
//         if ((game->content.counted_c == 0 || game->content.counted_e != 1
//             || game->content.counted_p != 1) && game->map != NULL)
//         {
//             free_map(game);
//             return (ft_error("Error\nWrong nb of P,E or C\n"));
//         }
//     }
//     return (game->map);
// }

// void    *free_map(t_game *game)
// {
//     int     i;

//     i = 0;
//     while (game->map[i] != NULL)
//     {
//         free(game->map[i++]);
//     }
//     free(game->map);
//     game->map = NULL;
//     return (0);
// }

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}
