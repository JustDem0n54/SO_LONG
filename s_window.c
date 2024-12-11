/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_window.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:24:42 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/11 18:08:32 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int animate(t_game *game)
{
	int i;
	int j;
	char **map;
	
	i = 0;
	map = game->map->data;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (map[i][j] == '2')
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
	
	pixel = (int *)mlx_get_data_addr(img, &game->play->bpp, &game->play->line, &game->play->end);
	img_y = 0;
	while (img_y < 64)
	{
		img_x = 0;
		while (img_x < 64)
		{
			color = pixel[img_y * (game->play->line / 4) + img_x];
			if ((color >> 24 & 0xFF) == 0)
				mlx_pixel_put(game->mlx, game->win, x + img_x, y + img_y, color);
			img_x++;
		}
		img_y++;
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (EXIT_SUCCESS);
	}
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	else if (keycode == 115)
        move_player(game, 0, 1);
	return (0);
}

int	gameplay(t_game *game)
{
	game->img->count++;
	if (game->img->count >= game->img->speed)
	{
		game->img->frame = (game->img->frame + 1) % 6;
		game->img->count = 0;
		render_map(game);
		animate(game);
		render_player(game);
		mlx_do_sync(game->mlx);
	}
	return(0);
}

int	create_window(t_game *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * 64, game->map->height * 64, "Hello world!");
	game->img = init_img(game);
	game->play = init_play(game);
	
	
	mlx_hook(game->win, 2, 1L<<0, key_hook, game);
	mlx_loop_hook(game->mlx, gameplay, game);
	mlx_loop(game->mlx);
	return (0);
}

