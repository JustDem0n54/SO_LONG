/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:43:46 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/18 13:09:38 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		fin;
	int		debut;

	debut = 0;
	fin = ft_strlen(s1);
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (debut <= fin && ft_strchr(set, s1[debut]))
		debut++;
	while (fin >= debut && ft_strchr(set, s1[fin]))
		fin--;
	str = ft_substr(s1, debut, fin - debut + 1);
	return (str);
}

// int main(void)
// {
// 	printf("%s", ft_strtrim("oauauouaBonjour a tous !oauouaou", "oau"));
// 	return (0);
// }