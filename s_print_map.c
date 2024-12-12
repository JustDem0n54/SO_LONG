/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:40 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/12 17:59:09 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_game *game, int i, int j, char **map)
{
	if (i == (game->map->height - 1) || i == 0 || j == 0 || j == (game->map->width - 1))
		map[i][j] = '2';
	else if (map[i][j] == 'E')
	{
		if (game->obj == 0)
			my_put_img(game, game->img->e_2, j * 64, i * 64);
		else
			my_put_img(game, game->img->e_1, j * 64, i * 64);
	}
	else if (map[i][j] == 'C')
		my_put_img(game, game->img->o_1, j * 64, i * 64);
	else if (map[i - 1][j] != '1' && map[i + 1][j] != '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w[2], j * 64, i * 64);
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'E' || map[i + 1][j] == 'C' || 
			(map[i + 1][j] == '2' && i + 1 == game->map->height - 1))
		mlx_put_image_to_window(game->mlx, game->win, game->img->w[0], j * 64, i * 64);
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img->w[1], j * 64, i * 64);
	
}

void	print_floor(t_game *game, int i, int j, char **map)
{
	if (map[i + 1][j] == '2' && (map[i][j- 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[2], j * 64, i * 64);
	else if (map[i - 1][j] == '2' && (map[i][j - 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[1], j * 64, i * 64);
	else if ((map[i][j + 1] == '2' || map[i][j + 1] == '1') && map[i - 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[5], j * 64, i * 64);
	else if ((map[i][j + 1] == '2' || map[i][j + 1] == '1') && map[i + 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[6], j * 64, i * 64);
	else if ((map[i][j - 1] == '2' || map[i][j - 1] == '1') && j <= 2)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[3], j * 64, i * 64);
	else if ((map[i - 1][j] == '2' || map[i - 1][j] == '1') && i <= 1)
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[4], j * 64, i * 64);
	else if (map[i + 1][j] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[8], j * 64, i * 64);
	else if (map[i][j + 1] == '2')
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[7], j * 64, i * 64);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->img->f[0], j * 64, i * 64);
}

void	load_animation_frame(t_img *img, t_game *game)
{
	img->count = 0;
	img->frame = 0;
	img->rp[0] = mlx_xpm_file_to_image(game->mlx, "design/rp/rp1.xpm", &(img->width), &(game->img->height));
	img->rp[1] = mlx_xpm_file_to_image(game->mlx, "design/rp/rp2.xpm", &(img->width), &(game->img->height));
	img->rp[2] = mlx_xpm_file_to_image(game->mlx, "design/rp/rp3.xpm", &(img->width), &(game->img->height));
	img->rp[3] = mlx_xpm_file_to_image(game->mlx, "design/rp/rp4.xpm", &(img->width), &(game->img->height));
	img->rp[4] = mlx_xpm_file_to_image(game->mlx, "design/rp/rp5.xpm", &(img->width), &(game->img->height));
	img->rp[5] = mlx_xpm_file_to_image(game->mlx, "design/rp/rp6.xpm", &(img->width), &(game->img->height));
	img->lp[0] = mlx_xpm_file_to_image(game->mlx, "design/lp/lp1.xpm", &(img->width), &(game->img->height));
	img->lp[1] = mlx_xpm_file_to_image(game->mlx, "design/lp/lp2.xpm", &(img->width), &(game->img->height));
	img->lp[2] = mlx_xpm_file_to_image(game->mlx, "design/lp/lp3.xpm", &(img->width), &(game->img->height));
	img->lp[3] = mlx_xpm_file_to_image(game->mlx, "design/lp/lp4.xpm", &(img->width), &(game->img->height));
	img->lp[4] = mlx_xpm_file_to_image(game->mlx, "design/lp/lp5.xpm", &(img->width), &(game->img->height));
	img->lp[5] = mlx_xpm_file_to_image(game->mlx, "design/lp/lp6.xpm", &(img->width), &(game->img->height));
	img->w_a[0] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W1.xpm", &(img->width), &(img->height));
	img->w_a[1] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W2.xpm", &(img->width), &(img->height));
	img->w_a[2] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W3.xpm", &(img->width), &(img->height));
	img->w_a[3] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W4.xpm", &(img->width), &(img->height));
	img->w_a[4] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W5.xpm", &(img->width), &(img->height));
	img->w_a[5] = mlx_xpm_file_to_image(game->mlx, "design/aw_1/W6.xpm", &(img->width), &(img->height));
	img->o_1 = mlx_xpm_file_to_image(game->mlx, "design/Obj1.xpm", &(img->width), &(img->height));
	img->c_2 = mlx_xpm_file_to_image(game->mlx, "design/Player2.xpm", &(img->width), &(game->img->height));
}

void	load_fight_frame(t_img *img, t_game *game)
{
	img->ra[0] = mlx_xpm_file_to_image(game->mlx, "design/pa/ra1.xpm", &(img->width), &(game->img->height));
	img->ra[1] = mlx_xpm_file_to_image(game->mlx, "design/pa/ra2.xpm", &(img->width), &(game->img->height));
	img->ra[2] = mlx_xpm_file_to_image(game->mlx, "design/pa/ra3.xpm", &(img->width), &(game->img->height));
	img->ra[3] = mlx_xpm_file_to_image(game->mlx, "design/pa/ra4.xpm", &(img->width), &(game->img->height));
	img->ra[4] = mlx_xpm_file_to_image(game->mlx, "design/pa/ra5.xpm", &(img->width), &(game->img->height));
	img->ra[5] = mlx_xpm_file_to_image(game->mlx, "design/pa/ra6.xpm", &(img->width), &(game->img->height));
	img->la[0] = mlx_xpm_file_to_image(game->mlx, "design/pa/la1.xpm", &(img->width), &(game->img->height));
	img->la[1] = mlx_xpm_file_to_image(game->mlx, "design/pa/la2.xpm", &(img->width), &(game->img->height));
	img->la[2] = mlx_xpm_file_to_image(game->mlx, "design/pa/la3.xpm", &(img->width), &(game->img->height));
	img->la[3] = mlx_xpm_file_to_image(game->mlx, "design/pa/la4.xpm", &(img->width), &(game->img->height));
	img->la[4] = mlx_xpm_file_to_image(game->mlx, "design/pa/la5.xpm", &(img->width), &(game->img->height));
	img->la[5] = mlx_xpm_file_to_image(game->mlx, "design/pa/la6.xpm", &(img->width), &(game->img->height));
	img->da[0] = mlx_xpm_file_to_image(game->mlx, "design/pa/da1.xpm", &(img->width), &(game->img->height));
	img->da[1] = mlx_xpm_file_to_image(game->mlx, "design/pa/da2.xpm", &(img->width), &(game->img->height));
	img->da[2] = mlx_xpm_file_to_image(game->mlx, "design/pa/da3.xpm", &(img->width), &(game->img->height));
	img->da[3] = mlx_xpm_file_to_image(game->mlx, "design/pa/da4.xpm", &(img->width), &(game->img->height));
	img->da[4] = mlx_xpm_file_to_image(game->mlx, "design/pa/da5.xpm", &(img->width), &(game->img->height));
	img->da[5] = mlx_xpm_file_to_image(game->mlx, "design/pa/da6.xpm", &(img->width), &(game->img->height));
	img->ua[0] = mlx_xpm_file_to_image(game->mlx, "design/pa/ua1.xpm", &(img->width), &(game->img->height));
	img->ua[1] = mlx_xpm_file_to_image(game->mlx, "design/pa/ua2.xpm", &(img->width), &(game->img->height));
	img->ua[2] = mlx_xpm_file_to_image(game->mlx, "design/pa/ua3.xpm", &(img->width), &(game->img->height));
	img->ua[3] = mlx_xpm_file_to_image(game->mlx, "design/pa/ua4.xpm", &(img->width), &(game->img->height));
	img->ua[4] = mlx_xpm_file_to_image(game->mlx, "design/pa/ua5.xpm", &(img->width), &(game->img->height));
	img->ua[5] = mlx_xpm_file_to_image(game->mlx, "design/pa/ua6.xpm", &(img->width), &(game->img->height));
}

t_img	*init_img(t_game *game)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->height = 0;
	img->width = 0;
	img->speed = 5000;
	load_fight_frame(img, game);
	load_animation_frame(img, game);
	img->w[0] = mlx_xpm_file_to_image(game->mlx, "design/Wall2.xpm", &(img->width), &(img->height));
	img->w[1] = mlx_xpm_file_to_image(game->mlx, "design/Wall3.xpm", &(img->width), &(img->height));
	img->w[2] = mlx_xpm_file_to_image(game->mlx, "design/Wall4.xpm", &(img->width), &(img->height));
	img->f[0] = mlx_xpm_file_to_image(game->mlx, "design/Floor1.xpm", &(img->width), &(img->height));
	img->f[1] = mlx_xpm_file_to_image(game->mlx, "design/Floor2.xpm", &(img->width), &(img->height));
	img->f[2] = mlx_xpm_file_to_image(game->mlx, "design/Floor3.xpm", &(img->width), &(img->height));
	img->f[3] = mlx_xpm_file_to_image(game->mlx, "design/Floor4.xpm", &(img->width), &(img->height));
	img->f[4] = mlx_xpm_file_to_image(game->mlx, "design/Floor5.xpm", &(img->width), &(img->height));
	img->f[5] = mlx_xpm_file_to_image(game->mlx, "design/Floor6.xpm", &(img->width), &(img->height));
	img->f[6] = mlx_xpm_file_to_image(game->mlx, "design/Floor7.xpm", &(img->width), &(img->height));
	img->f[7] = mlx_xpm_file_to_image(game->mlx, "design/Floor8.xpm", &(img->width), &(img->height));
	img->f[8] = mlx_xpm_file_to_image(game->mlx, "design/Floor9.xpm", &(img->width), &(img->height));
	img->e_1 = mlx_xpm_file_to_image(game->mlx, "design/Exit1.xpm", &(img->width), &(img->height));
	img->e_2 = mlx_xpm_file_to_image(game->mlx, "design/Exit2.xpm", &(img->width), &(img->height));
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
