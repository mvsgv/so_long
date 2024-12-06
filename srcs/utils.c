/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:35:32 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/06 18:39:02 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print(t_game *game, void *img, int x, int y)
{
    mlx_put_image_to_window(game->mlx_ptr, game->mlx_win, img,
                            game->img.width * x, game->img.height * y);
}
