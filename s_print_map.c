/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:40 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 14:06:22 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_wall(t_game *g, int i, int j, char **map)
{
	if (i == (g->map->height - 1) || i == 0 || j == 0
		|| j == (g->map->width - 1))
		map[i][j] = '2';
	else if (map[i][j] == 'E')
	{
		if (g->obj == 0)
			my_put_img(g, g->img->e_2, j * 64, i * 64);
		else
			my_put_img(g, g->img->e_1, j * 64, i * 64);
	}
	else if (map[i][j] == 'C')
		my_put_img(g, g->img->o_1, j * 64, i * 64);
	else if (map[i - 1][j] != '1' && map[i + 1][j] != '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img->wo[2], j * 64, i * 64);
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'E'
		|| map[i + 1][j] == 'C' || map[i + 1][j] == 'M' ||
		(map[i + 1][j] == '2' && i + 1 == g->map->height - 1))
		mlx_put_image_to_window(g->mlx, g->win, g->img->wo[0], j * 64, i * 64);
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img->wo[1], j * 64, i * 64);
}

void	print_floor(t_game *g, int i, int j, char **map)
{
	if (map[i + 1][j] == '2' && (map[i][j - 1] == '2' || map[i][j - 1] == '1'))
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[2], j * 64, i * 64);
	else if (map[i - 1][j] == '2'
		&& (map[i][j - 1] == '2' || map[i][j - 1] == '1'))
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[1], j * 64, i * 64);
	else if ((map[i][j + 1] == '2' || map[i][j + 1] == '1')
		&& map[i - 1][j] == '2')
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[5], j * 64, i * 64);
	else if ((map[i][j + 1] == '2' || map[i][j + 1] == '1')
		&& map[i + 1][j] == '2')
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[6], j * 64, i * 64);
	else if ((map[i][j - 1] == '2' || map[i][j - 1] == '1') && j <= 2)
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[3], j * 64, i * 64);
	else if ((map[i - 1][j] == '2' || map[i - 1][j] == '1') && i <= 1)
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[4], j * 64, i * 64);
	else if (map[i + 1][j] == '2')
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[8], j * 64, i * 64);
	else if (map[i][j + 1] == '2')
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[7], j * 64, i * 64);
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[0], j * 64, i * 64);
}

void	load_animation_frame(t_img *img, t_game *g)
{
	img->count = 0;
	img->frame = 0;
	img->rp[0] = load_img(g->mlx, "d/rp/rp1.xpm", &(img->wi), &(img->he));
	img->rp[1] = load_img(g->mlx, "d/rp/rp2.xpm", &(img->wi), &(img->he));
	img->rp[2] = load_img(g->mlx, "d/rp/rp3.xpm", &(img->wi), &(img->he));
	img->rp[3] = load_img(g->mlx, "d/rp/rp4.xpm", &(img->wi), &(img->he));
	img->rp[4] = load_img(g->mlx, "d/rp/rp5.xpm", &(img->wi), &(img->he));
	img->rp[5] = load_img(g->mlx, "d/rp/rp6.xpm", &(img->wi), &(img->he));
	img->lp[0] = load_img(g->mlx, "d/lp/lp1.xpm", &(img->wi), &(img->he));
	img->lp[1] = load_img(g->mlx, "d/lp/lp2.xpm", &(img->wi), &(img->he));
	img->lp[2] = load_img(g->mlx, "d/lp/lp3.xpm", &(img->wi), &(img->he));
	img->lp[3] = load_img(g->mlx, "d/lp/lp4.xpm", &(img->wi), &(img->he));
	img->lp[4] = load_img(g->mlx, "d/lp/lp5.xpm", &(img->wi), &(img->he));
	img->lp[5] = load_img(g->mlx, "d/lp/lp6.xpm", &(img->wi), &(img->he));
	img->w[0] = load_img(g->mlx, "d/aw_1/W1.xpm", &(img->wi), &(img->he));
	img->w[1] = load_img(g->mlx, "d/aw_1/W2.xpm", &(img->wi), &(img->he));
	img->w[2] = load_img(g->mlx, "d/aw_1/W3.xpm", &(img->wi), &(img->he));
	img->w[3] = load_img(g->mlx, "d/aw_1/W4.xpm", &(img->wi), &(img->he));
	img->w[4] = load_img(g->mlx, "d/aw_1/W5.xpm", &(img->wi), &(img->he));
	img->w[5] = load_img(g->mlx, "d/aw_1/W6.xpm", &(img->wi), &(img->he));
	img->o_1 = load_img(g->mlx, "d/Obj1.xpm", &(img->wi), &(img->he));
}

