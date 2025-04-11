/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:01:45 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/11 17:21:15 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_map *map)
{
	int	tempx;
	int	tempy;

	tempx = map->player.x - 1;
	tempy = map->player.y;
	if (map->mapp[tempx][tempy] != '1')
	{
		map->mapp[map->player.x][map->player.y] = '0';
		map->mapp[tempx][tempy] = 'P';
		map->player.x = tempx;
		map->player.y = tempy;
	}
	map_printer(map);
}

void	move_down(t_map *map)
{
	int	tempx;
	int	tempy;

	tempx = map->player.x + 1;
	tempy = map->player.y;
	if (map->mapp[tempx][tempy] != '1')
	{
		map->mapp[map->player.x][map->player.y] = '0';
		map->mapp[tempx][tempy] = 'P';
		map->player.x = tempx;
		map->player.y = tempy;
	}
	map_printer(map);
}

void	move_left(t_map *map)
{
	int	tempx;
	int	tempy;

	tempx = map->player.x;
	tempy = map->player.y - 1;
	if (map->mapp[tempx][tempy] != '1')
	{
		map->mapp[map->player.x][map->player.y] = '0';
		map->mapp[tempx][tempy] = 'P';
		map->player.x = tempx;
		map->player.y = tempy;
	}
	map_printer(map);
}

void	move_right(t_map *map)
{
	int	tempx;
	int	tempy;

	tempx = map->player.x;
	tempy = map->player.y + 1;
	if (map->mapp[tempx][tempy] != '1')
	{
		map->mapp[map->player.x][map->player.y] = '0';
		map->mapp[tempx][tempy] = 'P';
		map->player.x = tempx;
		map->player.y = tempy;
	}
	map_printer(map);
}

int	moves(int keycode, t_map *map)
{
	if (keycode == 119)
		move_up(map);
	if (keycode == 115)
		move_down(map);
	if (keycode == 97)
		move_left(map);
	if (keycode == 100)
		move_right(map);
	if (keycode == 65307)
		ft_close(map);
	return (0);
}
