/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:01:07 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/10 16:59:27 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx_linux/mlx.h"

# define CELL_SIZE 80

typedef struct s_img
{
	void	*w_a[6];
	void	*w_1;
	void	*w_2;
	void	*w_3;
	void	*w_4;
	void	*f_1;
	void	*f_2;
	void	*f_3;
	void	*f_4;
	void	*f_5;
	void	*f_6;
	void	*f_7;
	void	*f_8;
	void	*f_9;
	int		width;
	int		height;
	int		frame;
	int		speed;
	int		count;
}	t_img;

typedef struct s_play
{
	int		play_x;
	int		play_y;
	void	*p_img;
}	t_play;


typedef struct s_map
{
	int height;
	int width;
	char **data;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_play	*play;
	t_map	*map;
	t_img	*img;
}	t_game;


int		create_window(t_game *game);
int		key_hook(int keycode, t_game *game);

#endif 