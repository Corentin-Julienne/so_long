/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/07 16:07:56 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_img
{
	void		*id;
	int			width;
	int			height;
}				t_img;

typedef struct	s_map_parse
{
	int			nb_coll;
	int			nb_psp;
	int			nb_exit;
	int			nb_inv_char;
	int			len_line;
	int			nb_rect_error;
	int			nb_err_walls;
	int			ber_format;
	char		*lines;
	char		**map_arr;
}				t_map_parse;

typedef struct	s_game
{
	void		*mlx;
	void		*wdw;
	t_img		*img_space;
	t_img		*img_wall;
	t_img		*img_coll;
	t_img		*img_exit;
	t_img		*img_psp;
}				t_game;

/* so long */

void	init_map_struct(t_map_parse *map);
void	init_game_struct(t_game *game);

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
void	display_map(t_game *game, int wdw_x, int wdw_y);
void	init_window(t_game *game, t_map_parse *map);
void	init_game(t_map_parse *map);

/* parse map */

void	parser_map(const char *line, int nb_of_lines, t_map_parse *map);

/* utils */

char	*get_all_lines(int fd);
void	display_error_message(char	*error_message);

#endif