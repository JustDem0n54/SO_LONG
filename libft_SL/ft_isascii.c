/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:40:00 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 10:00:25 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_isascii(98));
// 	printf("%d\n", ft_isascii('1'));
// 	printf("%d\n", ft_isascii('/'));
// 	printf("%d\n", ft_isascii(1649));
// }