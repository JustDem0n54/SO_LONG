/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:56:39 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/09 15:08:55 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_animate(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx, game->img->la[i]);
		mlx_destroy_image(game->mlx, game->img->ra[i]);
		mlx_destroy_image(game->mlx, game->img->ua[i]);
		mlx_destroy_image(game->mlx, game->img->da[i]);
		mlx_destroy_image(game->mlx, game->img->lp[i]);
		mlx_destroy_image(game->mlx, game->img->rp[i]);
		mlx_destroy_image(game->mlx, game->img->w[i]);
		mlx_destroy_image(game->mlx, game->img->pe[i]);
		mlx_destroy_image(game->mlx, game->img->pe2[i]);
		mlx_destroy_image(game->mlx, game->img->dp[i]);
		i++;
	}
}

void	clear_last(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->wo[0]);
	mlx_destroy_image(game->mlx, game->img->wo[1]);
	mlx_destroy_image(game->mlx, game->img->wo[2]);
	mlx_destroy_image(game->mlx, game->img->f[0]);
	mlx_destroy_image(game->mlx, game->img->f[1]);
	mlx_destroy_image(game->mlx, game->img->f[2]);
	mlx_destroy_image(game->mlx, game->img->f[3]);
	mlx_destroy_image(game->mlx, game->img->f[4]);
	mlx_destroy_image(game->mlx, game->img->f[5]);
	mlx_destroy_image(game->mlx, game->img->f[6]);
	mlx_destroy_image(game->mlx, game->img->f[7]);
	mlx_destroy_image(game->mlx, game->img->f[8]);
	mlx_destroy_image(game->mlx, game->img->e_1);
	mlx_destroy_image(game->mlx, game->img->e_2);
	mlx_destroy_image(game->mlx, game->img->o_1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->data[i++]);
	free(map->data);
	free(map);
}

void	ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	clear_all(t_game *game)
{
	int	i;

	i = 0;
	clear_animate(game);
	clear_last(game);
	free_map(game->map);
	free(game->p);
	free(game->img);
	ft_lstclear(&game->e, free);
	free(game->str);
	mlx_do_key_autorepeaton(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
