/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:14:29 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/10 18:05:20 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		ft_error();
	if (filename[len - 2] != 'e')
		ft_error();
	if (filename[len - 3] != 'b')
		ft_error();
	if (filename[len - 4] != '.')
		ft_error();
}

void	map_border(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		if (map->columns != ft_strlen(map->mapp[i]))
			ft_error();
	i = -1;
	while (++i < map->columns)
	{
		if (map->mapp[0][i] != 1)
			ft_error();
		if (map->mapp[map->rows - 1][i] != 1)
			ft_error();
	}
	i = -1;
	while (++i < map->rows)
	{
		if (map->mapp[i][0])
			ft_error();
		if (map->mapp[i][map->columns - 1])
			ft_error();
	}
}

void	map_check(t_map *map)
{
	int	i;
	int	j;

	map->c = 0;
	map->p = 0;
	map->e = 0;
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->mapp[i][j] == 'E')
				map->e++;
			if (map->mapp[i][j] == 'P')
				map->p++;
			if (map->mapp[i][j] == 'C')
				map->c++;
		}
	}
	if (map->e != 1 || map->p != 1)
		ft_error();
}
void	map_checker(t_map *map)
{
	map_check(map);
	map_border(map);
}