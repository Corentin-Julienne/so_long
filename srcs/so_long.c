/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:38 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/06 18:02:33 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_map_parse	*map;

	if (argc != 2)
	{
		display_error_message("Wrong number of arguments !\n");
		exit(1);
	}
	map = (t_map_parse *)malloc(sizeof(t_map_parse));
	if (!map)
	{
		display_error_message("Struct failed to be created\n");
		exit(1);
	}
	init_map_struct(map);
	check_map_validity(argv, map);
	init_game(map);
	return (0);
}
