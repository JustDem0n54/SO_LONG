/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:01:01 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/18 13:12:14 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void myfonction(unsigned int i, char *s)
// {
// 	while (s[i])
// 	{
// 		write(1, &s[i], 1);
// 		i++;
// 	}
// }

// int main(void)
// {
// 	char str[8] = "Bonjour";

// 	ft_striteri(str, myfonction);
// }