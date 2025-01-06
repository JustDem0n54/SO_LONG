/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:24:42 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 14:05:36 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_death(t_game *game)
{
	void		*save;
	t_enemie	*e;

	save = game->e;
	while (game->e)
	{
		e = game->e->content;
		if ((game->p->x * 64) == e->x * 64
			&& (game->p->y * 64) == e->y * 64 && e->dead == 0)
		{
			game->death = 1;
			game->p->time = 0;
		}
		game->e = game->e->next;
	}
	game->e = save;
	return (0);
}

int	gameplay(t_game *game)
{
	game->img->count++;
	if (game->img->count >= game->img->speed)
	{
		game->img->frame = (game->img->frame + 1) % 6;
		game->img->count = 0;
		if (game->death != 1)
			check_death(game);
		animate(game);
		render_map(game);
		render_player(game);
		render_enemie(game);
		mlx_string_put(game->mlx, game->win, 64, 64, 0x000000, game->str);
		mlx_do_sync(game->mlx);
	}
	return (0);
}

int	init_obj(t_game *game)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	game->str = ft_itoa(0);
	while (game->map->data[y])
	{
		x = 0;
		while (game->map->data[y][x])
		{
			if (game->map->data[y][x] == 'C')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

int	create_window(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->map->width * 64,
			g->map->height * 64, "Knight Adventure");
	g->obj = init_obj(g);
	g->img = init_img(g);
	g->p = init_play(g);
	init_enemie(g);
	mlx_hook(g->win, 17, 0, clear_all, g);
	mlx_hook(g->win, 2, 1L << 0, key_hook, g);
	mlx_loop_hook(g->mlx, gameplay, g);
	mlx_loop(g->mlx);
	return (0);
}
