/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:38:00 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/06 12:44:52 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

/* get_all_lines takes a fd as input and convert it to a single char 
(malloqued) by using the read function
, or NULL if it fails a malloc or cannnot read */

char	*ft_free_and_return(char **str_to_free, char *rtn_value)
{
	if (*str_to_free)
	{
		free(*str_to_free);
		*str_to_free = NULL;
	}
	return (rtn_value);
}

char	*ft_strjoin_and_free(const char *s1, const char *s2)
{
	char			*copy;
	size_t			i;
	size_t			j;

	if (!s1 || !s2)
		return (NULL);
	copy = malloc((strlen(s1) + strlen(s2) + 1) * (sizeof(char)));
	if (!(copy))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		copy[i++] = s2[j++];
	copy[i] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (copy);
}

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
			rtn = strdup("");
		rtn = ft_strjoin_and_free(rtn, buffer);
		if (!rtn)
			ft_free_and_return(&rtn, NULL);
	}
	free(buffer);
	return (rtn);
}

int main(int argc, char **argv)
{
	char 	*res;
	int		fd;
	
	if (argc != 2)
	{
		printf("Wrong number of arguments\n");
		exit (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("fd could no be openned\n");
		exit (0);
	}
	res = get_all_lines(fd);
	printf("%s\n", res);
	return (0);
}
