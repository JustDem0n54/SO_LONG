/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:24:09 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/03 14:42:07 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_storage(char *str)
{
	size_t	i;
	size_t	pos;

	i = -1;
	pos = -1;
	while (str[++pos])
		if (str[pos] == '\n')
			break ;
	if (str[pos])
		pos++;
	while (str[(++i) + pos])
		str[i] = str[i + pos];
	while (pos)
	{
		str[pos + i - 1] = 0;
		pos--;
	}
	if (!str[0])
	{
		free(str);
		str = NULL;
	}
	return (str);
}

char	*read_check(char *str, int fd, char *buff)
{
	int		size_rd;
	char	*temp;

	size_rd = 1;
	while (ft_strch(str, '\n') == 0 && size_rd != 0)
	{
		size_rd = read(fd, buff, BUFFER_SIZE);
		if (size_rd == -1)
		{
			free(str);
			return (NULL);
		}
		buff[size_rd] = '\0';
		temp = str;
		str = ft_strjoi(str, buff, size_rd);
		free (temp);
	}
	if (size_rd == 0 && str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	if (size_rd == 0 && str && str[0] != '\0')
		return (str);
	return (str);
}

char	*ft_strcp(char *str)
{
	size_t	i;
	int		len;
	char	*buff;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len])
		len++;
	i = 0;
	buff = malloc((len + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*storage[1024];
	char		buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE == 0)
		return (NULL);
	storage[fd] = read_check(storage[fd], fd, buff);
	if (!storage[fd])
		return (NULL);
	str = ft_strcp(storage[fd]);
	if (str == NULL)
		return (NULL);
	storage[fd] = create_storage(storage[fd]);
	return (str);
}

// int main() {
//     int fd = open("example.txt", O_RDONLY);
//     int i = 1;
// 	char *GNL;

//     if (fd == -1) {
//         perror("Erreur à l'ouverture du fichier");
//         return 1;
//     }
// 	while (i > 0)
// 	{
// 		GNL = get_next_line(fd);
// 		printf("%s", GNL);
// 		free (GNL);
// 		i--;
// 	}
//     close(fd);
//     return 0;
// }
