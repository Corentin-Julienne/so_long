/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:33 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/20 18:51:19 by cjulienn         ###   ########.fr       */
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
}

int	check_if_blank_space(char *line) // check if blank space in every line
{
	int	blank_spaces;
	int	i;

	blank_spaces = 0;
	i = 0;
	if (!line) // if line == NULL (pas de map ou ligne en trop)
		return (1);
	while (line[i])
	{
		if (line[i] = ' ')
			blank_spaces++;
		i++;
	}
	if (blank_spaces > 0)
	{
		map_error_messages(1); // print error message
		return (1); // return 1 if blank space
	}
	return (0);	
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
	while(next_line != NULL && stop == 0)
	{
		stop = 0; // stop the entry if next_line == NULL
		next_line = get_next_line(fd); // read_line
		if (check_if_blank_space(next_line) == 1)
			error++;
		if ()
			error++;
	}
	return (0); // if map valid
}
