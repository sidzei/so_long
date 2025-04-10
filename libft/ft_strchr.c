/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:08:20 by sjesione          #+#    #+#             */
/*   Updated: 2025/01/03 16:05:30 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)

{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
