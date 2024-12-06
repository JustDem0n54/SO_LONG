/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:36 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/14 10:11:46 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

// int main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// 	printf("%c\n", ft_toupper('/'));
// 	printf("%c\n", ft_toupper('1'));
// 	return (0);
// }