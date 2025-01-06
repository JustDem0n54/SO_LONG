/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:17:52 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 14:08:55 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_img(void *mlx, char *str, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx, str, width, height));
}

int	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->height)
	{
		j = 0;
		while (j < game->map->width)
		{
			if (game->map->data[i][j] == '1')
				print_wall(game, i, j, game->map->data);
			if (game->map->data[i][j] == '0' || game->map->data[i][j] == 'C'
				|| game->map->data[i][j] == 'P' || game->map->data[i][j] == 'E'
				|| game->map->data[i][j] == 'M')
				print_floor(game, i, j, game->map->data);
			if (game->map->data[i][j] == 'C' || game->map->data[i][j] == 'E')
				print_wall(game, i, j, game->map->data);
			j++;
		}
		i++;
	}
	return (0);
}

t_img	*init_img(t_game *g)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (img == NULL)
		return (NULL);
	img->he = 0;
	img->wi = 0;
	img->speed = 5000;
	load_fight_frame(img, g);
	load_animation_frame(img, g);
	img->wo[0] = load_img(g->mlx, "d/Wall2.xpm", &(img->wi), &(img->he));
	img->wo[1] = load_img(g->mlx, "d/Wall3.xpm", &(img->wi), &(img->he));
	img->wo[2] = load_img(g->mlx, "d/Wall4.xpm", &(img->wi), &(img->he));
	img->f[0] = load_img(g->mlx, "d/Floor1.xpm", &(img->wi), &(img->he));
	img->f[1] = load_img(g->mlx, "d/Floor2.xpm", &(img->wi), &(img->he));
	img->f[2] = load_img(g->mlx, "d/Floor3.xpm", &(img->wi), &(img->he));
	img->f[3] = load_img(g->mlx, "d/Floor4.xpm", &(img->wi), &(img->he));
	img->f[4] = load_img(g->mlx, "d/Floor5.xpm", &(img->wi), &(img->he));
	img->f[5] = load_img(g->mlx, "d/Floor6.xpm", &(img->wi), &(img->he));
	img->f[6] = load_img(g->mlx, "d/Floor7.xpm", &(img->wi), &(img->he));
	img->f[7] = load_img(g->mlx, "d/Floor8.xpm", &(img->wi), &(img->he));
	img->f[8] = load_img(g->mlx, "d/Floor9.xpm", &(img->wi), &(img->he));
	img->e_1 = load_img(g->mlx, "d/Exit1.xpm", &(img->wi), &(img->he));
	img->e_2 = load_img(g->mlx, "d/Exit2.xpm", &(img->wi), &(img->he));
	return (img);
}

void	my_put_img(t_game *g, void *img, int x, int y)
{
	int	img_x;
	int	img_y;
	int	*pixel;
	int	color;

	pixel = (int *)mlx_get_data_addr(img, &g->p->bpp, &g->p->line, &g->p->end);
	img_y = 0;
	while (img_y < 64)
	{
		img_x = 0;
		while (img_x < 64)
		{
			color = pixel[img_y * (g->p->line / 4) + img_x];
			if ((color >> 24 & 0xFF) == 0)
				mlx_pixel_put(g->mlx, g->win, x + img_x, y + img_y, color);
			img_x++;
		}
		img_y++;
	}
}

int	animate(t_game *g)
{
	int	x;
	int	y;

	x = 0;
	while (x < g->map->height)
	{
		y = 0;
		while (y < g->map->width)
		{
			if (g->map->data[x][y] == '2')
			{
				mlx_put_image_to_window(g->mlx, g->win,
					g->img->w[g->img->frame], y * 64, x * 64);
			}
			y++;
		}
		x++;
	}
	return (0);
}
