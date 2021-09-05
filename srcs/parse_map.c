/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:01:33 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/05 16:29:39 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	parser_map(const char *line, int nl_of_lines, t_map_parse *map)
{	
	if (!line)
		return ;
	if (nl_of_lines == 0)
	{
		map->lines = ft_strjoin(line, '\n');
		return ;
	}
	map->lines = ft_strjoin_and_free(map->lines, line);
	map->lines = ft_strjoin_and_free(map->lines, '\n');
}