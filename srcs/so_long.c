/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:38 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/07 11:41:14 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_struct(t_map_parse *map)
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

int	main(int argc, char **argv)
{
	t_map_parse	*map;

	if (argc != 2)
		display_error_message("Wrong number of arguments !\n");
	map = (t_map_parse *)malloc(sizeof(t_map_parse));
	if (!map)
		display_error_message("struct failed to be created\n");
	initialize_struct(map);
	check_map_validity(argv, map);
	printf("Seems to be working :)\n");
	init_game(map);
	return (0);
}
