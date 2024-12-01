/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 13:23:10 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/01 18:38:43 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    *get_map(int fd)
{
    char    *line;
    char    *buff;
    int     count;
    char    *tmp;

    line = ft_strdup("");
    buff = ft_strdup("");
    count = get_next_line(fd);
    if (count > 0)
    {
        tmp = buff;
        while (count > 0)
        {
            buff = ft_strjoin(buff, line);
            free(tmp);
            free(line);
            line = ft_strdup("");
            count = ft_strdup("");
            count = get_next_line(fd);
            tmp = buff;
        }
        return (buff);
    }
    perror("Error\nWrong map lecture\n");
    return (NULL);
}
char    **parsing(int fd, t_game *game)
{
    int     i;

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
        else if (!(rest_checker(game->map[i], &(game->content))))
            return (free_map(game));
        i++;
    }
    game->height = i;
    if (!(lines_checker(game->map[i - 1], game->content.wall_s)))
        return (free_map);
    return (game->map);
}

char    **map_init(char **argv, t_game *game)
{
    int     fd;

    fd = 0;
    game->map = NULL;
    if (ft_strnchr(argv[1], ".ber") == 0)
    {
            perror("Error\nCorrect map not founded\n");
            return (0);
    }
    else
    {
        fd = open(argv[1], O_RDONLY);
        if (fd > 0)
            game->map = parsing(fd, game);
        else
            return (ft_error("Error\nCan't open the file\n"));
        if ((game->content.counted_c == 0 || game->content.counted_e != 1
            || game->content.counted_e != 1) && game->map != NULL)
        {
            free_map(game);
            return (ft_error("Error\nWrong nb of P,E or C\n"));
        }
    }
    return (game->map);
}

void    *free_map(char **map)
{
    int     i;

    i = 0;
    while (map && map[i])
    {
        free(map[i++]);
    }
    free(map);
    return (0);
}
