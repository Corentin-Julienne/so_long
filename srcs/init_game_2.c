/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 12:29:26 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/06 17:06:14 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_game *game, t_img **image, char *path, int iter)
{
	int		width;
	int		height;

	(*image)->id = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!((*image)->id))
	{
		display_error_message("Failed to import img from xpm file\n");
		if (iter == 1)
			free(game->img_space);
		else
			free_images(game, iter);
		free(game->map->map_arr);
		free(game->map);
		free(game);
		exit(EXIT_FAILURE);
	}
	(*image)->width = width;
	(*image)->height = height;
}

void	init_textures(t_game *game)
{	
	load_textures(game, &game->img_space, "./imgs/sand.xpm", 1);
	load_textures(game, &game->img_wall, "./imgs/wall.xpm", 2);
	load_textures(game, &game->img_psp, "./imgs/player.xpm", 3);
	load_textures(game, &game->img_coll, "./imgs/gas.xpm", 4);
	load_textures(game, &game->img_exit, "./imgs/helicopter.xpm", 5);
}
