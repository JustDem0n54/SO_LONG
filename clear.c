/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:56:39 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/18 16:02:38 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clear_animate(t_game *game)
{
	int i;

	i = 0;
	while (i < 6)
	{
		mlx_destroy_image(game->mlx, game->img->la[i]);
		mlx_destroy_image(game->mlx, game->img->ra[i]);
		mlx_destroy_image(game->mlx, game->img->ua[i]);
		mlx_destroy_image(game->mlx, game->img->da[i]);
		mlx_destroy_image(game->mlx, game->img->lp[i]);
		mlx_destroy_image(game->mlx, game->img->rp[i]);
		mlx_destroy_image(game->mlx, game->img->w_a[i]);
		mlx_destroy_image(game->mlx, game->img->pe[i]);
		i++;
	}
}

void	clear_all(t_game *game)
{
	clear_animate(game);
}
