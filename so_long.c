/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:30:13 by mavissar          #+#    #+#             */
/*   Updated: 2024/11/20 16:59:35 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;   

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, size_x, size_y, "first_window");
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    free(mlx_ptr);
}