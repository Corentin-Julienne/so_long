/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:03:25 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/10 14:11:55 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_textures(t_game *game, t_img **image, char *path)
{
	int		width;
	int		height;

	(*image)->id = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	if (!((*image)->id))
		display_error_message("img failed to import from xpm file\n");
	(*image)->width = width;
	(*image)->height = height;
}

void	init_textures(t_game *game)
{	
	load_textures(game, &game->img_space, "./imgs/sand.xpm");
	load_textures(game, &game->img_wall, "./imgs/wall.xpm");
	load_textures(game, &game->img_psp, "./imgs/player.xpm");
	load_textures(game, &game->img_coll, "./imgs/gas.xpm");
	load_textures(game, &game->img_exit, "./imgs/helicopter.xpm");
}

void	init_window(t_game *game)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (game->map[i])
	{
		y += game->img_space->height;
		i++;
	}
	x += ft_strlen(game->map[0]) * game->img_space->width;
	game->wdw_x = x;
	game->wdw_y = y;
	game->wdw = mlx_new_window(game->mlx, x, y, "so_long");
	display_map(game, x, y);
}

void	init_game(t_map_parse *map)
{
	t_game			*game;
	t_pl_coord		*coord;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(map);
		display_error_message("Malloc error (allocation of t_game_struct)\n");
	}
	init_game_struct(game, map);
	free(map);
	game->mlx = mlx_init();
	init_textures(game);
	init_window(game); // couille
	coord = (t_pl_coord *)malloc(sizeof(t_pl_coord));
	if (!coord)
	{
		free_images(game, 5);
		free(game);
		display_error_message("Malloc error (allocation of t_player_coord)\n");
	}
	init_coord_struct(game, coord);
	// ok till this point
	mlx_key_hook(game->wdw, key_hook, &game);
	mlx_loop(game->mlx);
}
