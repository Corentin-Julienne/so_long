/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/10 17:23:42 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_img
{
	void			*id;
	int				width;
	int				height;
}					t_img;

typedef struct s_pl_coord
{
	int				j;
	int				i;
}					t_pl_coord;

typedef struct s_map_parse
{
	int				nb_coll;
	int				nb_psp;
	int				nb_exit;
	int				nb_inv_char;
	int				len_line;
	int				nb_rect_error;
	int				nb_err_walls;
	int				ber_format;
	char			*lines;
	char			**map_arr;
}					t_map_parse;

typedef struct s_game
{
	void			*mlx;
	void			*wdw;
	int				wdw_x;
	int				wdw_y;
	t_img			*img_space;
	t_img			*img_wall;
	t_img			*img_coll;
	t_img			*img_exit;
	t_img			*img_psp;
	char			**map;
	int				total_moves;
	int				nb_coll;
	t_pl_coord		*coord;
}					t_game;

/* check map_validity 1 and 2 */

void	is_map_rectangular(t_map_parse *map);
void	is_walls(t_map_parse *map);
void	count_items(t_map_parse *map);
void	check_map_validity(char **argv, t_map_parse *map);

void	check_errors(t_map_parse *map);
void	map_error_messages(int error_type);
void	is_format_ber(char **argv, t_map_parse *map);

/* init game */

void	init_textures(t_game *game);
void	load_textures(t_game *game, t_img **image, char *path);
void	init_window(t_game *game);
void	init_game(t_map_parse *map);

/* init_structs */

void	init_map_struct(t_map_parse *map);
void	init_game_struct(t_game *game, t_map_parse *map);
void	init_coord_struct(t_game *game, t_pl_coord *coord);

/* display map */

void	fulfill_wdw(t_game *game, int x, int y);
void	display_map(t_game *game, int wdw_x, int wdw_y);
void	floor_wdw(t_game *game, int wdw_x, int wdw_y);

/* player inputs */

int		key_hook(int keycode, t_game **game);
void	quit_game(t_game *game);

/* player moves */

void	move_player(t_game *game, int keycode);
int		is_obstacle(t_game *game, int keycode);
void	update_coord(t_game *game, int keycode);
void	change_player_pos(t_game *game, int keycode);
void	handle_coll(t_game *game);
void	handle_exit_pos(t_game *game);

/* utils */

char	*get_all_lines(int fd);
void	display_error_message(char *error_message);
void	free_images(t_game *game, int num_img);

#endif
