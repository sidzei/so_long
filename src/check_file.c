/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:14:29 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/11 18:36:19 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_filename(char *filename, t_map *map)
{
	size_t	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		ft_error(3, map);
	if (filename[len - 2] != 'e')
		ft_error(3, map);
	if (filename[len - 3] != 'b')
		ft_error(3, map);
	if (filename[len - 4] != '.')
		ft_error(3, map);
}

void	map_border(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->rows)
		if ((size_t)map->columns != ft_strlen(map->mapp[i]))
			ft_error(7, map);
	i = -1;
	while (++i < map->columns - 1)
	{
		if (map->mapp[0][i] != '1')
			ft_error(4, map);
		if (map->mapp[map->rows - 1][i] != '1')
			ft_error(4, map);
	}
	i = -1;
	while (++i < map->rows)
	{
		if (map->mapp[i][0] != '1')
			ft_error(4, map);
		if (map->mapp[i][map->columns - 1] != '1')
			ft_error(4, map);
	}
}

void	map_check(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->mapp[i][j] != '1' && map->mapp[i][j] != '0'
				&& map->mapp[i][j] != 'C' && map->mapp[i][j] != 'E'
				&& map->mapp[i][j] != 'P')
				ft_error(5, map);
			if (map->mapp[i][j] == 'E')
				map->e++;
			if (map->mapp[i][j] == 'P')
				map->p++;
			if (map->mapp[i][j] == 'C')
				map->c++;
		}
	}
	if (map->e != 1 || map->p != 1)
		ft_error(5, map);
}

void	map_checker(t_map *map)
{
	int	i;
	int	j;

	map_check(map);
	map_border(map);
	i = -1;
	while (++i < map->rows)
	{
		j = -1;
		while (++j < map->columns)
		{
			if (map->mapp[i][j] == 'P')
			{
				map->player.x = i;
				map->player.y = j;
			}
		}
	}
}
