/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:16:56 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 16:02:30 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (d == s)
		return (dest);
	if (d < s)
	{
		while (n-- > 0)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n-- > 0)
		{
			*--d = *--s;
		}
	}
	return (dest);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
// 	char dest[20] = "Bonjour test test ";
// 	char src[] = "Hello World !";
// 	printf("%s\n", dest);
// 	ft_memmove(dest, src, 13);
// 	printf("%s", dest);
// }