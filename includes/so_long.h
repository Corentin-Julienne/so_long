/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:29 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/20 18:20:24 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h> 

 // gnl buffer (tmp)
# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

// gnl tmp prototypes
char	*ft_protec_strdup(const char *str);
char	*ft_strjoin_and_free(const char *s1, const char *s2);
char	*ft_free_and_return(char **str_to_free, char *rtn_value);
char	*ft_output(ssize_t reader, char	**line, int iter);
char	*ft_cut_rtn(const char *line);
char	*ft_cut_line(ssize_t reader, char *line);
char	*manage_errors(int fd);
char	*get_next_line(int fd);

#endif