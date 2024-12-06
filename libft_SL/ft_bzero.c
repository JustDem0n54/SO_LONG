/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:23:06 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 10:03:16 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str++ = 0;
		n--;
	}
}

// #include <stdio.h>

// int main(void)
// {
// 	char str[19] = "test test test test";
// 	printf("%s\n", str);
// 	ft_bzero(str, sizeof(str));
// 	printf("%s\n", str);
// 	return(0);
// }