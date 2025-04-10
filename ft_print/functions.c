/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:11:27 by sjesione          #+#    #+#             */
/*   Updated: 2025/01/13 19:56:18 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_dandi(int number, int counter)
{
	if (number == -2147483648)
	{
		counter += printf_s("-2147483648");
		return (counter);
	}
	if (number < 0)
	{
		counter += printf_c('-');
		number = -number;
	}
	if (number > 9)
	{
		counter = printf_dandi(number / 10, counter);
		counter += printf_c((number % 10) + '0');
	}
	else
	{
		counter += printf_c(number + '0');
	}
	return (counter);
}

int	printf_u(unsigned int n, int counter)
{
	if (n > 9)
	{
		counter = printf_u(n / 10, counter);
		counter += printf_c(n % 10 + '0');
	}
	else
	{
		counter += printf_c(n + '0');
	}
	return (counter);
}

int	printf_x(unsigned int n, char form, int counter)
{
	char	hex[20];
	int		support;
	int		i;

	i = 0;
	if (n == 0)
	{
		printf_dandi(0, 0);
		return (1);
	}
	while (n != 0)
	{
		support = n % 16;
		if (support < 10)
			hex[i] = support + '0';
		else if (form == 'X')
			hex[i] = support + 'A' - 10;
		else
			hex[i] = support + 'a' - 10;
		i++;
		n = n / 16;
	}
	while (--i >= 0)
		counter += printf_c(hex[i]);
	return (counter);
}

int	printf_p(unsigned long long ptr, int counter)
{
	char				hex[40];
	unsigned long long	support;
	int					i;

	i = 0;
	if (ptr == 0)
		return (printf_s("(nil)"));
	counter += write(1, "0x", 2);
	while (ptr != 0)
	{
		support = ptr % 16;
		if (support < 10)
			hex[i] = support + '0';
		else
			hex[i] = support + 'a' - 10;
		i++;
		ptr = ptr / 16;
	}
	while (--i >= 0)
		counter += printf_c(hex[i]);
	return (counter);
}
