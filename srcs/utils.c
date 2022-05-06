/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:07:29 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/06 17:10:17 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* get_all_lines takes a fd as input and convert it to a single char 
(malloqued) by using the read function, 
or NULL if it fails a malloc or cannnot read */

char	*get_all_lines(int fd)
{
	char	*next_line;
	char	*all_lines;
	char	*tmp;

	all_lines = NULL;
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		if (!all_lines)
			all_lines = ft_protec_strdup(next_line);
		else
		{
			tmp = ft_strjoin(all_lines, next_line);
			if (tmp)
				free(all_lines);
			all_lines = tmp;
		}
		if (!all_lines)
			return (NULL);
	}
	return (all_lines);
}

// char	*get_all_lines(int fd) // change that
// {
// 	char		*rtn;
// 	char		*buffer;
// 	ssize_t		reader;

// 	rtn = NULL;
// 	buffer = (char *)malloc(sizeof(char) * 2);
// 	if (!buffer)
// 		return (NULL);
// 	reader = 1;
// 	while (reader > 0)
// 	{
// 		reader = read(fd, buffer, 1);
// 		if (reader < 0)
// 			ft_free_and_return(&buffer, NULL);
// 		if (reader == 0)
// 			break ;
// 		buffer[1] = '\0';
// 		if (!rtn)
// 			rtn = ft_protec_strdup("");
// 		rtn = ft_strjoin_and_free(rtn, buffer);
// 		if (!rtn)
// 			ft_free_and_return(&rtn, NULL);
// 	}
// 	free(buffer);
// 	return (rtn);
// }

/* display an error message while failure of any type (on STDERR)*/

void	display_error_message(char	*error_message)
{
	char	*prefix;

	prefix = "Error : ";
	ft_putstr_fd(prefix, STDERR_FILENO);
	ft_putstr_fd(error_message, STDERR_FILENO);
}

/* free image previously malloqued in case of malloc error 
or when about to exit the program */

void	free_images(t_game *game, int num_img)
{
	free(game->img_space);
	free(game->img_wall);
	if (num_img == 3)
		free(game->img_psp);
	if (num_img == 4)
	{
		free(game->img_psp);
		free(game->img_coll);
	}
	if (num_img == 5)
	{
		free(game->img_psp);
		free(game->img_coll);
		free(game->img_exit);
	}
}

/* free split is used for freeing an array of str
when every str is also malloqued */

void	free_split(char **split)
{
	int		len;
	int		i;

	len = 0;
	while (split[len])
		len++;
	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
