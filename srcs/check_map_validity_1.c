/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:33 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/02 19:12:05 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_map_rectangular(const char *line, t_map_err *err)
{
	static int	iter = 0;
	int			len;
	
	if (!line)
		return ;
	len = err->len_line;
	err->len_line = (int)ft_strlen(line);
	if (iter != 0)
	{
		if (len != err->len_line)
			err->nb_rect_error++;
	}
	iter++;
}

void	is_walls(const char *line, t_map_err *err)
{
	// TO IMPLEMENT
	if (!line)
		return ;
	return ; // testing purposes, to implement full function after
}

void	count_items(const char *line, t_map_err *err)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		if (line[i] == 'E')
			err->nb_exit++;
		if (line[i] == 'P')
			err->nb_psp++;
		if (line[i] == 'C')
			err->nb_coll++;
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P' 
		&& line[i] != 'E' && line[i] != 'C')
			err->nb_inv_char++;
		i++;
	}	
}

void	check_validity_then_parse(char **argv, t_map_err *err)
{
	char	*next_line;
	int		stop;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error\nfd impossible to read\n");
	next_line = NULL;
	stop = 1;
	while(next_line != NULL || stop == 1)
	{
		stop = 0;
		next_line = get_next_line(fd);
		count_items(next_line, err);
		is_map_rectangular(next_line, err);
		is_wall(next_line, err);
	}
	check_errors(err);
}
