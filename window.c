/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:24:42 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/10 18:22:52 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_wall(t_game *game, int i, int j, char **map)
{
	if (i == (game->map->height - 1) || i == 0 || j == 0 || j == (game->map->width - 1))
		map[i][j] = '2';
	else if (map[i - 1][j] != '1' && map[i + 1][j] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_4, j * 64, i * 64);
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'E' || map[i + 1][j] == 'C' || 
			(map[i + 1][j] == '1' && i + 1 == game->map->height - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_2, j * 64, i * 64);
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_3, j * 64, i * 64);
}

void	print_floor(t_game *game, int i, int j, char **map)
{
	if (map[i + 1][j] == '1' && (map[i][j- 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_3, j * 64, i * 64);
	else if (map[i - 1][j] == '2' && (map[i][j - 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_2, j * 64, i * 64);
	else if (map[i][j + 1] == '1' && map[i - 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_6, j * 64, i * 64);
	else if (map[i][j + 1] == '1' && map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_7, j * 64, i * 64);
	else if ((map[i][j - 1] == '2' || map[i][j - 1] == '1') && j <= 2)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_4, j * 64, i * 64);
	else if ((map[i - 1][j] == '2' || map[i - 1][j] == '1') && i <= 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_5, j * 64, i * 64);
	else if (map[i + 1][j] == '1' || map[i + 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_9, j * 64, i * 64);
	else if (map[i][j + 1] == '1' || map[i][j + 1] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_8, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_1, j * 64, i * 64);
}

void	load_animation_frame(t_img *img, t_game *game)
{
	img->count = 0;
	img->frame = 0;
	img->speed = 800;
	img->w_a[0] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W1.xpm", &(img->width), &(img->height));
	img->w_a[1] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W2.xpm", &(img->width), &(img->height));
	img->w_a[2] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W3.xpm", &(img->width), &(img->height));
	img->w_a[3] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W4.xpm", &(img->width), &(img->height));
	img->w_a[4] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W5.xpm", &(img->width), &(img->height));
	img->w_a[5] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W6.xpm", &(img->width), &(img->height));
}

t_img	*init_img(t_game *game)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->height = 0;
	img->width = 0;
	load_animation_frame(img, game);
	img->w_1 = mlx_xpm_file_to_image(game->mlx, "design/Wall1.xpm", &(img->width), &(img->height));
	img->w_2 = mlx_xpm_file_to_image(game->mlx, "design/Wall2.xpm", &(img->width), &(img->height));
	img->w_3 = mlx_xpm_file_to_image(game->mlx, "design/Wall3.xpm", &(img->width), &(img->height));
	img->w_4 = mlx_xpm_file_to_image(game->mlx, "design/Wall4.xpm", &(img->width), &(img->height));
	img->f_1 = mlx_xpm_file_to_image(game->mlx, "design/Floor1.xpm", &(img->width), &(img->height));
	img->f_2 = mlx_xpm_file_to_image(game->mlx, "design/Floor2.xpm", &(img->width), &(img->height));
	img->f_3 = mlx_xpm_file_to_image(game->mlx, "design/Floor3.xpm", &(img->width), &(img->height));
	img->f_4 = mlx_xpm_file_to_image(game->mlx, "design/Floor4.xpm", &(img->width), &(img->height));
	img->f_5 = mlx_xpm_file_to_image(game->mlx, "design/Floor5.xpm", &(img->width), &(img->height));
	img->f_6 = mlx_xpm_file_to_image(game->mlx, "design/Floor6.xpm", &(img->width), &(img->height));
	img->f_7 = mlx_xpm_file_to_image(game->mlx, "design/Floor7.xpm", &(img->width), &(img->height));
	img->f_8 = mlx_xpm_file_to_image(game->mlx, "design/Floor8.xpm", &(img->width), &(img->height));
	img->f_9 = mlx_xpm_file_to_image(game->mlx, "design/Floor9.xpm", &(img->width), &(img->height));
	return (img);
}

int render_map(t_game *game)
{
	char **map;
	int i;
	int j;
	int height;
	int width;

	height = game->map->height;
	width = game->map->width;
	i = 0;
	map = game->map->data;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == '1')
				print_wall(game, i, j, map);
			else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				print_floor(game, i, j, map);
			j++;
		}
		i++;
	}
	return (0);
}

int animate(t_game *game)
{
	int i;
	int j;
	char **map;
	
	game->img->count++;
	if (game->img->count >= game->img->speed)
	{
		game->img->frame = (game->img->frame + 1) % 6;
		game->img->count = 0;
	}
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

t_play *init_play(t_game *game)
{
	int			x;
	int			y;
	char		**map;
	t_play	*play;
	
	play = ft_calloc(1, sizeof(t_play));
	y = 0;
	map = game->map->data;
	play->p_img = mlx_xpm_file_to_image(game->mlx, "design/Player1.xpm", &(game->img->width), &(game->img->height));
	while (map[y++])
	{
		x = 0;
		while (map[y][x++])
		{
			if (map[y][x] == 'P')
			{
				play->play_x = x;
				play->play_y = y;
				return (play);
			}
		}
	}
	return (play);
}

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
void move_player(t_game *game, int dx, int dy)
{
	int new_x;
	int new_y;
	
	new_x = game->play->play_x + dx;
	new_y = game->play->play_y + dy;
	if (game->map->data[new_y][new_x] != 1)
	{
		game->play->play_x = new_x;
		game->play->play_y = new_y;
		mlx_put_image_to_window(game->mlx, game->win, game->play->p_img, new_x * 64, new_y * 64);
	}
}

int	create_window(t_game *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * 64, game->map->height * 64, "Hello world!");
	game->img = init_img(game);
	game->play = init_play(game);
	render_map(game);
	// render_player(game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop_hook(game->mlx, animate, game);
	mlx_hook(game->win, 2, 1L<<0, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

