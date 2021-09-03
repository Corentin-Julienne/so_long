/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:38 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/02 19:40:13 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_struct(t_map_err *err)
{
	err->nb_coll = 0;
	err->nb_psp = 0;
	err->nb_exit = 0;
	err->nb_inv_char = 0;
	err->len_line = 0;
	err->nb_rect_error = 0;
	err->nb_err_walls = 0;
}

int	main(int argc, char **argv)
{
	t_map_err	*err;

	if (argc != 2)
	{
		printf("Error\nWrong number of arguments !\n");
		return (-1);
	}
	err = (t_map_err *)malloc(sizeof(t_map_err));
	if (!err)
		return (-1);
	initialize_struct(err);
	check_map_validity(argv, err);
	// go this far if map is valid only
	return (0);
}
