/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:30:13 by mavissar          #+#    #+#             */
/*   Updated: 2024/11/29 17:53:57 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx.h"

int main(int argc, char **argv)
{
    t_game      game;

    if (argc != 2)
    {
        ft_putstr_fd("Error!\nWrong number of arguments\n", 2);
        return (1);
    }
    if (!game_create(&game, argv[1]))
    {
        ft_putstr_fd("Error!\nCan't initialize the game :(\n", 2);
        return (1);
    }
    mlx_loop_hook(game.mlx, render_game, &game);
    mlx_loop(game.mlx);
    return (0);
}
