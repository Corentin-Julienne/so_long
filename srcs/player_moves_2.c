/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:13:34 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/06 17:10:43 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_obstacle(t_game *game, int keycode)
{
	if (keycode == 13
		&& game->map->map_arr[game->coord->j - 1][game->coord->i] == '1')
		return (1);
	if (keycode == 1
		&& game->map->map_arr[game->coord->j + 1][game->coord->i] == '1')
		return (1);
	if (keycode == 2
		&& game->map->map_arr[game->coord->j][game->coord->i + 1] == '1')
		return (1);
	if (keycode == 0
		&& game->map->map_arr[game->coord->j][game->coord->i - 1] == '1')
		return (1);
	return (0);
}

void	handle_exit_pos(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_space->id,
		(game->coord->i * game->img_space->width),
		(game->coord->j * game->img_space->height));
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_exit->id,
		(game->coord->i * game->img_exit->width),
		(game->coord->j * game->img_exit->height));
	mlx_put_image_to_window(game->mlx, game->wdw, game->img_psp->id,
		(game->coord->i * game->img_psp->width),
		(game->coord->j * game->img_psp->height));
	if (game->nb_coll == 0)
		quit_game(game);
}
