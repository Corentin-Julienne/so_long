/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:33 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/03 16:50:50 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_map_rectangular(const char *line, int nl_of_lines, t_map_parse *map)
{
	int	len;

	if (!line)
		return ;
	len = map->len_line;
	map->len_line = (int)ft_strlen(line);
	if (nl_of_lines != 0)
	{
		if (len != map->len_line)
			map->nb_rect_error++;
	}
}

void	is_walls(const char *line, int nl_of_lines, t_map_parse *map)
{
	int	i;
	int	len;
	
	if (!line)
		return ;
	i = 0;
	while (line[i] && nl_of_lines == 0)
	{
		if (line[i] != '1')
			map->nb_err_walls++;
		i++;
	}
	len = ft_strlen(line);
	if (nl_of_lines != 0)
	{
		if (line[0] != '1')
			map->nb_err_walls++;
		if (line[len - 1] != '1')
			map->nb_err_walls++;
	}
}

void	is_last_wall(const char *line, int nl_of_lines, t_map_parse *map)
{
	if (!line)
		return;
	// TO IMPLEMENT
}

void	count_items(const char *line, t_map_parse *map)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		if (line[i] == 'E')
			map->nb_exit++;
		if (line[i] == 'P')
			map->nb_psp++;
		if (line[i] == 'C')
			map->nb_coll++;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' 
		&& line[i] != 'E' && line[i] != 'C')
			map->nb_inv_char++;
		i++;
	}	
}

void	check_map_validity(char **argv, t_map_parse *map)
{
	char	*next_line;
	int		nl_of_lines;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error\nfd impossible to read\n");
	is_format_ber(argv, map);
	next_line = NULL;
	nl_of_lines = -1;
	while(next_line != NULL || nl_of_lines == -1)
	{
		nl_of_lines++;
		next_line = get_next_line(fd);
		count_items(next_line, map);
		is_map_rectangular(next_line, nl_of_lines, map);
		is_wall(next_line, nl_of_lines, map);
		parser_map(next_line, map);
	}
	is_last_wall(nl_of_lines, nl_of_lines, map); // TODO
	check_errors(map);
}
