/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:55:45 by cjulienn          #+#    #+#             */
/*   Updated: 2022/03/02 12:01:09 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_items(t_map_parse *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->map_arr[j])
	{
		while (map->map_arr[j][i])
		{
			if (map->map_arr[j][i] == 'E')
				map->nb_exit++;
			if (map->map_arr[j][i] == 'P')
				map->nb_psp++;
			if (map->map_arr[j][i] == 'C')
				map->nb_coll++;
			if (map->map_arr[j][i] != '1' && map->map_arr[j][i] != '0'
			&& map->map_arr[j][i] != 'P'
			&& map->map_arr[j][i] != 'E' && map->map_arr[j][i] != 'C')
				map->nb_inv_char++;
			i++;
		}
		i = 0;
		j++;
	}
}

void	is_format_ber(char **argv, t_map_parse *map, int fd)
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
		free(map);
		display_error_message("Map is not in ber format\n");
		close(fd);
		if (fd == -1)
			display_error_message("Fd could not be closed\n");
		exit(1);
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
		free(map->map_arr);
		free(map);
		exit(1);
	}
}

void	map_error_messages(int error_type)
{
	if (error_type == 1)
		ft_printf("Error\nMap not surrounded by walls\n");
	if (error_type == 2)
		ft_printf("Error\nPlayer starting position unexistant or plural\n");
	if (error_type == 3)
		ft_printf("Error\nNo collectible present\n");
	if (error_type == 4)
		ft_printf("Error\nNo exit present\n");
	if (error_type == 5)
		ft_printf("Error\nNon rectangular map\n");
	if (error_type == 6)
		ft_printf("Error\ninvalid character used in map\n");
}
