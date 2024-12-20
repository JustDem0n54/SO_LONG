/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:24:42 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/20 15:45:06 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animate(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->data[i][j] == '2')
				mlx_put_image_to_window(game->mlx, game->win, game->img->w_a[game->img->frame],j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void	my_put_img(t_game *game, void *img, int x, int y)
{
	int	img_x;
	int	img_y;
	int	*pixel;
	int	color;
	
	pixel = (int *)mlx_get_data_addr(img, &game->p->bpp, &game->p->line, &game->p->end);
	img_y = 0;
	while (img_y < 64)
	{
		img_x = 0;
		while (img_x < 64)
		{
			color = pixel[img_y * (game->p->line / 4) + img_x];
			if ((color >> 24 & 0xFF) == 0)
				mlx_pixel_put(game->mlx, game->win, x + img_x, y + img_y, color);
			img_x++;
		}
		img_y++;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

void	kill_enemie(t_game *g, int atk)
{
	t_enemie	*e;
	void		*save;
	
	save = g->e;
	while (g->e)
	{
		e = g->e->content;
		if (atk == 1 && 
			((g->p->x + 1) * 64) == e->x * 64 && (g->p->y * 64) == e->y * 64)
			e->dead = 1;
		if (atk == 2 && 
			((g->p->x - 1) * 64) == e->x * 64 && (g->p->y * 64) == e->y * 64)
			e->dead = 1;
		if (atk == 3 && 
			(g->p->x * 64) == e->x * 64 && ((g->p->y - 1) * 64) == e->y * 64)
			e->dead = 1;
		if (atk == 4 && 
			(g->p->x * 64) == e->x * 64 && ((g->p->y + 1) * 64) == e->y * 64)
			e->dead = 1;
		g->e = g->e->next;
	}
	g->e = save;
}

int fight(int keycode, t_game *game)
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
	{
		mlx_clear_window(game->mlx, game->win);
		exit (EXIT_SUCCESS);
	}
	if (game->death != 1)
	{
		movement(keycode, game);
		fight(keycode, game);
	}
	return (0);
}

int	check_death(t_game *game)
{
	void	*save;
	t_enemie	*e;

	save = game->e;
	while(game->e)
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
	return(0);
}

int	init_obj(t_game *game)
{
	int y;
	int x;
	int		count;
	
	y = 0;
	count = 0;
	game->str = "0000";
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
	return(e);
}

void	init_enemie(t_game *game)
{
	int y;
	int x;
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

int	create_window(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, g->map->width * 64, g->map->height * 64, "Knight Adventure");
	g->obj = init_obj(g);
	g->img = init_img(g);
	g->p = init_play(g);
	init_enemie(g);
	mlx_hook(g->win, 2, 1L<<0, key_hook, g);
	mlx_loop_hook(g->mlx, gameplay, g);
	mlx_loop(g->mlx);
	return (0);
}

