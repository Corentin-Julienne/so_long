/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:59:39 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/20 18:10:06 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

char	*ft_protec_strdup(const char *str)
{
	char				*copy;
	unsigned long		sizer;
	int					i;

	if (!str)
		return (NULL);
	sizer = strlen(str) + 1;
	copy = malloc(sizer * (sizeof(char)));
	if (!(copy))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin_and_free(const char *s1, const char *s2)
{
	char			*copy;
	size_t			i;
	size_t			j;

	if (!s1)
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

char	*ft_free_and_return(char **str_to_free, char *rtn_value)
{
	if (*str_to_free)
	{
		free(*str_to_free);
		*str_to_free = NULL;
	}
	return (rtn_value);
}

char	*ft_output(ssize_t reader, char	**line, int iter)
{
	char	*rtn;

	if (reader < 0)
		return (NULL);
	if (reader == 0 && *line && *line[0] == '\0')
	{
		if (iter > 0)
		{
			free((void *)*line);
			*line = NULL;
		}	
		return (NULL);
	}
	rtn = ft_cut_rtn(*line);
	if (!rtn)
		return (NULL);
	*line = ft_cut_line(reader, *line);
	if (reader > 0 || (reader == 0 && *line == NULL))
		return (rtn);
	else
		return (NULL);
}

char	*ft_cut_rtn(const char *line)
{
	size_t	malloc_size;
	size_t	i;
	size_t	ln_rtn;
	char	*cutted_line;

	malloc_size = 0;
	ln_rtn = 0;
	if (strchr(line, '\n'))
		ln_rtn++;
	while (line[malloc_size] != '\n' && line[malloc_size])
		malloc_size++;
	cutted_line = (char *)malloc(sizeof(char) * (malloc_size + 1 + ln_rtn));
	if (!cutted_line)
		return (NULL);
	i = 0;
	while (line[i] && malloc_size > 0)
	{
		cutted_line[i] = line[i];
		i++;
		malloc_size--;
	}
	cutted_line[i + ln_rtn] = '\0';
	if (ln_rtn > 0)
		cutted_line[i] = '\n';
	return (cutted_line);
}

char	*ft_cut_line(ssize_t reader, char *line)
{
	char	*cutted_stc;

	if (!line)
		return (NULL);
	if (reader == 0)
	{
		free((void *)line);
		line = NULL;
		return (NULL);
	}
	if (strchr(line, '\n') && strlen(strchr(line, '\n')) > 1)
		cutted_stc = ft_protec_strdup(strchr(line, '\n') + 1);
	else if (strchr(line, '\n') && strlen(strchr(line, '\n')) == 1)
		cutted_stc = ft_protec_strdup("");
	else
		cutted_stc = ft_protec_strdup(line);
	free((void *)line);
	line = NULL;
	if (!cutted_stc)
		return (NULL);
	return (cutted_stc);
}

char	*manage_errors(int fd)
{
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*line = NULL;
	static int		iter = -1;
	char			*buffer;
	ssize_t			reader;

	iter++;
	buffer = manage_errors(fd);
	if (!buffer)
		return (NULL);
	reader = 1;
	while (strchr(line, '\n') == NULL && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			break ;
		buffer[reader] = '\0';
		if (!line)
			line = ft_protec_strdup("");
		line = ft_strjoin_and_free(line, buffer);
		if (!line)
			return (ft_free_and_return(&buffer, NULL));
	}
	free(buffer);
	return (ft_output(reader, &line, iter));
}
