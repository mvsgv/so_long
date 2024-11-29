/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:30:17 by mavissar          #+#    #+#             */
/*   Updated: 2024/11/29 17:52:52 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Initialisation de la MLX
// Chargement de la carte
// Création de la fenêtre
// Chargement des sprites
#include "so_long.h"

int     game_create(t_game *game, char *map_f)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);
    if (!load_map(game, map_f))
        return (0);
    game->win = mlx_new_window(game->mlx, game->width * 24, game->height * 24);
    if (!game->win)
        return (0);
    if (!load_sprites(game))
    {
        free_map(game->map);
        mlx_destroy_window(game->mlx, game->win);
        return (0);
    }
    return (1);
}

int     render_game(t_game *game)
{
    int     x;
    int     y;

    y = 0;
    x = 0;
    while (y < game->height)
    {
        while (x < game->width)
        {
            draw(game, x, y, game->map[y][x]);
        }
        x++;
    }
    y++;
    return (0);
}

int     draw(t_game *game, int x, int y, char pxl)
{
    void    *img;

    if (pxl == '1')
        img = game->wall_sprite;
    if (pxl == '0')
        img = game->background_sprite;
    if (pxl == 'C')
        img = game->collectible_sprite;
    if (pxl == 'E')
        img = game->exit_sprite;
    if (pxl == 'P')
        img = game->player_sprite;
    if (img)
        mlx_put_image_to_window(game->mlx, game->win, img, x * PXL_SIZE, y * PXL_SIZE);
}

int load_sprites(t_game *game)
{
    int width;
    int height;

    game->wall_sprite = mlx_xpm_file_to_image(game->mlx, "xpm/wall.xpm", &width, &height);
    if (!game->wall_sprite)
        return (0);

    game->background_sprite = mlx_xpm_file_to_image(game->mlx, "xpm/background.xpm", &width, &height);
    if (!game->background_sprite)
        return (0);

    game->collectible_sprite = mlx_xpm_file_to_image(game->mlx, "xpm/collectible.xpm", &width, &height);
    if (!game->collectible_sprite)
        return (0);

    game->player_sprite = mlx_xpm_file_to_image(game->mlx, "xpm/player.xpm", &width, &height);
    if (!game->player_sprite)
        return (0);

    game->exit_sprite = mlx_xpm_file_to_image(game->mlx, "xpm/exit.xpm", &width, &height);
    if (!game->exit_sprite)
        return (0);

    return (1);
}
