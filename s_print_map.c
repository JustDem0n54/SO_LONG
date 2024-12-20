/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_print_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:34:40 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/20 15:45:49 by nrontard         ###   ########.fr       */
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
		mlx_put_image_to_window(g->mlx, g->win, g->img->w[2], j * 64, i * 64);
	else if (map[i + 1][j] == '0' || map[i + 1][j] == 'E' 
		|| map[i + 1][j] == 'C' || map[i + 1][j] == 'M' ||
		(map[i + 1][j] == '2' && i + 1 == g->map->height - 1))
		mlx_put_image_to_window(g->mlx, g->win, g->img->w[0], j * 64, i * 64);
	else if (map[i - 1][j] == '1' || map[i + 1][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img->w[1], j * 64, i * 64);
	
}

void	print_floor(t_game *g, int i, int j, char **map)
{
	if (map[i + 1][j] == '2' && (map[i][j- 1] == '2' || map[i][j- 1] == '1'))
		mlx_put_image_to_window(g->mlx, g->win, g->img->f[2], j * 64, i * 64);
	else if (map[i - 1][j] == '2' && 
		(map[i][j - 1] == '2' || map[i][j- 1] == '1'))
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
	img->rp[0] = mlx_xpm_file_to_image(g->mlx, "d/rp/rp1.xpm", &(img->wi), &(img->he));
	img->rp[1] = mlx_xpm_file_to_image(g->mlx, "d/rp/rp2.xpm", &(img->wi), &(img->he));
	img->rp[2] = mlx_xpm_file_to_image(g->mlx, "d/rp/rp3.xpm", &(img->wi), &(img->he));
	img->rp[3] = mlx_xpm_file_to_image(g->mlx, "d/rp/rp4.xpm", &(img->wi), &(img->he));
	img->rp[4] = mlx_xpm_file_to_image(g->mlx, "d/rp/rp5.xpm", &(img->wi), &(img->he));
	img->rp[5] = mlx_xpm_file_to_image(g->mlx, "d/rp/rp6.xpm", &(img->wi), &(img->he));
	img->lp[0] = mlx_xpm_file_to_image(g->mlx, "d/lp/lp1.xpm", &(img->wi), &(img->he));
	img->lp[1] = mlx_xpm_file_to_image(g->mlx, "d/lp/lp2.xpm", &(img->wi), &(img->he));
	img->lp[2] = mlx_xpm_file_to_image(g->mlx, "d/lp/lp3.xpm", &(img->wi), &(img->he));
	img->lp[3] = mlx_xpm_file_to_image(g->mlx, "d/lp/lp4.xpm", &(img->wi), &(img->he));
	img->lp[4] = mlx_xpm_file_to_image(g->mlx, "d/lp/lp5.xpm", &(img->wi), &(img->he));
	img->lp[5] = mlx_xpm_file_to_image(g->mlx, "d/lp/lp6.xpm", &(img->wi), &(img->he));
	img->w_a[0] = mlx_xpm_file_to_image(g->mlx, "d/aw_1/W1.xpm", &(img->wi), &(img->he));
	img->w_a[1] = mlx_xpm_file_to_image(g->mlx, "d/aw_1/W2.xpm", &(img->wi), &(img->he));
	img->w_a[2] = mlx_xpm_file_to_image(g->mlx, "d/aw_1/W3.xpm", &(img->wi), &(img->he));
	img->w_a[3] = mlx_xpm_file_to_image(g->mlx, "d/aw_1/W4.xpm", &(img->wi), &(img->he));
	img->w_a[4] = mlx_xpm_file_to_image(g->mlx, "d/aw_1/W5.xpm", &(img->wi), &(img->he));
	img->w_a[5] = mlx_xpm_file_to_image(g->mlx, "d/aw_1/W6.xpm", &(img->wi), &(img->he));
	img->o_1 = mlx_xpm_file_to_image(g->mlx, "d/Obj1.xpm", &(img->wi), &(img->he));
	img->c_2 = mlx_xpm_file_to_image(g->mlx, "d/Player2.xpm", &(img->wi), &(img->he));
}

