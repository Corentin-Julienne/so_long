/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:38 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/07 15:39:14 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_map_struct(t_map_parse *map)
{
	map->nb_coll = 0;
	map->nb_psp = 0;
	map->nb_exit = 0;
	map->nb_inv_char = 0;
	map->len_line = 0;
	map->nb_rect_error = 0;
	map->nb_err_walls = 0;
	map->ber_format = 1;
}

void	init_game_struct(t_game *game)
{	
	game->img_space = (t_img *)malloc(sizeof(t_img));
	if (!game->img_space)
		display_error_message("malloc failed in game struct\n");
	game->img_wall = (t_img *)malloc(sizeof(t_img));
	if (!game->img_wall)
		display_error_message("malloc failed in game struct\n");
	game->img_psp = (t_img *)malloc(sizeof(t_img));
	if (!game->img_psp)
		display_error_message("malloc failed in game struct\n");
	game->img_coll = (t_img *)malloc(sizeof(t_img));
	if (!game->img_coll)
		display_error_message("malloc failed in game struct\n");
	game->img_exit = (t_img *)malloc(sizeof(t_img));
	if (!game->img_exit)
		display_error_message("malloc failed in game struct\n");
}

int	main(int argc, char **argv)
{
	t_map_parse	*map;

	if (argc != 2)
		display_error_message("Wrong number of arguments !\n");
	map = (t_map_parse *)malloc(sizeof(t_map_parse));
	if (!map)
		display_error_message("struct failed to be created\n");
	init_map_struct(map);
	check_map_validity(argv, map);
	init_game(map);
	return (0);
}
