/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:01:07 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/06 14:47:47 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "mlx_linux/mlx.h"

typedef struct s_map {
	int height;
	int width;
	char **data;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_game;


int		create_window(void);
int		key_hook(int keycode, t_game *game);

#endif 