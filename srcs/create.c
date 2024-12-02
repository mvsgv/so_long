/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 13:54:21 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 22:48:14 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_first(t_game *game)
{
    game->mlx_win = mlx_new_window(game->mlx_ptr, 
            (game->width * game->img.width), (game->height * game->img.height),
            "so_long");
    if (game->mlx_win == NULL)
    {
        free(game->mlx_ptr);
        return ;
    }
    mlx_loop_hook(game->mlx_ptr, &render, game);
    mlx_hook(game->mlx_win, 2, 0, &touch, game);
    mlx_hook(game->mlx_ptr, 17, 0, &ending, game);
}

void    render_second(t_game *game)
{
    int     x;
    int     y;
    
    x = 0;
    y = 0;
    while (game->map[y] != NULL)
    {
        while (game->map[y][x])
        {
            if (game->map[y][x] == game->content.collect_s)
                print(game, game->img.img_collect, x ,y);
            if (game->map[y][x] == game->content.player_s)
            {
                game->pos.x = x * game->img.width;
                game->pos.y = y * game->img.height;
                print(game, game->img.img_player, x, y);
            }
            if (game->map[y][x] == game->content.exit_s)
                print(game, game->img.img_exit, x, y);
            x++;
        }
        x = 0;
        y++;
    }
}

int    render(t_game *game)
{
    back_render(game);
    rest_render(game);
    return (0);
}

void    back_render(t_game *game)
{
    int     i;
    int     j;

    i = 0;
    while (game->map[i] != NULL)
    {
        while (game->map[i][j])
        {
            if (game->map[i][j] == game->content.wall_s)
                print(game, game->img.img_wall, i , j);
            if (game->map[i][j] == game->content.space_s)
                print(game, game->img.img_floor, i , j);
        j++;
        }
    j = 0;
    i++;
    }
}

void    rest_render(t_game *game)
{
    int     x;
    int     y;

    x = 0;
    while (game->map[x] != NULL)
    {
        while(game->map[x][y])
        {
            if (game->map[x][y] == game->content.collect_s)
                print(game, game->img.img_collect, x, y);
            if (game->map[x][y] == game->content.player_s)
            {
                game->pos.x = x * game->img.width;
                game->pos.y = y * game->img.height;
                print(game, game->img.img_player, x, y);   
            }
            if (game->map[x][y] == game->content.exit_s)
                print(game, game->img.img_exit, x, y);
            y++;
        }
        y = 0;
        x++;
    }
}