/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:55:45 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/05 19:17:10 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_format_ber(char **argv, t_map_parse *map)
{
	char	*title;
	int		length;

	title = argv[1];
	if (!title)
		map->ber_format = 0;
	else
	{
		length = ft_strlen(title);
		if (length < 5)
			map->ber_format = 0;
		else if (ft_strncmp(title + (length - 4), ".ber", 4) != 0)
			map->ber_format = 0;
	}
	if (map->ber_format != 1)
	{
		printf("Error\nMap is not in ber format\n");
		free(map);
		exit(0);
	}
}

void	check_errors(t_map_parse *map)
{
	if (map->nb_err_walls != 0)
		map_error_messages(1);
	if (map->nb_psp != 1)
		map_error_messages(2);
	if (map->nb_coll <= 0)
		map_error_messages(3);
	if (map->nb_exit <= 0)
		map_error_messages(4);
	if (map->nb_rect_error != 0)
		map_error_messages(5);
	if (map->nb_inv_char != 0)
		map_error_messages(6);
	if (map)
		map_error_messages(7);
	if (map->nb_err_walls != 0 || map->nb_psp != 1 || map->nb_coll <= 0
		|| map->nb_exit <= 0 || map->nb_rect_error != 0
		|| map->nb_inv_char != 0)
	{
		free(map);
		exit(0);
	}
}

void	map_error_messages(int error_type)
{
	if (error_type == 1)
		printf("Error\nMap not surrounded by walls\n");
	if (error_type == 2)
		printf("Error\nPlayer starting position unexistant or plural\n");
	if (error_type == 3)
		printf("Error\nNo collectible present\n");
	if (error_type == 4)
		printf("Error\nNo exit present\n");
	if (error_type == 5)
		printf("Error\nNon rectangular map\n");
	if (error_type == 6)
		printf("Error\ninvalid character used in map\n");
}
