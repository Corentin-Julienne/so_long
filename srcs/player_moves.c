/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjulienn <cjulienn@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:28:36 by cjulienn          #+#    #+#             */
/*   Updated: 2021/09/09 19:00:11 by cjulienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* handle map modifcation when player moves following actual keyboard input */

// void	reach_exit(t_game *game)
// {
// 	// TODO
// }

// void	collect_coll(t_game *game)
// {
// 	// TODO
// }

/* WASD (respectively 13, 0, 1, 2) */

int		is_obstacle(t_game *game, int keycode)
{
	if (keycode == 13 && game->map[game->coord->j + 1][game->coord->i] == '1')
		return (1);
	if (keycode == 1 && game->map[game->coord->j - 1][game->coord->i] == '1')
		return (1);
	if (keycode == 2 && game->map[game->coord->j][game->coord->i + 1] == '1')
		return (1);
	if (keycode == 0 && game->map[game->coord->j][game->coord->i - 1] == '1')
		return (1);
	return (0);
}

void	move_player(t_game *game, int keycode)
{
	if (!(is_obstacle(game, keycode)))
	{
		game->total_moves++;
		printf("total number of moves : %d\n", game->total_moves);
	}
}
