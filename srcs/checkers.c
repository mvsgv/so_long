/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:10:52 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/05 13:43:44 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* CONTENT_CHECKER -> parcours ma map et check les differents type d element 
                        presents a chaque encontre je rajouterai 1 a mon prg*/
/* FORMAT_CHECKER -> verifie que lq carte est carre*/
/* LINE_CHECKER -> Vérifier si une ligne de la carte 
                    est entièrement composée d'un caractère spécifique (wall)*/
/*COLUMN_CHECKER ->Vérifie que chaque col est fermée par des murs*/
#include "so_long.h"

// void    content_checker(t_game *game)
// {
//     int     i;
//     int     j;

//     i = 0;
//     j = 0;
//     // printf("before loop, exit : %d\n", game->content.exit_s);
//     while (game->map[i])
//     {
//         // printf("In loop\n");
//         while (game->map[i][j])
//         {
//             // printf("In loop2\n");
//             if (game->map[i][j] == game->content.collect_s)
//                 game->content.counted_c += 1;
//             if (game->map[i][j] == game->content.player_s)
//                 game->content.counted_p += 1;
//             if (game->map[i][j] == game->content.exit_s)
//                 game->content.counted_e += 1;
//             j++;
//         }
//         j = 0;
//         i++;
//     }
//     // printf("after loop, exit : %d\n", game->content.exit_s);
// }
void content_checker(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] == game->content.collect_s)
                game->content.counted_c++;
            else if (game->map[i][j] == game->content.player_s)
                game->content.counted_p++;
            else if (game->map[i][j] == game->content.exit_s)
                game->content.counted_e++;
            j++;
        }
        i++;
    }

    if (game->content.counted_p != 1 || game->content.counted_e != 1 
        || game->content.counted_c == 0)
        ft_error("Error\nWrong number of P, E, or C\n");
}


int format_checker(char **map)
{
    int row_length;
    int y;

    y = 0;
    if (!map || !map[0])
        return (ft_error("Error\nMap is empty or invalid!\n"), 0);
    row_length = ft_strlen(map[0]);
    while (map[y])
    {
        printf("Row %d length: %d\n", y, (int)ft_strlen(map[y])); // Debug row lengths
        if ((int)ft_strlen(map[y]) != row_length)
        {
            ft_error("Error\nThe map has a wrong size!\n");
            return (0);
        }
        y++;
    }
    return (1);
}


int lines_checker(char *line, char wall)
{
    int i;
    
    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != wall)
        {
            printf("Error: Invalid character '%c' at position %d in line: %s\n", line[i], i, line);
            ft_error("Error\nProblem with map closure(Walls)\n");
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
        ft_error("Error\nProblem with column closure\n");
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
        if (x->counted_e > 1 || x->counted_p > 1)
            {
                ft_error("Error\nWrong nb of P or E\n");
                return (0);
            }
        if (line[i] != x->wall_s && line[i] != x->collect_s 
            && line[i] != x->exit_s && line[i] != x->player_s
            && line[i] != x->space_s)
            {
                ft_error("Error\nWrong digit in the map\n");
                return (0);
            }
        i++;
    }
    return (1);
}
