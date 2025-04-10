/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:27:07 by sjesione          #+#    #+#             */
/*   Updated: 2025/01/13 19:42:45 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_s(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (printf_s("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	checker_arg(va_list args, char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter = printf_c(va_arg(args, int));
	else if (c == 's')
		counter = printf_s(va_arg(args, char *));
	else if (c == 'p')
		counter = printf_p(va_arg(args, unsigned long long), 0);
	else if (c == 'd')
		counter = printf_dandi(va_arg(args, int), 0);
	else if (c == 'i')
		counter = printf_dandi(va_arg(args, int), 0);
	else if (c == 'u')
		counter = printf_u(va_arg(args, unsigned int), 0);
	else if (c == 'x' || c == 'X')
		counter = printf_x(va_arg(args, unsigned long), c, 0);
	else if (c == '%')
	{
		write(1, "%%", 1);
		counter = 1;
	}
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		counter;

	counter = 0;
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		while (s[i] != '%' && s[i] != '\0')
		{
			write(1, &s[i++], 1);
			counter++;
		}
		if (s[i] == '%')
		{
			counter += checker_arg(args, s[++i]);
			i++;
		}
	}
	return (counter);
}
