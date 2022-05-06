/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:36 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/06 17:13:53 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_coll(t_game *game)
{
	game->nb_coll--;
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_space->id,
		(game->coord->i * game->img_space->width),
		(game->coord->j * game->img_space->height));
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_psp->id,
		(game->coord->i * game->img_psp->width),
		(game->coord->j * game->img_psp->height));
}

void	change_player_pos_2(t_game *game)
{
	if (game->map->map_arr[game->coord->j][game->coord->i] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_psp->id,
			(game->coord->i * game->img_psp->width),
			(game->coord->j * game->img_psp->height));
	}
	else if (game->map->map_arr[game->coord->j][game->coord->i] == 'C')
		handle_coll(game);
	else if (game->map->map_arr[game->coord->j][game->coord->i] == 'E')
		handle_exit_pos(game);
}

void	change_player_pos(t_game *game, int keycode)
{
	if (game->map->map_arr[game->coord->j][game->coord->i] != 'E')
	{
		game->map->map_arr[game->coord->j][game->coord->i] = '0';
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_space->id,
			(game->coord->i * game->img_space->width),
			(game->coord->j * game->img_space->height));
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_space->id,
			(game->coord->i * game->img_space->width),
			(game->coord->j * game->img_space->height));
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_exit->id,
			(game->coord->i * game->img_exit->width),
			(game->coord->j * game->img_exit->height));
	}
	update_coord(game, keycode);
	change_player_pos_2(game);
}

void	update_coord(t_game *game, int keycode)
{
	if (keycode == 13)
		game->coord->j--;
	if (keycode == 1)
		game->coord->j++;
	if (keycode == 2)
		game->coord->i++;
	if (keycode == 0)
		game->coord->i--;
}

void	move_player(t_game *game, int keycode)
{
	if (!(is_obstacle(game, keycode)))
	{
		game->total_moves++;
		change_player_pos(game, keycode);
		ft_printf("current number of movements : %d\n", game->total_moves);
	}
}
