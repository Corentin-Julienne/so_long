/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:07:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/06 12:59:57 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* get_all_lines takes a fd as input and convert it to a single char 
(malloqued) by using the read function
, or NULL if it fails a malloc or cannnot read */

char	*get_all_lines(int fd)
{
	char		*rtn;
	char		*buffer;
	ssize_t		reader;

	rtn = NULL;
	buffer = (char *)malloc(sizeof(char) * 2);
	if (!buffer)
		return (NULL);
	reader = 1;
	while (reader > 0)
	{
		reader = read(fd, buffer, 1);
		if (reader < 0)
			ft_free_and_return(&buffer, NULL);
		if (reader == 0)
			break ;
		buffer[1] = '\0';
		if (!rtn)
			rtn = ft_protec_strdup("");
		rtn = ft_strjoin_and_free(rtn, buffer);
		if (!rtn)
			ft_free_and_return(&rtn, NULL);
	}
	free(buffer);
	return (rtn);
}

/* display an error message and exit the programm while failure of any type */

void	display_error_message(char	*error_message)
{
	char	*prefix;
	char	*message;

	prefix = "Error\n";
	message = ft_strjoin(prefix, error_message);
	printf("%s", message);
	free(message);
	exit (0);
}
