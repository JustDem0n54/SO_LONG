/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_character.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:32 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 14:16:11 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_play	*init_play(t_game *game)
{
	int			x;
	int			y;
	t_play		*p;

	p = ft_calloc(1, sizeof(t_play));
	y = 0;
	p->dir = 1;
	p->atk = 1;
	p->count = 0;
	while (game->map->data[y])
	{
		x = 0;
		while (game->map->data[y][x])
		{
			if (game->map->data[y][x] == 'P')
			{
				p->x = x;
				p->y = y;
				return (p);
			}
			x++;
		}
		y++;
	}
	return (p);
}

void	fight_aimation(t_game *game, int x, int y)
{
	if (game->p->atk == 1)
		my_put_img(game, game->img->ra[game->p->time], x, y);
	if (game->p->atk == 2)
		my_put_img(game, game->img->la[game->p->time], x, y);
	if (game->p->atk == 3)
		my_put_img(game, game->img->ua[game->p->time], x, y);
	if (game->p->atk == 4)
		my_put_img(game, game->img->da[game->p->time], x, y);
	game->p->time++;
	game->p->fight--;
}

void	death_animation(t_game *game, int x, int y)
{
	my_put_img(game, game->img->dp[game->p->time], x, y);
	game->p->time++;
	if (game->p->time > 5)
	{
		ft_putstr_fd("YoU aRe DeAd !", 1);
		clear_all(game);
	}
}

void	render_player(t_game *game)
{
	int	x;
	int	y;

	x = (game->p->x * 64);
	y = (game->p->y * 64);
	if (game->p->fight > 0 && game->p->time < 6)
		fight_aimation(game, x, y);
	else if (game->death == 1 && game->p->time < 6)
		death_animation(game, x, y);
	else if (game->p->dir == 1)
		my_put_img(game, game->img->rp[game->img->frame], x, y);
	else if (game->p->dir == 2)
		my_put_img(game, game->img->lp[game->img->frame], x, y);
}

int	move_player(t_game *game, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = game->p->x + dx;
	ny = game->p->y + dy;
	if (game->map->data[ny][nx] != '1' && game->map->data[ny][nx] != '2')
	{
		game->p->x = nx;
		game->p->y = ny;
		game->p->count = game->p->count + 1;
		ft_printf("Number of movements : %d\n", game->p->count);
		free(game->str);
		game->str = ft_itoa(game->p->count);
		if (game->map->data[ny][nx] == 'C')
		{
			game->obj--;
			game->map->data[ny][nx] = '0';
		}
		if (game->map->data[ny][nx] == 'E')
		{
			ft_putstr_fd("VICTORY !!", 1);
			clear_all(game);
		}
	}
	return (0);
}
