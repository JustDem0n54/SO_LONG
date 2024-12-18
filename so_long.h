/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:01:07 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/18 16:26:29 by nrontard         ###   ########.fr       */
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
	void	*w[3];
	void	*f[9];
	void	*e_1;
	void	*e_2;
	void	*o_1;
	void	*rp[6];
	void	*lp[6];
	void	*ra[6];
	void	*la[6];
	void	*da[6];
	void	*ua[6];
	void	*pe[6];
	void	*c_2;
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
	char	*addr;
	int		bpp;
	int		line;
	int		end;
	int		count;
	int		dir;
	int		atk;
	int		fight;
	int		time;
}	t_play;


typedef struct s_map
{
	int height;
	int width;
	char **data;
}	t_map;

typedef struct s_enemie
{
	int				x;
	int				y;
	int				dir;
}	t_enemie;


typedef struct s_game
{
	void	*mlx;
	void	*win; 
	int		obj;
	t_list	*e;
	t_play	*p;
	t_map	*map;
	t_img	*img;
}	t_game;


int		create_window(t_game *game);
int		key_hook(int keycode, t_game *game);
t_play	*init_play(t_game *game);
void	render_player(t_game *game);
int		move_player(t_game *game, int dx, int dy);
int		check_map(char **map);
t_map	*initialing_map(void);
char	*only_useful(char *line);
int		line_is_correct(char *line);
t_list	*list_map(int fd, int *width, int *height);
t_map	*parsing_map(int fd);
void	print_wall(t_game *game, int i, int j, char **map);
void	print_floor(t_game *game, int i, int j, char **map);
void	load_animation_frame(t_img *img, t_game *game);
t_img	*init_img(t_game *game);
int		render_map(t_game *game);
void	my_put_img(t_game *game, void *img, int x, int y);
void	render_enemie(t_game *g);

#endif 