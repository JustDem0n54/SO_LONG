/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/06 17:35:01 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	border_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i][j] != '\n' && map[i][j] != 0)
	{
		if (map[i][j++] != '1')
			return (1);
	}
	j--;
	i++;
	while (map[i + 1] != NULL)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (1);
		i++;
	}
	while (j >= 0)
	{
		if (map[i][j--] != '1')
			return (1);
	}
	return (0);
}

char	**copy_map(char **map, int i)
{
	char **copy;
	int x;

	x = 0;
	copy = malloc(i * sizeof(char *));
	if (copy == NULL)
		return (NULL);
	while (x < i)
	{
		copy[x] = ft_strdup(map[x]);
		x++;
	}
	return (copy);
}

int count_element(t_game *game, char **map, int i, int y)
{
	int p;
	int c;
	int e;
	
	p = 0;
	c = 0;
	e = 0;
	while (i < game->map->height)
	{
		y = 0;
		while (y < game->map->width)
		{
			if (map[i][y] == 'P')
				p++;
			if (map[i][y] == 'E')
				e++;
			if (map[i][y] == 'C')
				c++;
			y++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		return (0);
	return (c);
}

void	init_point(t_game *game, char **map, t_point begin, t_point size)
{
	size.x = 0;
	while (size.x < game->map->height)
	{
		size.y = 0;
		while (size.y < game->map->width)
		{
			if (map[size.x][size.y] == 'P')
			{
				begin.x = size.x;
				begin.y = size.y;
			}
			size.y++;
		}
		size.x++;
	}
}

void	parse_it(char **map, t_point size, t_point begin, int count)
{
	if (map[begin.x][begin.y] == 'C' || map[begin.x][begin.y] == 'E')
		count--;
	if (map[begin.x][begin.y] == '1' || count == 0)
		return;
	map[begin.x][begin.y] = '1';
	parse_it(map, size, (t_point){begin.x - 1, begin.y}, count);
	parse_it(map, size, (t_point){begin.x + 1, begin.y}, count);
	parse_it(map, size, (t_point){begin.x, begin.y - 1}, count);
	parse_it(map, size, (t_point){begin.x, begin.y + 1}, count);
}

int check_map(t_game *game)
{
	char	**copy;
	int		count;
	t_point	begin;
	t_point	size;
	
	begin.x = 0;
	size.x = 0;
	if (border_map(game->map->data) == 1)
		return (error(2), 1);
	copy = copy_map(game->map->data, game->map->height);
	count = count_element(game, copy, 0, 0);
	if (count == 0)
		return (error(5), 1);
	init_point(game, copy, begin, size);
	// parse_it(copy, size, begin, count + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_game	g;

	if (argc != 2)
		return (error(1), 1);
	i = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
		return (0);
	g.map = parsing_map(fd);
	if (g.map == NULL)
		return (1);
	close (fd);
	if (check_map(&g) == 1)
		return (1);
	create_window(&g);
	free(g.map->data);
	return (0);
}