void	load_fight_frame(t_img *img, t_game *g)
{
	img->ra[0] = load_img(g->mlx, "d/pa/ra1.xpm", &(img->wi), &(img->he));
	img->ra[1] = load_img(g->mlx, "d/pa/ra2.xpm", &(img->wi), &(img->he));
	img->ra[2] = load_img(g->mlx, "d/pa/ra3.xpm", &(img->wi), &(img->he));
	img->ra[3] = load_img(g->mlx, "d/pa/ra4.xpm", &(img->wi), &(img->he));
	img->ra[4] = load_img(g->mlx, "d/pa/ra5.xpm", &(img->wi), &(img->he));
	img->ra[5] = load_img(g->mlx, "d/pa/ra6.xpm", &(img->wi), &(img->he));
	img->la[0] = load_img(g->mlx, "d/pa/la1.xpm", &(img->wi), &(img->he));
	img->la[1] = load_img(g->mlx, "d/pa/la2.xpm", &(img->wi), &(img->he));
	img->la[2] = load_img(g->mlx, "d/pa/la3.xpm", &(img->wi), &(img->he));
	img->la[3] = load_img(g->mlx, "d/pa/la4.xpm", &(img->wi), &(img->he));
	img->la[4] = load_img(g->mlx, "d/pa/la5.xpm", &(img->wi), &(img->he));
	img->la[5] = load_img(g->mlx, "d/pa/la6.xpm", &(img->wi), &(img->he));
	img->da[0] = load_img(g->mlx, "d/pa/da1.xpm", &(img->wi), &(img->he));
	img->da[1] = load_img(g->mlx, "d/pa/da2.xpm", &(img->wi), &(img->he));
	img->da[2] = load_img(g->mlx, "d/pa/da3.xpm", &(img->wi), &(img->he));
	img->da[3] = load_img(g->mlx, "d/pa/da4.xpm", &(img->wi), &(img->he));
	img->da[4] = load_img(g->mlx, "d/pa/da5.xpm", &(img->wi), &(img->he));
	img->da[5] = load_img(g->mlx, "d/pa/da6.xpm", &(img->wi), &(img->he));
	img->ua[0] = load_img(g->mlx, "d/pa/ua1.xpm", &(img->wi), &(img->he));
	img->ua[1] = load_img(g->mlx, "d/pa/ua2.xpm", &(img->wi), &(img->he));
	img->ua[2] = load_img(g->mlx, "d/pa/ua3.xpm", &(img->wi), &(img->he));
	img->ua[3] = load_img(g->mlx, "d/pa/ua4.xpm", &(img->wi), &(img->he));
	img->ua[4] = load_img(g->mlx, "d/pa/ua5.xpm", &(img->wi), &(img->he));
	img->ua[5] = load_img(g->mlx, "d/pa/ua6.xpm", &(img->wi), &(img->he));
	load_extra_frame(img, g);
}

void	load_extra_frame(t_img *img, t_game *g)
{
	img->pe[0] = load_img(g->mlx, "d/pe/en1.xpm", &(img->wi), &(img->he));
	img->pe[1] = load_img(g->mlx, "d/pe/en2.xpm", &(img->wi), &(img->he));
	img->pe[2] = load_img(g->mlx, "d/pe/en3.xpm", &(img->wi), &(img->he));
	img->pe[3] = load_img(g->mlx, "d/pe/en4.xpm", &(img->wi), &(img->he));
	img->pe[4] = load_img(g->mlx, "d/pe/en5.xpm", &(img->wi), &(img->he));
	img->pe[5] = load_img(g->mlx, "d/pe/en6.xpm", &(img->wi), &(img->he));
	img->dp[0] = load_img(g->mlx, "d/dp/dp1.xpm", &(img->wi), &(img->he));
	img->dp[1] = load_img(g->mlx, "d/dp/dp2.xpm", &(img->wi), &(img->he));
	img->dp[2] = load_img(g->mlx, "d/dp/dp3.xpm", &(img->wi), &(img->he));
	img->dp[3] = load_img(g->mlx, "d/dp/dp4.xpm", &(img->wi), &(img->he));
	img->dp[4] = load_img(g->mlx, "d/dp/dp5.xpm", &(img->wi), &(img->he));
	img->dp[5] = load_img(g->mlx, "d/dp/dp6.xpm", &(img->wi), &(img->he));
	img->pe2[0] = load_img(g->mlx, "d/pe/len1.xpm", &(img->wi), &(img->he));
	img->pe2[1] = load_img(g->mlx, "d/pe/len2.xpm", &(img->wi), &(img->he));
	img->pe2[2] = load_img(g->mlx, "d/pe/len3.xpm", &(img->wi), &(img->he));
	img->pe2[3] = load_img(g->mlx, "d/pe/len4.xpm", &(img->wi), &(img->he));
	img->pe2[4] = load_img(g->mlx, "d/pe/len5.xpm", &(img->wi), &(img->he));
	img->pe2[5] = load_img(g->mlx, "d/pe/len6.xpm", &(img->wi), &(img->he));
}
