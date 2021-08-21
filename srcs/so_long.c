/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:38 by cjulienn          #+#    #+#             */
/*   Updated: 2021/08/20 18:28:59 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	int	map_err;
	
	if (argc != 2)
		printf("Error ! Wrong number of arguments !\n"); // changer message erreur
	map_err = check_if_map_valid(argv);
	if (map_err != 0)
		return (-1); // mistake
	return (0);
}
