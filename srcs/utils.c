/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/07 16:27:06 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    //    *img;
    while (x < game->height - 1)
    {
        while (y < game->width - 1)
        {
            mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, game->img.wall,
                        x * 64, y * 64);
            y++;
        }
        y = 0;
        x++;
    }
}
