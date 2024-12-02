/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ending.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:41:35 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 18:59:11 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     collected(t_game *game)
{
    int     x;
    int     y;
    int     counter;

    x = 0;
    y = 0;
    counter = 0;
    while (game->map[x])
    {
        while (game->map[x][y])
        {
            if (game->map[x][y] == game->content.collect_s)
                counter++;
            y++;
        }
    y = 0;
    x++;
    }
    return (counter);
}

int     ending(t_game *game)
{
    int     i;

    i = 0;
    if (game->map[i] != NULL)
    {
        while (game->map[i] != NULL)
            free(game->map[i++]);
        free(game->map);
        mlx_destroy_image(game->mlx_ptr, game->img.img_collect);
        mlx_destroy_image(game->mlx_ptr, game->img.img_exit);
        mlx_destroy_image(game->mlx_ptr, game->img.img_floor);
        mlx_destroy_image(game->mlx_ptr, game->img.img_player);
        mlx_destroy_image(game->mlx_ptr, game->img.img_wall);
    }
    mlx_destroy_display(game->mlx_ptr);
    free(game->mlx_ptr);
    exit(0);
}

int     touch(int x, t_game *game)
{
    if (x == KEY_ESCAPE)
        ending(game);
    if (x == KEY_W || x == KEY_UP)
        move_up(game, game->pos.x, game->pos.y);
    if (x == KEY_A || x == KEY_LEFT)
        move_left(game, game->pos.x, game->pos.y);
    if (x == KEY_D || x == KEY_RIGHT)
        move_right(game, game->pos.x, game->pos.y);
    if (x == KEY_S || x == KEY_DOWN)
        move_down(game, game->pos.x, game->pos.y);
    return (0);
}

(game, game->map.player.y, game->map.player.x + 1, RIGHT);