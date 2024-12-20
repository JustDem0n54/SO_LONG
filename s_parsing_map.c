/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parsing_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:43:33 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/20 17:17:50 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*initialing_map(void)
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

char	*only_useful(char *line)
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
		if (ft_strchr("10PECM", line[i]))
			i++;
		else	
			return (1);
	}
	return (0);
}

t_list	*list_map(int fd, int *width, int *height)
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

t_map	*parsing_map(int fd)
{
	t_map	*map;
	t_list	*lst_start;
	t_list	*lst;
	int		i;

	i = 0;
	map = initialing_map();
	lst_start = list_map(fd, &map->width, &map->height);
	if (lst_start == NULL)
		return (NULL);
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
