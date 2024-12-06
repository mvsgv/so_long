/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:30:13 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/06 19:17:43 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game      game;

    if (argc != 2)
    {
        ft_putstr_fd("Error!\nWrong number of arguments\n", 2);
        return (0);
    }
    else
    {
            game.count = 0;
            game.mlx_ptr = mlx_init();
            link_content(&(game.content));
            game.map = map_init(argv, &game);
                printf("here\n");
            if (!game.map)
            {
                img_setup(&game);
               //render_first(&game);             
            }
            // else
            //     ending(&game);
    }
    return (1);
}

