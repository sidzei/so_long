/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:01:37 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/10 22:25:38 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	image_initialzer(t_map *map)
{
	int	a;

	a = 50;
	map->img.player = mlx_png_file_to_image(map->mlx, "../images/player.png",&a, &a);
	map->img.e_img = mlx_png_file_to_image(map->mlx, "../images/empty.png", &a,&a);
}

void	map_maker(t_map *map, int x, int y)
{
	int type;

	type = map->mapp[x][y];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->img.es_img, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->img.c_img, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->img.player, x + 8,
			y);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->img.e_img, x, y);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->img.w_img, x, y);
}