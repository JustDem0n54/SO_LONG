/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:03:55 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 17:25:41 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t		i;
	const char	*s;

	i = 0;
	s = str;
	if (n == 0)
		return (NULL);
	while (n > (i + 1) && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

// int main(void)
// {
// 	char *result;
// 	result = ft_memchr("Bonjour", 'j', 3);
// 	printf("%s", result);
// }