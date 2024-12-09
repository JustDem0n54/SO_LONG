/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:24:42 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/09 17:56:35 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (EXIT_SUCCESS);
	}
	return (0);
}

void print_wall(t_game *game, int i, int j, char **map)
{
	if (i == (game->map->height - 1) || i == 0 || j == 0 || j == (game->map->width - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_1, j * 128, i * 128);
	else if (map[i - 1][j] == '0' && map[i + 1][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_4, j * 128, i * 128);
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'E' || map[i + 1][j] == 'C' || 
			(map[i + 1][j] == '1' && i + 1 == game->map->height - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_2, j * 128, i * 128);
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_3, j * 128, i * 128);
}

void	print_floor(t_game *game, int i, int j, char **map)
{
	if (map[i + 1][j] == '1' && map[i][j- 1] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_3, j * 128, i * 128);
	else if (map[i - 1][j] == '1' && map[i][j - 1] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_2, j * 128, i * 128);
	else if (map[i][j + 1] == '1' && map[i - 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_6, j * 128, i * 128);
	else if (map[i][j + 1] == '1' && map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_7, j * 128, i * 128);
	else if (map[i][j - 1] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_4, j * 128, i * 128);
	else if (map[i - 1][j] == '1' && i <= 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_5, j * 128, i * 128);
	else if (map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_9, j * 128, i * 128);
	else if (map[i][j + 1] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_8, j * 128, i * 128);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_1, j * 128, i * 128);
}

t_img	*init_img(t_game *game)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->height = 0;
	img->width = 0;
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

void render_map(t_game *game, int *height, int *width)
{
	char **map;
	int i;
	int j;

	i = 0;
	map = game->map->data;
	while (i < *height)
	{
		j = 0;
		while (j < *width)
		{
			if (map[i][j] == '1')
				print_wall(game, i, j, map);
			else if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				print_floor(game, i, j, map);
			j++;
		}
		i++;
	}
}

int	create_window(t_game *game)
{

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map->width * 128, game->map->height * 128, "Hello world!");
	game->img = init_img(game);
	render_map(game, &game->map->height, &game->map->width);
	mlx_hook(game->win, 2, 1L<<0, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}

