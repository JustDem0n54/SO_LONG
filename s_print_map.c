/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:40 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/11 18:07:08 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_game *game, int i, int j, char **map)
{
	if (i == (game->map->height - 1) || i == 0 || j == 0 || j == (game->map->width - 1))
		map[i][j] = '2';
	else if (map[i][j] == 'E')
	{
		if (game->coin < game->obj)
			my_put_img(game, game->img->e_1, j * 64, i * 64);
		if (game->coin >= game->obj)
			my_put_img(game, game->img->e_2, j * 64, i * 64);
	}
	// else if (map[i][j] == 'C')
	// 	mlx_put_image_to_window(game->mlx, game->win, game->img->c_1, j * 64, i * 64);
	else if (map[i - 1][j] != '1' && map[i + 1][j] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_4, j * 64, i * 64);
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'E' || map[i + 1][j] == 'C' || 
			(map[i + 1][j] == '2' && i + 1 == game->map->height - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_2, j * 64, i * 64);
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w_3, j * 64, i * 64);
	
}

void	print_floor(t_game *game, int i, int j, char **map)
{
	if (map[i + 1][j] == '2' && (map[i][j- 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_3, j * 64, i * 64);
	else if (map[i - 1][j] == '2' && (map[i][j - 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_2, j * 64, i * 64);
	else if ((map[i][j + 1] == '2' || map[i][j + 1] == '1') && map[i - 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_6, j * 64, i * 64);
	else if ((map[i][j + 1] == '2' || map[i][j + 1] == '1') && map[i + 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_7, j * 64, i * 64);
	else if ((map[i][j - 1] == '2' || map[i][j - 1] == '1') && j <= 2)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_4, j * 64, i * 64);
	else if ((map[i - 1][j] == '2' || map[i - 1][j] == '1') && i <= 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_5, j * 64, i * 64);
	else if (map[i + 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_9, j * 64, i * 64);
	else if (map[i][j + 1] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_8, j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img->f_1, j * 64, i * 64);
}

void	load_animation_frame(t_img *img, t_game *game)
{
	img->count = 0;
	img->frame = 0;
	img->speed = 5000;
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
	img->e_1 = mlx_xpm_file_to_image(game->mlx, "design/Exit1.xpm", &(img->width), &(img->height));
	img->e_2 = mlx_xpm_file_to_image(game->mlx, "design/Exit2.xpm", &(img->width), &(img->height));
	img->c_1 = mlx_xpm_file_to_image(game->mlx, "design/Obj1.xpm", &(img->width), &(img->height));
	return (img);
}

int	render_map(t_game *game)
{
	char **map;
	int i;
	int j;
	
	i = 0;
	map = game->map->data;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (map[i][j] == '1')
				print_wall(game, i, j, map);
			if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P' || map[i][j] == 'E')
				print_floor(game, i, j, map);
			if (map[i][j] == 'C' || map[i][j] == 'E')
				print_wall(game, i, j, map);
			j++;
		}
		i++;
	}
	return (0);
}
