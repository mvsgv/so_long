/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavissar <mavissar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:15 by mavissar          #+#    #+#             */
/*   Updated: 2024/12/01 18:47:08 by mavissar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include "../functions/functions.h"
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
    void    *wall_s; //sprite wall
    void    *exit_s;
    void    *space_s;
    void    *player_s;
    void    *collect_s; 
    void    *counted_p;
    void    *counted_c;
    void    *counted_e;
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


#endif