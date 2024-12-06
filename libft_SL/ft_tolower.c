/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:15:24 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 10:12:04 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

// int main(void)
// {
// 	printf("%c\n", ft_tolower('A'));
// 	printf("%c\n", ft_tolower('/'));
// 	printf("%c\n", ft_tolower('1'));
// 	return (0);
// }