/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:01 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/11 16:51:19 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (map[i][j] != '\n' && map[i][j] != 0)
	{
		if (map[i][j++] != '1')
			return (0);
	}
	j--;
	i++;
	while (map[i + 1] != NULL)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return(0);
		i++;
	}
	while (j >= 0)
	{
		if (map[i][j--] != '1')
			return (0);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_game game;
	
	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
		return (0);
	game.map = parsing_map(fd);
	close (fd);
	while (game.map->data[i] != 0)
	{
		ft_printf("%s\n", game.map->data[i]);
		i++;
	}
	check_map(game.map->data);
	create_window(&game);
	free (game.map->data);
	return (0);
}
