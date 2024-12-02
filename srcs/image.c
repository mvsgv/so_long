/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:52:52 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 11:47:33 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    link_content(t_map_content *content)
{
    content->collect_s = 'C';
    content->exit_s = 'E';
    content->wall_s = '1';
    content->player_s = 'P';
    content->space_s = '0';
    content->counted_p = 0;
    content->counted_e = 0;
    content->counted_c = 0;
}
void    img_setup(t_game *game)
{
    game->img.height = 80;
    game->img.width = 80;
    game->img.floor = "./xpm/background.xpm";
    game->img.collect = "./xpm/collectible.xpm";
    game->img.exit = "./xpm/exit.xpm";
    game->img.player = "./xpm/player.xpm";
    game->img.wall = "./xpm/wall.xpm";
    game->img.img_floor = mlx_xpm_file_to_image(game->mlx_ptr,
             game->img.floor, &(game->img.width), &(game->img.height));
    game->img.img_collect = mlx_xpm_file_to_image(game->mlx_ptr, 
            game->img.collect, &(game->img.height), &(game->img.width));
    game->img.img_exit = mlx_xpm_file_to_image(game->mlx_ptr, game->img.exit,
                        &(game->img.height), &(game->img.width));
    game->img.img_player = mlx_xpm_file_to_image(game->mlx_ptr, 
                game->img.player, &(game->img.height), &(game->img.width));
    game->img.img_wall = mlx_xpm_file_to_image(game->mlx_ptr,
                    game->img.wall, &(game->img.height), &(game->img.width));
}
