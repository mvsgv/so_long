// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   create.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/12/02 13:54:21 by mavissar          #+#    #+#             */
// /*   Updated: 2024/12/05 11:31:20 by mavissar         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "so_long.h"

void render_first(t_game *game)
{
    game->mlx_win = mlx_new_window(game->mlx_ptr, 
                                   game->width * game->img.width, 
                                   game->height * game->img.height, 
                                   "so_long");
    if (!game->mlx_win)
    {
        ft_putstr_fd("Error!\nFailed to create MLX window\n", 2);
        return;
    }
    print(game);
    mlx_hook(game->mlx_win, 2, (1L << 0), &touch, game);
    mlx_hook(game->mlx_win, 17, (1L << 17), &ending, game);
    mlx_loop(game->mlx_ptr);
    ending(game);
}

// void    render_second(t_game *game)
// // {
// //     int     x;
// //     int     y;
    
// //     x = 0;
// //     y = 0;
// //     while (game->map[y] != NULL)
// //     {
// //         while (game->map[y][x])
// //         {
// //             if (game->map[y][x] == game->content.collect_s)
// //                 print(game->);
// //             if (game->map[y][x] == game->content.player_s)
// //             {
// //                 game->pos.x = x * game->img.width;
// //                 game->pos.y = y * game->img.height;
// //                 print(game, game->img.img_player, x, y);
// //             }
// //             if (game->map[y][x] == game->content.exit_s)
// //                 print(game, game->img.img_exit, x, y);
// //             x++;
// //         }
// //         x = 0;
// //         y++;
// //     }
//     print(game)
// }

// int render(void *param)
// {
//     t_game *game = (t_game *)param;

//     // Ajoutez un rendu basique ici, par exemple :
//     back_render(game); // Si vous avez une fonction pour dessiner l'arrière-plan.
//     rest_render(game); // Si vous dessinez des éléments de la carte.

//     return (0);
// }

// // int    render(t_game *game)
// // {
// //     back_render(game);
// //     rest_render(game);
// //     return (0);
// // }

// void    back_render(t_game *game)
// {
//     int     i;
//     int     j;

//     i = 0;
//     while (i < game->height && game->map[i] != NULL)
//     {
//         // if (i == game->height - 1)
//         //     break;
//         j= 0;
//         while (j < game->width && game->map[i][j] != '\0')
//         {
//             if (game->map[i][j] == game->content.space_s)
//                 print(game, game->img.img_floor, i , j);
//             if (game->map[i][j] == game->content.wall_s)
//                 print(game, game->img.img_wall, i , j);
//             j++;
//         }
//         i++;
//     }
// }

// void    rest_render(t_game *game)
// {
//     int     x;
//     int     y;

//     x = 0;
//     while (x < game->height && game->map[x] != NULL)
//     {
//         while(y < game->width && game->map[x][y] != '\0')
//         {
//             y = 0;
//             if (game->map[x][y] == game->content.collect_s)
//                 print(game, game->img.img_collect, x, y);
//             if (game->map[x][y] == game->content.player_s)
//             {
//                 game->pos.x = x * game->img.width;
//                 game->pos.y = y * game->img.height;
//                 print(game, game->img.img_player, x, y);   
//             }
//             if (game->map[x][y] == game->content.exit_s)
//                 print(game, game->img.img_exit, x, y);
//             y++;
//         }
//         x++;
//     }
// }

