/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:43:11 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/09 17:41:41 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	floor_wdw(t_game *game, int wdw_x, int wdw_y)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < wdw_y)
	{
		while (x < wdw_x)
		{
			mlx_put_image_to_window(game->mlx, game->wdw,
				game->img_space->id, x, y);
			x += game->img_space->width;
		}
		x = 0;
		y += game->img_space->height;
	}
}

void	fulfill_wdw(t_game *game, t_map_parse *map, int x, int y)
{
	int		i;
	int		j;

	i = x / (game->img_space->width);
	j = y / (game->img_space->height);
	if (map->map_arr[j][i] == '0')
		mlx_put_image_to_window(game->mlx,
			game->wdw, game->img_space->id, x, y);
	else if (map->map_arr[j][i] == '1')
		mlx_put_image_to_window(game->mlx, game->wdw,
			game->img_wall->id, x, y);
	else if (map->map_arr[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->wdw,
			game->img_psp->id, x, y);
	else if (map->map_arr[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->wdw,
			game->img_coll->id, x, y);
	else if (map->map_arr[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->wdw,
			game->img_exit->id, x, y);
}

void	display_map(t_game *game, t_map_parse *map, int wdw_x, int wdw_y)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	floor_wdw(game, wdw_x, wdw_y);
	while (y < wdw_y)
	{
		while (x < wdw_x)
		{
			fulfill_wdw(game, map, x, y);
			x += game->img_space->width;
		}
		x = 0;
		y += game->img_space->height;
	}
}
