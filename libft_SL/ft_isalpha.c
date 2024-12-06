/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:00:58 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 09:59:28 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_isalpha(98));
// 	printf("%d\n", ft_isalpha('1'));
// 	printf("%d\n", ft_isalpha('/'));
// }