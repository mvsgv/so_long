// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   checkers.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/01 16:10:52 by mavissar          #+#    #+#             */
// /*   Updated: 2024/12/06 16:00:54 by mavissar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// /* CONTENT_CHECKER -> parcours ma map et check les differents type d element 
//                         presents a chaque encontre je rajouterai 1 a mon prg*/
// /* FORMAT_CHECKER -> verifie que lq carte est carre*/
// /* LINE_CHECKER -> Vérifier si une ligne de la carte 
//                     est entièrement composée d'un caractère spécifique (wall)*/
// /*COLUMN_CHECKER ->Vérifie que chaque col est fermée par des murs*/
#include "so_long.h"

void content_checker(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        if (i == game->height - 1)
			break;
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


int format_checker(t_game *game)
{
    int row_length;
    int y;
    y = 0;
    if (!game->map || !game->map[0])
        return (ft_error("Error\nMap is empty or invalid!\n"), 0);
    row_length = ft_strlen(game->map[0]);
    while (game->map[y])
    {
        if (y == 3)
            break;
        if ((int)ft_strlen(game->map[y]) != row_length)
        {
            ft_error("Error\nThe map has a wrong size!\n");
            return (0);
        }
        y++;
    }
    return (1);
}


int lines_checker(char *line, char wall, t_game *game)
{
    int i;
    
    i = 0;
    while (line[i] != '\0')
    {
        if (i == game->height - 1)
			break;
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
    while (line[i] && i < game->height)
        i++;
    
    if (line[0] != wall || line[i - 1] != wall)
    {
        ft_error("Error\nProblem with column closure\n");
        return (0);
    }
    game->width = i;
    // exit(0);
    return (1);
}

int     good_behavior_checker(t_game *game)
{
    int	i;
	int	j;
    char **map;
	map = game->map;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'C' ||
				map[i][j] == 'P' || map[i][j] == 'E' || map[i][j] == '\n')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

