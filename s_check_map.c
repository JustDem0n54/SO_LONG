/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:20:51 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/09 12:23:58 by nrontard         ###   ########.fr       */
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
	char	**copy;
	int		x;

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

int	count_element(t_game *game, char **map, int i, int y)
{
	int	p;
	int	c;
	int	e;

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

void	init_point(t_game *game, char **map, t_point *begin, t_point *end)
{
	int	i;
	int	y;

	i = 0;
	while (i < game->map->height)
	{
		y = 0;
		while (y < game->map->width)
		{
			if (map[i][y] == 'P')
			{
				begin->x = i;
				begin->y = y;
			}
			if (map[i][y] == 'E')
			{
				end->x = i;
				end->y = y;
			}
			y++;
		}
		i++;
	}
}

void	find_exit(char **map, t_point end, t_point start, int *count)
{
	if (start.x == end.x && start.y == end.y)
		count[1] = 1;
	if (map[start.x][start.y] == '1' || (count[1] == 1 && count[0] == 0)
		|| (count[0] != 0 && start.x == end.x && start.y == end.y))
		return ;
	if (map[start.x][start.y] == 'C')
		count[0] = count[0] - 1;
	map[start.x][start.y] = '1';
	find_exit(map, end, (t_point){start.x - 1, start.y}, count);
	find_exit(map, end, (t_point){start.x + 1, start.y}, count);
	find_exit(map, end, (t_point){start.x, start.y - 1}, count);
	find_exit(map, end, (t_point){start.x, start.y + 1}, count);
}
