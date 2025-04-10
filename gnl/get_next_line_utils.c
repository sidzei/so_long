/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:06:13 by sjesione          #+#    #+#             */
/*   Updated: 2025/03/04 18:03:44 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t			allsize;
	void			*pointer;
	unsigned char	*c;

	if (num != 0 && size > SIZE_MAX / num)
		return (NULL);
	allsize = num * size;
	pointer = malloc(allsize);
	if (pointer == NULL)
		return (NULL);
	c = (unsigned char *)pointer;
	while (allsize--)
		*c++ = '\0';
	return (pointer);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		join[i] = s1[i];
	}
	i = -1;
	while (s2[++i])
	{
		join[i + s1_len] = s2[i];
	}
	join[i + s1_len] = '\0';
	return (join);
}

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

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
