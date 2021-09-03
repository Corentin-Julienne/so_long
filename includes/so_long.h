/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/02 19:37:56 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct	s_map_err
{
	int			nb_coll;
	int			nb_psp;
	int			nb_exit;
	int			nb_inv_char;
	int			len_line;
	int			nb_rect_error;
	int			nb_err_walls;
}				t_map_err;

// so long

void	initialize_struct(t_map_err *err);

// check_map_validity 1 and 2

void	check_errors(t_map_err *err);
void	map_error_messages(int error_type);

void	is_map_rectangular(const char *line, t_map_err *err);
// void	is_walls(const char *line, t_map_err *err);
void	count_items(const char *line, t_map_err *err);
void	check_map_validity(char **argv, t_map_err *err);

// player_moves

#endif