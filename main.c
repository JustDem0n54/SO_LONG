/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:40:01 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/06 15:50:42 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	check_map(char **map)
// {
// 	int	i;
// 	int j;
// 	int len;

// 	i = 0;
// 	j = 0;
// 	while (map[i][j] != '\n' && map[i][j] != 0)
// 	{
// 		if (map[i][j++] != '1')
// 			return (0);
// 	}
// 	j--;
// 	i++;
// 	while (map[i + 1] != NULL)
// 	{
// 		if (map[i][0] != '1' || map[i][j] != '1')
// 			return(0);
// 		i++;
// 	}
// 	len = j;
// 	while (j >= 0)
// 	{
// 		if (map[i][j--] != '1')
// 			return (0);
// 	}
// 	return (len);
// }

t_map *initialing_map(void)
{
	t_map	*map;
	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
		return (NULL);
	map->width = -1;
	map->height = 0;
	map->data = NULL;
	return (map);
}

char *only_useful(char *line)
{
	size_t	i;

	i = ft_strlen(line);
	if (line[i - 1] == '\n')
		line[i - 1] = '\0';
	return (line);
}

int	line_is_correct(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_strchr("10PEC", line[i]))
			i++;
		else	
			return (1);
	}
	return (0);
}

t_list *list_map(int fd, int *width, int *height)
{
	char	*line;
	t_list	*lst;
	
	lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		only_useful(line);
		if (line_is_correct(line) == 1)
			return (free(line), NULL);
		(*width) = ft_strlen(line);
		if ((*width) < 3)
			return (free(line), NULL);
		ft_lstadd_back(&lst, ft_lstnew(line));
		(*height)++;
	}
	return (lst);
}

t_map *parsing_map(int fd)
{
	t_map	*map;
	t_list	*lst_start;
	t_list	*lst;
	int		i;

	i = 0;
	map = initialing_map();
	lst_start = list_map(fd, &map->width, &map->height);
	lst = lst_start;
	map->data = ft_calloc(map->height + 1, sizeof(char *));
	if (map->data == NULL)
		return (ft_lstclear(&lst_start, free), NULL);
	while (i < map->height)
	{
		map->data[i++] = lst->content;
		lst = lst->next;
	}
	ft_lstclear(&lst_start, NULL);
	return (map);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	t_game game;
	
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
	// create_window();
	free (game.map->data);
	return (0);
}
