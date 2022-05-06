/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:09:18 by cjulienn          #+#    #+#             */
/*   Updated: 2022/05/06 17:08:52 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_game(t_game *game)
{
	free_images(game, 5);
	mlx_destroy_window(game->mlx, game->wdw);
	free_split(game->map->map_arr);
	free(game->map);
	free(game->coord);
	free(game);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_game **game)
{
	if (keycode == 53)
		quit_game(*game);
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
		move_player(*game, keycode);
	return (1);
}

int	exit_hook(t_game **game)
{
	quit_game(*game);
	return (1);
}
