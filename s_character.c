/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_character.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:32 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/18 16:08:24 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_play	*init_play(t_game *game)
{
	int			x;
	int			y;
	t_play	*p;
	
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
				p->play_x = x;
				p->play_y = y;
				return (p);
			}
			x++;
		}
		y++;
	}
	return (p);
}

void	render_player(t_game *game)
{
	int x;
	int y;

	x = (game->p->play_x * 64);
	y = (game->p->play_y * 64);
	if (game->p->fight > 0 && game->p->time < 6)
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
	else if (game->p->dir == 1)
		my_put_img(game, game->img->rp[game->img->frame], x, y);
	else if (game->p->dir == 2)
		my_put_img(game, game->img->lp[game->img->frame], x, y);
}

int	move_player(t_game *game, int dx, int dy)
{
	int new_x;
	int new_y;
	
	new_x = game->p->play_x + dx;
	new_y = game->p->play_y + dy;
	if (game->map->data[new_y][new_x] != '1' && game->map->data[new_y][new_x] != '2')
	{
		game->p->play_x = new_x;
		game->p->play_y = new_y;
		game->p->count = game->p->count + 1;
		ft_printf("Nombre de deplacement : %d\n", game->p->count);
		if (game->map->data[new_y][new_x] == 'C')
		{
			game->obj--;
			game->map->data[new_y][new_x] = '0';
		}
		if (game->map->data[new_y][new_x] == 'E')
			exit (EXIT_SUCCESS);
	}
	return (0);
}

