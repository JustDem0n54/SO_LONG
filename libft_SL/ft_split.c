/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:48:27 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/18 13:11:05 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char const *s, char c)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wc++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	size_t			i;
	int				wc;
	char			**str;
	size_t			start;
	size_t			end;

	i = 0;
	wc = 0;
	str = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		end = i;
		if (end > start)
			str[wc++] = ft_substr(s, start, end - start);
	}
	str[wc] = 0;
	return (str);
}

// int		main(void)
// {
// 	int i = 0;
// 	char **tab;
// 	tab = ft_split("bonjour je m'appel Arthur", ' ');
// 	while (i < 4)
// 	{
// 		printf("string %d : %s\n", i, tab[i]);
// 		i++;
// 	}
// 	return (0);
// }
