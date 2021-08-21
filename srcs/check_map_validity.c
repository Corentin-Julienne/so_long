/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:33 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/21 12:36:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// permet de voir si la map est valide

void	map_error_messages(int error_type) // change error message
{
	if (error_type == 1) // when blank spaces
		printf("Blank spaces within the map\n"); 
	if (error_type == 2) // when not surrounded by walls
		printf("Map not surrounded by walls\n");
	if (error_type == 3) // several or non starting position present
		printf("Player starting position unexistant or plural\n");
	if (error_type == 4) // no collectible present
		printf("No collectible present\n");
	if (error_type == 5) // no exit present
		printf("No exit present\n");
	if (error_type == 6) // non rectangular map
		printf("Non rectangular map\n");
	if (error_type == 7)
		printf("invalid character used in map\n");
}

int	check_if_map_rectangular(char *line)
{
	static int	line_len = 0;
	static int	errors = 0;
	int			i;
	size_t		current_line_len;

	current_line_len = strlen(line);
	if (line_len = 0)
		line_len = current_line_len;
	else
	{
		if (current_line_len != line_len)
			errors++;
	}
	return (errors);	
}

int	check_if_walls(char *line) // find a wy to find if next line is full of 1
{
	static int	line_nbr = 0;
	static int	breaches = 0;
	int 		i;
	
	if (!line)
		return (breaches);
	i = 0;
	while (line_nbr == 0 && line[i])
	{
		if (line[i] != '1')
			breaches++;
		i++;
	}
	if (line_nbr != 0)
	{
		if (line[0] != '1')
			breaches++;
		if (line[strlen(line) - 1] != '1')
			breaches++;
	}
	// check if map last line is fill of 1
	line_nbr++;
	return (breaches);
}

int	check_if_coll(char *line)
{
	static int	coll_num = 0;
	int			i;
	
	if (!line)
		return (coll_num);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			coll_num++;
		i++;
	}
	return (coll_num);
}

int	check_if_exit(char *line)
{
	static int	exit_num = 0;
	int			i;
	
	if (!line)
		return (exit_num);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			exit_num++;
		i++;
	}
	return (exit_num);
}

int check_if_starting_pos(char *line)
{
	static int	sp_num = 0;
	int			i;
	
	if (!line)
		return (sp_num);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			sp_num++;
		i++;
	}
	return (sp_num);
}

int	check_invalid_char(char *line)
{
	static int	inval_char = 0;
	int			i;
	
	if (!line)
		return (inval_char);
	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			inval_char++;
		i++;
	}
	return (inval_char);
}

int	check_if_blank_space(char *line)
{
	static int	bl_sp = 0;
	int			i;
	
	if (!line)
		return (bl_sp);
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			bl_sp++;
		i++;
	}
	return (bl_sp);
}

void	check_errors(char *line)
{
		
}

int	check_if_map_valid(char **argv) // use gnl to read every line of the map
{
	char	*next_line;
	int		stop;
	int		fd;
	int		error;

	fd = open(argv[1], O_RDONLY); // open map to use gnl
	if (fd == -1)
		printf("fd impossible to read\n"); // change error message
	next_line = NULL;
	error = 0;
	stop = 1; // enter in the loop
	while(next_line != NULL || stop == 1)
	{
		stop = 0; // stop the entry if next_line == NULL
		next_line = get_next_line(fd); // read_line
		check_if_blank_space(next_line);
		check_invalid_char(next_line);
		check_if_starting_pos(next_line);
		check_if_exit(next_line);
		check_if_coll(next_line);
		check_if_map_rectangular(next_line);
	}
	check_errors(next_line);
	return (0); // if map valid
}
