/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:44:59 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 13:29:49 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement(int keycode, t_game *game)
{
	if (keycode == 97)
	{
		move_player(game, -1, 0);
		game->p->dir = 2;
		game->p->atk = 2;
	}
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 100)
	{
		move_player(game, 1, 0);
		game->p->dir = 1;
		game->p->atk = 1;
	}
	else if (keycode == 115)
		move_player(game, 0, 1);
	return (0);
}

int	fight(int keycode, t_game *game)
{
	if (keycode == 32)
	{
		game->p->fight = 6;
		game->p->time = 0;
		kill_enemie(game, game->p->atk);
	}
	else if (keycode == 65361)
	{
		game->p->dir = 2;
		game->p->atk = 2;
	}
	else if (keycode == 65363)
	{
		game->p->dir = 1;
		game->p->atk = 1;
	}
	else if (keycode == 65362)
		game->p->atk = 3;
	else if (keycode == 65364)
		game->p->atk = 4;
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		clear_all(game);
	if (game->death != 1)
	{
		movement(keycode, game);
		fight(keycode, game);
	}
	return (0);
}
