/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:15 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/02 18:58:48 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../functions/functions.h"

# define KEY_ESCAPE 53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_UP		126
# define KEY_DOWN	125
# define KEY_RIGHT	124
# define KEY_LEFT	123
// # include "Libft/libft.h"
                                /*IMAGE STRUCTURE*/
typedef struct s_img_str
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img_str;
                                /*SPRITES ON MAP*/
typedef struct s_map_content
{
    char    wall_s; //sprite wall
    char    exit_s;
    char    space_s;
    char    player_s;
    char    collect_s; 
    int	   counted_p;
    int    counted_c;
    int    counted_e;
    }           t_map_content;
                                /*GAME CORE DATA*/
typedef struct pos_s
{
	int		x;
	int		y;
}				t_pos;
                            /*STRUCUTRE OF MAP CONTENT*/
typedef struct s_game
{
	void	        *mlx_ptr;
	void	        *mlx_win;
	int		        width;
	int		        height;
	char        	**map;
	t_map_content	content;
	t_img_str	    img;
	t_pos	        pos;
	int	        	count;
}				t_game;

int     load_map(t_game *game, char *map_file);
void    link_content(t_map_content *content);
void    img_setup(t_game *game);
char    **map_init(char **argv, t_game *game);
char    *get_map(int fd);
void	content_checker(t_game *game);
int		lines_checker(char *line, char wall);
int		format_checker(char **map);
int     column_checker(char *line, char wall, t_game *game);
int     good_behavior_checker(char *line, t_map_content *x);
void    *free_map(t_game *game);
void	*ft_error(char *str);
void    print(t_game *game, void *img, int x, int y);
int   	render(t_game *game);
void    render_second(t_game *game);
void    render_first(t_game *game);
void    back_render(t_game *game);
void    rest_render(t_game *game);
int     ending(t_game *game);
int     collected(t_game *game);

void    move_up(t_game *game, t_pos x, t_pos y);
void    move_down(t_game *game, t_pos x, t_pos y);
void    move_right(t_game *game, t_pos x, t_pos y);
void    move_left(t_game *game, t_pos x, t_pos y);
#endif