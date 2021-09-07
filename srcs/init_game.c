/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:03:25 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/07 12:00:00 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"


void	load_textures(t_game *game, t_img **image, char *path)
{
	int		width;
	int		height;

	(*image)->id = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	printf("go to there\n");
	(*image)->width = width;
	printf("go to there\n");
	(*image)->height = height; 
}

void	init_textures(t_game *game) // does not work (seg fault sa race)
{	
	printf("bite\n");
	load_textures(game, &game->img_space, "../imgs/sand.xpm");
	printf("double bite\n");
	load_textures(game, &game->img_wall, "../imgs/wall.xpm");
	load_textures(game, &game->img_psp, "../imgs/player.xpm");
	load_textures(game, &game->img_coll, "../imgs/gas.xpm");
	load_textures(game, &game->img_exit, "../imgs/helicopter.xpm");
	
}

void	display_map(t_game *game, int wdw_x, int wdw_y)
{
	int x = 0;
	int y = 0;
	
	while (y < wdw_y)
	{
		while (x < wdw_x)
		{
			mlx_put_image_to_window(game->mlx, game->wdw, game->img_space->id, x, y);
			x += game->img_space->width;
		}
		x = 0;
		y += game->img_space->height;
	}
}

void	init_window(t_game *game, t_map_parse *map)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (map->map_arr[i])
	{
		y+= game->img_space->height;
		i++;
	}
	x+= ft_strlen(map->map_arr[0]) * game->img_space->width;
	game->wdw = mlx_new_window(game->mlx, x, y, "so long");
	display_map(game, x, y);
}

void	init_game(t_map_parse *map)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		free(map);
		display_error_message("Malloc error during the allocation of t_game struct\n");
	}
	game->img_space = 0;
	game->mlx = mlx_init();
	init_textures(game);
	init_window(game, map);
	// add link to gameplay func here before loop
	mlx_loop(game->mlx); // should be the last function of the prog
}
