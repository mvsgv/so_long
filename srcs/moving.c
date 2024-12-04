/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:27:49 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/03 18:04:17 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// void    move_left(t_game *game)
// {
//     int     pos_x;
//     int     pos_y;

//     pos_x = game->pos.x / game->img.height;
//     pos_y = game->pos.y / game->img.width;
//     if (game->map[pos_x][pos_y - 1] != game->content.wall_s)
//     {
//         if (!(game->map[pos_x][pos_y - 1] == game->content.exit_s))
//         {
//             printf("Debug: Moving left to x = %d, y = %d\n", pos_x - 1, pos_y);
//             game->map[pos_x][pos_y - 1] = game->content.player_s;
//             game->map[pos_x][pos_y] = game->content.space_s;
//             game->count += 1;
//         }
//         else 
//         {
//             if (collected(game) == 0)
//             {
//                 ending(game);
//             }
//         }
//     }
// }

// void    move_right(t_game *game)
// {
//     int     pos_x;
//     int     pos_y;

//     pos_x = game->pos.x / game->img.height;
//     pos_y = game->pos.y / game->img.width;
//     if (game->map[pos_x][pos_y - 1] != game->content.wall_s)
//     {
//         if (!(game->map[pos_x][pos_y + 1] == game->content.exit_s))
//         {
//             game->map[pos_x][pos_y + 1] = game->content.player_s;
//             game->map[pos_x][pos_y] = game->content.space_s;
//             game->count += 1;
//         }
//         else 
//         {
//             if (collected(game) == 0)
//             {
//                 ending(game);
//             }
//         }
//     }
// }
// void    move_down(t_game *game)
// {
//     int     pos_x;
//     int     pos_y;

//     pos_x = game->pos.x / game->img.height;
//     pos_y = game->pos.y / game->img.width;
//     if (game->map[pos_x + 1][pos_y] != game->content.wall_s)
//     {
//         if (!(game->map[pos_x + 1][pos_y] == game->content.exit_s))
//         {
//             game->map[pos_x + 1][pos_y] = game->content.player_s;
//             game->map[pos_x][pos_y] = game->content.space_s;
//             game->count += 1;
//         }
//         else 
//         {
//             if (collected(game) == 0)
//             {
//                 ending(game);
//             }
//         }
//     }
// }

// void    move_up(t_game *game)
// {
//     int     pos_x;
//     int     pos_y;

//     pos_x = game->pos.x / game->img.height;
//     pos_y = game->pos.y / game->img.width;
//     if (game->map[pos_x - 1][pos_y] != game->content.wall_s)
//     {
//         if (!(game->map[pos_x - 1][pos_y] == game->content.exit_s))
//         {
//             game->map[pos_x - 1][pos_y] = game->content.player_s;
//             game->map[pos_x][pos_y] = game->content.space_s;
//             game->count += 1;
//         }
//         else 
//         {
//             if (collected(game) == 0)
//             {
//                 ending(game);
//             }
//         }
//     }
// }

