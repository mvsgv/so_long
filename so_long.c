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
int main(void)
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
t_asset asset;
// Initialisation de la bibliothèque mlx
asset.mlx = mlx_init();
if (tasset.mlx)
return (1);
// Création de la fenêtre (800x600 ici, vous pouvez ajuster les dimensions) asset-win = mlx_new_window(asset.mlx, 800, 600, "Fenêtre avec image");
if (lasset.win)
return (1);
// Charger une image XPM
asset. img = mlx_xpm_file_to_image(asset.mlx,
if (lasset.img)
"asset/sp-xpm", sasset.img_width,
Sgsset. img_height) ;
mlx_ destroy_window(asset.mlx, asset.win);
return (1);
// Afficher l'image dans la fenêtre, à la position (0, 0)
mix_put_image_to_window(asset.mx, asset.win, asset.img, 0, 0);
// Gérer la fermeture de la fenêtre
mx hook(asset.win, 17, 0, close_window, &asset);
// Lancer la boucle principale de la bibliothèque mlx
mlx_loop (asset.mlx) ;
53
return (0);
AA FUNCTION LINES: 30 44

