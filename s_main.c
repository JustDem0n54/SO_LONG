/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:01 by nrontard          #+#    #+#             */
/*   Updated: 2025/01/09 15:07:39 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	char	**copy;
	int		count[2];
	t_point	begin;
	t_point	end;

	begin.x = 0;
	end.x = 0;
	count[1] = 0;
	if (border_map(game->map->data) == 1)
		return (error(2), 1);
	copy = copy_map(game->map->data, game->map->height);
	count[0] = count_element(game, copy, 0, 0);
	if (count[0] == 0)
		return (ft_free(copy, game->map->height), error(5), 1);
	init_point(game, copy, &begin, &end);
	find_exit(copy, end, begin, count);
	if (count[0] != 0 && count[1] == 0)
		return (ft_free(copy, game->map->height), error(6), 1);
	ft_free(copy, game->map->height);
	return (0);
}

void	error(int error)
{
	if (error == 1)
		ft_putstr_fd("You need 1 argument !", 2);
	if (error == 2)
		ft_putstr_fd("The border of the map need to be only walls.", 2);
	if (error == 3)
		ft_putstr_fd("Invalid character in map.", 2);
	if (error == 4)
		ft_putstr_fd("Invalid size of map.", 2);
	if (error == 5)
		ft_putstr_fd("Error map, check 'E', 'P' or 'C'.", 2);
	if (error == 6)
		ft_putstr_fd("The map is impossible.", 2);
	if (error == 7)
		ft_putstr_fd("Empty Map.", 2);
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
	close(fd);
	if (check_map(&g) == 1)
	{
		free_map(g.map);
		return (1);
	}
	create_window(&g);
	free(g.map->data);
	return (0);
}
