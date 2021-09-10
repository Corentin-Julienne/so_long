/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 20:09:18 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/10 16:46:37 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_game(t_game *game)
{
	free_images(game, 5);
	mlx_clear_window(game->mlx, game->wdw);
	free(game->coord);
	free(game);
	exit(0);
}

/* handle when player press ESC (CODE 53) or use 
WASD (respectively 13, 0, 1, 2) */

int	key_hook(int keycode, t_game **game)
{
	if (keycode == 53)
		quit_game(*game);
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0)
		move_player(*game, keycode);
	return (1);
}
