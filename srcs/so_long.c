/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:30:13 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/01 18:45:11 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game      game;

    if (argc != 2)
    {
        ft_putstr_fd("Error!\nWrong number of arguments\n", 2);
        return (1);
    }
    else
    {
            game.count = 0;
            game.mlx_ptr = mlx_init();
            link_content(&(game.content));
            game.map = map_init(argv, &game);
            if (!game.map)
            {
                img_setup(&game);                
            }
            
    }
    return (1);
}

