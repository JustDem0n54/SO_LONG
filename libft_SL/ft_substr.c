/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:47:33 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/15 13:41:43 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	j;
	size_t	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	news = (char *)malloc(len + 1 * sizeof(char));
	if (news == NULL)
		return (NULL);
	i = 0;
	j = start;
	while (i < len && j < ft_strlen(s))
	{
		news[i] = s[j];
		i++;
		j++;
	}
	news[i] = '\0';
	return (news);
}
// int main(void)
// {
// 	printf("%s", ft_substr("Ceci est une copie et voila !", 10, 50));
// }
