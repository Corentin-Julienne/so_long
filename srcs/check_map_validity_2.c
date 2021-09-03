/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:55:45 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/02 20:03:58 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_format_ber(char **argv,t_map_err *err)
{
	char	*map;
	
	map = argv[1];
	if (!map)
		err->ber_format = 0;
	if (map)
	{
		if (ft_strlen(map >= 5) )
			err->ber_format = 1;
	}
	if (err->ber_format != 1)
	{
		printf("Error\nMap is not in ber format\n");
		free(err);
		exit(0);
	}
}

void	check_errors(t_map_err *err)
{
	if (err->nb_err_walls != 0)
		map_error_messages(1);
	if (err->nb_psp != 1)
		map_error_messages(2);
	if (err->nb_coll <= 0)
		map_error_messages(3);
	if (err->nb_exit <= 0)
		map_error_messages(4);
	if (err->nb_rect_error != 0)
		map_error_messages(5);
	if (err->nb_inv_char != 0)
		map_error_messages(6);
	if (err)
		map_error_messages(7);
	if (err->nb_err_walls != 0 || err->nb_psp != 1 || err->nb_coll <= 0
		|| err->nb_exit <= 0 || err->nb_rect_error != 0
		|| err->nb_inv_char != 0)
	{
		free(err);
		exit(0);
	}
	free(err);
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
