/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:01 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/18 16:36:32 by nrontard         ###   ########.fr       */
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
	t_game g;
	
	if (argc != 2)
		return (0);
	i = 0;
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd < 0)
		return (0);
	g.map = parsing_map(fd);
	close (fd);
	while (g.map->data[i] != 0)
	{
		ft_printf("%s\n", g.map->data[i]);
		i++;
	}
	check_map(g.map->data);
	create_window(&g);
	free(g.map->data);
	return (0);
}