void	load_fight_frame(t_img *img, t_game *g)
{
	img->ra[0] = mlx_xpm_file_to_image(g->mlx, "d/pa/ra1.xpm", &(img->wi), &(img->he));
	img->ra[1] = mlx_xpm_file_to_image(g->mlx, "d/pa/ra2.xpm", &(img->wi), &(img->he));
	img->ra[2] = mlx_xpm_file_to_image(g->mlx, "d/pa/ra3.xpm", &(img->wi), &(img->he));
	img->ra[3] = mlx_xpm_file_to_image(g->mlx, "d/pa/ra4.xpm", &(img->wi), &(img->he));
	img->ra[4] = mlx_xpm_file_to_image(g->mlx, "d/pa/ra5.xpm", &(img->wi), &(img->he));
	img->ra[5] = mlx_xpm_file_to_image(g->mlx, "d/pa/ra6.xpm", &(img->wi), &(img->he));
	img->la[0] = mlx_xpm_file_to_image(g->mlx, "d/pa/la1.xpm", &(img->wi), &(img->he));
	img->la[1] = mlx_xpm_file_to_image(g->mlx, "d/pa/la2.xpm", &(img->wi), &(img->he));
	img->la[2] = mlx_xpm_file_to_image(g->mlx, "d/pa/la3.xpm", &(img->wi), &(img->he));
	img->la[3] = mlx_xpm_file_to_image(g->mlx, "d/pa/la4.xpm", &(img->wi), &(img->he));
	img->la[4] = mlx_xpm_file_to_image(g->mlx, "d/pa/la5.xpm", &(img->wi), &(img->he));
	img->la[5] = mlx_xpm_file_to_image(g->mlx, "d/pa/la6.xpm", &(img->wi), &(img->he));
	img->da[0] = mlx_xpm_file_to_image(g->mlx, "d/pa/da1.xpm", &(img->wi), &(img->he));
	img->da[1] = mlx_xpm_file_to_image(g->mlx, "d/pa/da2.xpm", &(img->wi), &(img->he));
	img->da[2] = mlx_xpm_file_to_image(g->mlx, "d/pa/da3.xpm", &(img->wi), &(img->he));
	img->da[3] = mlx_xpm_file_to_image(g->mlx, "d/pa/da4.xpm", &(img->wi), &(img->he));
	img->da[4] = mlx_xpm_file_to_image(g->mlx, "d/pa/da5.xpm", &(img->wi), &(img->he));
	img->da[5] = mlx_xpm_file_to_image(g->mlx, "d/pa/da6.xpm", &(img->wi), &(img->he));
	img->ua[0] = mlx_xpm_file_to_image(g->mlx, "d/pa/ua1.xpm", &(img->wi), &(img->he));
	img->ua[1] = mlx_xpm_file_to_image(g->mlx, "d/pa/ua2.xpm", &(img->wi), &(img->he));
	img->ua[2] = mlx_xpm_file_to_image(g->mlx, "d/pa/ua3.xpm", &(img->wi), &(img->he));
	img->ua[3] = mlx_xpm_file_to_image(g->mlx, "d/pa/ua4.xpm", &(img->wi), &(img->he));
	img->ua[4] = mlx_xpm_file_to_image(g->mlx, "d/pa/ua5.xpm", &(img->wi), &(img->he));
	img->ua[5] = mlx_xpm_file_to_image(g->mlx, "d/pa/ua6.xpm", &(img->wi), &(img->he));
	load_extra_frame(img, g);
}

