/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:33 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/06 14:18:01 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_map_rectangular(t_map_parse *map)
{
	int		j;
	int		len;
	int		previous_len;

	j = 1;
	previous_len = ft_strlen(map->map_arr[0]);
	while (map->map_arr[j])
	{
		len = ft_strlen(map->map_arr[j]);
		if (len != previous_len)
			map->nb_rect_error++;
		previous_len = len;
		j++;
	}
}

void	is_intermediate_walls(t_map_parse *map)
{
	int		len;
	int		j;

	j = 1;
	len = ft_strlen(map->map_arr[0]);
	while (map->map_arr[j])
	{
		if (map->map_arr[j][0] != '1')
			map->nb_err_walls++;
		if (map->map_arr[j][len - 1] != '1')
			map->nb_err_walls++;
		j++;
	}
}

void	is_walls(t_map_parse *map)
{
	int		i;
	int		num_len;

	if (map->nb_rect_error != 0)
		return ;
	i = 0;
	num_len = 0;
	while (map->map_arr[num_len])
		num_len++;
	while (map->map_arr[0][i])
	{
		if (map->map_arr[0][i] != '1')
			map->nb_err_walls++;
		i++;
	}
	i = 0;
	while (map->map_arr[num_len - 1][i])
	{
		if (map->map_arr[num_len - 1][i] != '1')
			map->nb_err_walls++;
		i++;
	}
	is_intermediate_walls(map);
}

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

void	check_map_validity(char **argv, t_map_parse *map)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		display_error_message("fd impossible to read\n");
	is_format_ber(argv, map);
	map->lines = get_all_lines(fd);
	if (!map->lines)
		display_error_message("Error while parsing map\n");
	if (close(fd) == -1)
		display_error_message("fd could not be closed\n");
	map->map_arr = ft_split(map->lines, '\n');
	if (!map->map_arr)
		display_error_message("ft_split failed\n");
	free(map->lines);
	is_map_rectangular(map);
	is_walls(map);
	count_items(map);
	check_errors(map);
}
