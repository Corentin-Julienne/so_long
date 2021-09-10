/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:36 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/10 17:16:17 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		is_obstacle(t_game *game, int keycode)
{
	if (keycode == 13 && game->map[game->coord->j - 1][game->coord->i] == '1')
		return (1);
	if (keycode == 1 && game->map[game->coord->j + 1][game->coord->i] == '1')
		return (1);
	if (keycode == 2 && game->map[game->coord->j][game->coord->i + 1] == '1')
		return (1);
	if (keycode == 0 && game->map[game->coord->j][game->coord->i - 1] == '1')
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

void	change_player_pos(t_game *game, int keycode)
{
	if (game->map[game->coord->j][game->coord->i] != 'E')
	{
		game->map[game->coord->j][game->coord->i] = '0';
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
	if (game->map[game->coord->j][game->coord->i] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->wdw, game->img_psp->id,
		(game->coord->i * game->img_psp->width),
			(game->coord->j * game->img_psp->height));
	}
	else if (game->map[game->coord->j][game->coord->i] == 'C')
		handle_coll(game);
	else if (game->map[game->coord->j][game->coord->i] == 'E')
		handle_exit_pos(game);
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
		printf("total number of moves : %d\n", game->total_moves);
	}
}
