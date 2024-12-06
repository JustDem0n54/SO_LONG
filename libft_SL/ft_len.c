/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:53:28 by nrontard          #+#    #+#             */
/*   Updated: 2024/11/20 17:48:54 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_len_nbr(int n)
{
	int		i;
	long	nb;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

int	ft_len_nbru(unsigned long n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

int	ft_len_hexa(size_t n)
{
	size_t	i;

	i = 0;
	while (n >= 16)
	{
		n = n / 16;
		i++;
	}
	return (i + 1);
}
