/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:03:25 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/05 18:51:25 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	load_textures(t_game *game)
{	
	game->img_space->id = mlx_xpm_file_to_image(game->mlx,
 "../imgs/sand.xpm", &game->img_space->width, &game->img_space->height);
	game->img_wall->id = mlx_xpm_file_to_image(game->mlx, 
"../imgs/wall.xpm", &game->img_wall->width, &game->img_wall->height);
	game->img_psp->id = mlx_xpm_file_to_image(game->mlx, 
"../imgs/player.xpm", &game->img_psp->width, &game->img_psp->height);
	game->img_coll->id = mlx_xpm_file_to_image(game->mlx, 
"../imgs/gas.xpm", &game->img_coll->width, &game->img_coll->height);
	game->img_exit->id = mlx_xpm_file_to_image(game->mlx, 
"../imgs/helicopter.xpm", &game->img_exit->width, &game->img_exit->height);
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

	game = (t_game * )malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error\nMalloc error during the allocation of t_game struct\n");
		free(map);
		exit(0);
	}
	game->mlx = mlx_init();
	load_textures(game);
	init_window(game, map);
	// add link to gameplay func here before loop
	mlx_loop(game->mlx); // should be the last function of the prog
}
