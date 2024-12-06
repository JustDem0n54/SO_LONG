/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:27:16 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 10:00:02 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	printf("%d\n", ft_isdigit(98));
// 	printf("%d\n", ft_isdigit('1'));
// 	printf("%d\n", ft_isdigit('/'));
// }