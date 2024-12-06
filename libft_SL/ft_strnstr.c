/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:52:11 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 13:33:28 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	size_find;

	i = 0;
	size_find = 0;
	if (*find == '\0')
		return ((char *)str);
	while (find[size_find])
		size_find++;
	while (str[i] != '\0' && i <= len)
	{
		if (str[i] == find[0])
		{
			j = 0;
			while (j < size_find && str[i + j] == find[j] && (i + j) < len)
				j++;
			if (j == size_find)
				return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
// 	printf("%s", ft_strnstr("Bonjour", "jour", 8));
// }
