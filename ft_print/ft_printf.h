/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:57:55 by sjesione          #+#    #+#             */
/*   Updated: 2025/01/13 19:42:27 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	printf_c(int c);
int	printf_s(char *s);
int	printf_dandi(int number, int counter);
int	printf_p(unsigned long long ptr, int counter);
int	printf_u(unsigned int n, int counter);
int	checker_arg(va_list args, char c);
int	printf_x(unsigned int n, char form, int counter);

#endif
