/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/03 16:52:43 by cjulienn         ###   ########.fr       */
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

// so long

void	initialize_struct(t_map_parse *err);

// check_map_validity 1 and 2

void	check_errors(t_map_parse *err);
void	map_error_messages(int error_type);

void	is_map_rectangular(const char *line, int nl_of_lines, t_map_parse *map);
// void	is_walls(const char *line, t_map_err *err);
void	count_items(const char *line, t_map_parse *err);
void	check_map_validity(char **argv, t_map_parse *err);

// player_moves

#endif