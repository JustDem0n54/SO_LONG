/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:22:03 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 16:01:42 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (dest);
	while (n > 0)
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char dest[8] = "Bonjour";
// 	char src[] = "Hello World !";
// 	printf("%s\n", dest);
// 	ft_memcpy(dest, src, 8);
// 	printf("%s", dest);
// }