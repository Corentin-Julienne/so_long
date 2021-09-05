/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:03:25 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/05 17:16:20 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/so_long.h"

void	load_textures(t_game *game, t_map_parse *map)
{
	
}

void	init_window(t_game *game)
{
	// TODO
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
	load_textures(game, map);
	init_window(game);
	mlx_loop(game->mlx);
}


