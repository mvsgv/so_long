/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:15 by mavissar          #+#    #+#             */
/*   Updated: 2024/11/29 17:55:03 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"

# define PXL_SIZE 50 //pxl size

typedef struct s_game
{
    void    *mlx;   // 
    void    *win;   // Fenetre mlx
    char    **map;  // Carte du jeu
    int     width;  // Largeur de la carte
    int     height;  // hauteur de la carte
    void    *img[5];
    void    *wall_sprite;
    void    *exit_sprite;
    void    *background_sprite;
    void    *player_sprite;
    void    *collectible_sprite;
    int     sprite_width;
    int     sprite_height;
}   t_game;

int     render_game(t_game *game);
int     game_create(t_game *game, char *map_f);
int     draw(t_game *game, int x, int y, char pxl);
int     load_sprites(t_game *game);


#endif 