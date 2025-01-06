/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_enemie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 10:18:18 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 13:21:24 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_enemie(t_game *g)
{
	t_enemie	*e;
	void		*save;

	save = g->e;
	while (g->e)
	{
		e = g->e->content;
		if (e->dead == 0)
			move_enemie(g, e);
		if (e->dead == 0 && e->dir > 0)
			my_put_img(g, g->img->pe[g->img->frame], e->x * 64, e->y * 64);
		if (e->dead == 0 && e->dir < 0)
			my_put_img(g, g->img->pe2[g->img->frame], e->x * 64, e->y * 64);
		if (e->dead == 1)
		{
			my_put_img(g, g->img->dp[e->t_death], e->x * 64, e->y * 64);
			if (e->t_death < 5)
				e->t_death++;
		}
		g->e = g->e->next;
	}
	g->e = save;
}

void	move_enemie(t_game *g, t_enemie *e)
{
	e->count++;
	if (e->count == 10)
	{
		e->count = 0;
		if (e->dir > 0 && (g->map->data[e->y][e->x + 1] != '1'
			&& g->map->data[e->y][e->x + 1] != '2'))
			e->x = e->x + 1;
		else if (e->dir < 0 && (g->map->data[e->y][e->x - 1] != '1'
			&& g->map->data[e->y][e->x - 1] != '2'))
			e->x = e->x - 1;
		else
			e->dir = e->dir * -1;
	}
}

t_enemie	*new_enemie(int x, int y)
{
	t_enemie	*e;

	e = ft_calloc(1, sizeof(t_enemie));
	e->x = x;
	e->y = y;
	e->dir = 1;
	e->dead = 0;
	e->t_death = 0;
	e->count = 0;
	return (e);
}

void	init_enemie(t_game *game)
{
	int			y;
	int			x;
	t_enemie	*e;

	game->e = NULL;
	game->death = 0;
	game->p->time = 6;
	y = 0;
	while (game->map->data[y])
	{
		x = 0;
		while (game->map->data[y][x])
		{
			if (game->map->data[y][x] == 'M')
			{
				e = new_enemie(x, y);
				ft_lstadd_back(&(game->e), ft_lstnew(e));
			}
			x++;
		}
		y++;
	}
}

void	kill_enemie(t_game *g, int atk)
{
	t_enemie	*e;
	void		*save;

	save = g->e;
	while (g->e)
	{
		e = g->e->content;
		if (atk == 1
			&& ((g->p->x + 1) * 64) == e->x * 64 && (g->p->y * 64) == e->y * 64)
			e->dead = 1;
		if (atk == 2
			&& ((g->p->x - 1) * 64) == e->x * 64 && (g->p->y * 64) == e->y * 64)
			e->dead = 1;
		if (atk == 3
			&& (g->p->x * 64) == e->x * 64 && ((g->p->y - 1) * 64) == e->y * 64)
			e->dead = 1;
		if (atk == 4
			&& (g->p->x * 64) == e->x * 64 && ((g->p->y + 1) * 64) == e->y * 64)
			e->dead = 1;
		g->e = g->e->next;
	}
	g->e = save;
}
