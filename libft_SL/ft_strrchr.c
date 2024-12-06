/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:47:24 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/15 13:42:49 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char)c && i > 0)
		i--;
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_strrchr("Bonjour", 'o'));
// }