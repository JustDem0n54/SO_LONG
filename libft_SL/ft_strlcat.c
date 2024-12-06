/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:40:30 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 14:08:12 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
		i++;
	while (s2[j])
		j++;
	if (i == n)
		return (n + j);
	k = 0;
	while (k < j && i + k < n - 1)
	{
		s1[i + k] = s2[k];
		k++;
	}
	s1[i + k] = '\0';
	return (i + j);
}

// int main(void)
// {
// 	char dest[20] = "hello ";
// 	char src[] = "World !";
// 	printf("%s\n", dest);
// 	printf("%zu\n", ft_strlcat(dest, src, 20));
// 	printf("%s\n", dest);

// 	return (0);
// }