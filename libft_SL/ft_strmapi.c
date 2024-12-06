/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:12:52 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/18 13:12:04 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	i = 0;
	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char my_fonct(unsigned int i, char c)
// {
// 	if (c >= 65 && c <= 90)
// 		return (c + 32);
// 	else if (c >= 97 && c <= 122)
// 		return (c - 32);
// 	return (c);
// }

// int main(void)
// {
// 	char str[8] = "Bonjour";
// 	printf("%s\n", ft_strmapi(str, my_fonct));
// 	return (0);
// }