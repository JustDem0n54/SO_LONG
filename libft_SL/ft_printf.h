/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrontard <nrontard@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:45:30 by nrontard          #+#    #+#             */
/*   Updated: 2024/12/03 13:47:31 by nrontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define BASE16 "0123456789abcdef"
# define BASE16M "0123456789ABCDEF"

int		ft_putnbr(int n, int fd);
int		ft_putchar(char c);
int		ft_putstr(char *s, int fd);
int		use_format(char c, va_list args);
int		ft_printf(const char *val, ...);
int		ft_puthexanbr_fd(size_t n, int fd, char c);
int		ft_len_nbr(int n);
int		ft_len_hexa(size_t n);
int		ft_putnbr_u(unsigned long n, int fd);
int		ft_len_nbru(unsigned long n);
int		check_args(va_list args);
int		hexa_p(void *n);

#endif 