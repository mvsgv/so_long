/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:10:52 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 08:56:55 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* CONTENT_CHECKER -> parcours ma map et check les differents type d element 
                        presents a chaque encontre je rajouterai 1 a mon prg*/
/* FORMAT_CHECKER -> verifie que lq carte est carre*/
/* LINE_CHECKER -> Vérifier si une ligne de la carte 
                    est entièrement composée d'un caractère spécifique (wall)*/
/*COLUMN_CHECKER ->Vérifie que chaque col est fermée par des murs*/
#include "so_long.h"

void    content_checker(t_game *game)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (game->map[i])
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == game->content.collect_s)
                game->content.counted_c += 1;
            if (game->map[i][j] == game->content.player_s)
                game->content.counted_p += 1;
            if (game->map[i][j] == game->content.exit_s)
                game->content.counted_e += 1;
        }
        j++;
    }
    j = 0;
    i++;
}

int    format_checker(char **map)
{
    int     x;
    int     y;
    int     count;

    x = 0;
    y = 0;
    count = 0;
    while (map[x][count] != '\0')
        count++;
    while (map[y] != NULL)
    {
        while (map[x][y])
            x++;
        if (x != count)
        {
            perror("Error\nThe map has a wrong size!\n");
            return (0);
        }
        x = 0;
        y++;
    }
    return (1);
}

int     lines_checker(char *line, char wall)
{
    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] != wall)
        {
            perror("Error\nProblem with map closure(Walls)\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int     column_checker(char *line, char wall, t_game *game)
{
    int     i;

    i = 0;
    while (line[i])
        i++;
    if (line[0] != wall || line[i - 1] != wall)
    {
        perror("Error\nProblem with column closure\n");
        return (0);
    }
    game->width = i;
    return (1);
}

int     good_behavior_checker(char *line, t_map_content *x)
{
    int     i;

    i = 0;
    while(line[i])
    {
        if (x->exit_s > 1 || x->player_s > 1)
            {
                perror("Error\nWrong nb of P or E\n");
                return (0);
            }
        if (line[i] != x->wall_s && line[i] != x->collect_s 
            && line[i] != x->exit_s && line[i] != x->player_s
            && line[i] != x->space_s)
        {
            perror("Error\nWrong digit in the map\n");
            return (0);
        }
        i++;
    }
    return (1);
}
