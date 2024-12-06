/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:58:31 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/03 13:49:16 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	use_format(char c, va_list args)
{
	if (c == '%')
	{
		write (1, "%", 1);
		return (1);
	}
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *), 1));
	if (c == 'p')
		return (hexa_p(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 1));
	if (c == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int), 1));
	if (c == 'x' || c == 'X')
		return (ft_puthexanbr_fd(va_arg(args, unsigned int), 1, c));
	return (0);
}

int	hexa_p(void *n)
{
	if (n == 0)
		return (ft_putstr("(nil)", 1));
	ft_putchar('0');
	ft_putchar('x');
	return (ft_puthexanbr_fd((unsigned long)n, 1, 'p') + 2);
}

int	detect_format(char c)
{
	static const char	*detect = "cspdiuxX%";
	int					i;

	i = 0;
	while (detect[i])
		i++;
	while (detect[i] != (char)c && i > 0)
		i--;
	if (detect[i] == (char)c)
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char *val, ...)
{
	va_list	args;
	int		i;
	int		k;

	va_start(args, val);
	i = 0;
	k = 0;
	while (val[i])
	{
		if (val[i] == '%' && detect_format(val[i + 1]))
		{
			k = k + use_format(val[i + 1], args);
			i = i + 2;
		}
		else if (val[i])
		{
			write(1, &val[i++], 1);
			k++;
		}
	}
	va_end(args);
	return (k);
}

// int main() {
// 	int n = -9;
// 	int s = 1813;
// 	char *str = "";
// 	char c = 't';

// 	printf("%d\n", printf("test c: %c\n", c));
// 	printf("%d\n\n", ft_printf("test c: %c\n", c));

// 	printf("%d\n", printf("%s", ""));
// 	printf("%d\n\n", ft_printf("%s", ""));

//    	printf("%d\n", printf("test d: %d\n", -1));
// 	printf("%d\n\n", ft_printf("test d: %d\n", -1));

// 	printf("%d\n", printf("test i: %i\n", n));
// 	printf("%d\n\n", ft_printf("test i: %i\n", n));

// 	printf("%d\n", printf("test u: %u\n", n));
// 	printf("%d\n\n", ft_printf("test u: %u\n", n));

// 	printf("test x: %x\n", 0Xfffffffffff);
// 	ft_printf("test x: %x\n", 0Xffffffffff);

// 	printf("%d\n", printf("test X: %X\n", s));
// 	printf("%d\n\n", ft_printf("test X: %X\n", s));

// 	printf("%d\n", printf("test %%: %%\n"));
// 	printf("%d\n\n", ft_printf("test %%: %%\n"));

// 	printf("%d\n", printf("test p: %p\n", LONG_MAX));
// 	printf("%d\n\n", ft_printf("test p: %p\n", LONG_MAX));
// 	return 0;
// }