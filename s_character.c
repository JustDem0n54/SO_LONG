/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_character.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:36:32 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/11 17:42:55 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_play	*init_play(t_game *game)
{
	int			x;
	int			y;
	char		**map;
	t_play	*play;
	
	play = ft_calloc(1, sizeof(t_play));
	y = 0;
	map = game->map->data;
	play->count = 0;
	play->p_img = mlx_xpm_file_to_image(game->mlx, "design/Player1.xpm", &(game->img->width), &(game->img->height));
	play->addr = mlx_get_data_addr(play->p_img, &play->bpp, &play->line, &play->end);
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

void	render_player(t_game *game)
{
	int x;
	int y;

	x = game->play->play_x * 64;
	y = game->play->play_y * 64;
	my_put_img(game, game->play->p_img, x, y);
}

int	move_player(t_game *game, int dx, int dy)
{
	int new_x;
	int new_y;
	
	new_x = game->play->play_x + dx;
	new_y = game->play->play_y + dy;
	if (game->map->data[new_y][new_x] != '1' && game->map->data[new_y][new_x] != '2')
	{
		game->play->play_x = new_x;
		game->play->play_y = new_y;
		game->play->count = game->play->count + 1;
		ft_printf("Nombre de deplacement : %d\n", game->play->count);
	}
	return (0);
}

