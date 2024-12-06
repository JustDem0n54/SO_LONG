/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:24:42 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/06 12:32:15 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		mlx_destroy_window(game->mlx, game->win);
	return (0);
}

int	create_window(void)
{
	t_game	game;

	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map->height * 128, game.map->width * 128, "Hello world!");
	mlx_hook(game.win, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}