void	load_extra_frame(t_img *img, t_game *g)
{
	img->pe[0] = mlx_xpm_file_to_image(g->mlx, "d/pe/en1.xpm", &(img->wi), &(img->he));
	img->pe[1] = mlx_xpm_file_to_image(g->mlx, "d/pe/en2.xpm", &(img->wi), &(img->he));
	img->pe[2] = mlx_xpm_file_to_image(g->mlx, "d/pe/en3.xpm", &(img->wi), &(img->he));
	img->pe[3] = mlx_xpm_file_to_image(g->mlx, "d/pe/en4.xpm", &(img->wi), &(img->he));
	img->pe[4] = mlx_xpm_file_to_image(g->mlx, "d/pe/en5.xpm", &(img->wi), &(img->he));
	img->pe[5] = mlx_xpm_file_to_image(g->mlx, "d/pe/en6.xpm", &(img->wi), &(img->he));
	img->dp[0] = mlx_xpm_file_to_image(g->mlx, "d/dp/dp1.xpm", &(img->wi), &(img->he));
	img->dp[1] = mlx_xpm_file_to_image(g->mlx, "d/dp/dp2.xpm", &(img->wi), &(img->he));
	img->dp[2] = mlx_xpm_file_to_image(g->mlx, "d/dp/dp3.xpm", &(img->wi), &(img->he));
	img->dp[3] = mlx_xpm_file_to_image(g->mlx, "d/dp/dp4.xpm", &(img->wi), &(img->he));
	img->dp[4] = mlx_xpm_file_to_image(g->mlx, "d/dp/dp5.xpm", &(img->wi), &(img->he));
	img->dp[5] = mlx_xpm_file_to_image(g->mlx, "d/dp/dp6.xpm", &(img->wi), &(img->he));
	img->pe2[0] = mlx_xpm_file_to_image(g->mlx, "d/pe/len1.xpm", &(img->wi), &(img->he));
	img->pe2[1] = mlx_xpm_file_to_image(g->mlx, "d/pe/len2.xpm", &(img->wi), &(img->he));
	img->pe2[2] = mlx_xpm_file_to_image(g->mlx, "d/pe/len3.xpm", &(img->wi), &(img->he));
	img->pe2[3] = mlx_xpm_file_to_image(g->mlx, "d/pe/len4.xpm", &(img->wi), &(img->he));
	img->pe2[4] = mlx_xpm_file_to_image(g->mlx, "d/pe/len5.xpm", &(img->wi), &(img->he));
	img->pe2[5] = mlx_xpm_file_to_image(g->mlx, "d/pe/len6.xpm", &(img->wi), &(img->he));
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
	img->w[0] = mlx_xpm_file_to_image(g->mlx, "d/Wall2.xpm", &(img->wi), &(img->he));
	img->w[1] = mlx_xpm_file_to_image(g->mlx, "d/Wall3.xpm", &(img->wi), &(img->he));
	img->w[2] = mlx_xpm_file_to_image(g->mlx, "d/Wall4.xpm", &(img->wi), &(img->he));
	img->f[0] = mlx_xpm_file_to_image(g->mlx, "d/Floor1.xpm", &(img->wi), &(img->he));
	img->f[1] = mlx_xpm_file_to_image(g->mlx, "d/Floor2.xpm", &(img->wi), &(img->he));
	img->f[2] = mlx_xpm_file_to_image(g->mlx, "d/Floor3.xpm", &(img->wi), &(img->he));
	img->f[3] = mlx_xpm_file_to_image(g->mlx, "d/Floor4.xpm", &(img->wi), &(img->he));
	img->f[4] = mlx_xpm_file_to_image(g->mlx, "d/Floor5.xpm", &(img->wi), &(img->he));
	img->f[5] = mlx_xpm_file_to_image(g->mlx, "d/Floor6.xpm", &(img->wi), &(img->he));
	img->f[6] = mlx_xpm_file_to_image(g->mlx, "d/Floor7.xpm", &(img->wi), &(img->he));
	img->f[7] = mlx_xpm_file_to_image(g->mlx, "d/Floor8.xpm", &(img->wi), &(img->he));
	img->f[8] = mlx_xpm_file_to_image(g->mlx, "d/Floor9.xpm", &(img->wi), &(img->he));
	img->e_1 = mlx_xpm_file_to_image(g->mlx, "d/Exit1.xpm", &(img->wi), &(img->he));
	img->e_2 = mlx_xpm_file_to_image(g->mlx, "d/Exit2.xpm", &(img->wi), &(img->he));
	return (img);
}

int	render_map(t_game *game)
{
	int i;
	int j;
	
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
