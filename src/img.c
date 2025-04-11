/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:01:37 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/11 15:49:28 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	image_initialzer(t_map *map)
{
	int	a;

	a = PXL;
	map->img.player = mlx_xpm_file_to_image(map->mlx, "images/player.xpm", &a,
			&a);
	map->img.e_img = mlx_xpm_file_to_image(map->mlx, "images/empty.xpm", &a,
			&a);
	map->img.w_img = mlx_xpm_file_to_image(map->mlx, "images/wall.xpm", &a, &a);
	map->img.c_img = mlx_xpm_file_to_image(map->mlx, "images/collectible.xpm",
			&a, &a);
	map->img.es_img = mlx_xpm_file_to_image(map->mlx, "images/escape.xpm", &a,
			&a);
	if (!map->img.player || !map->img.e_img || !map->img.w_img
		|| !map->img.c_img || !map->img.es_img)
	{
		ft_putstr_fd("Error\nOne or more images failed to load\n", 2);
		exit(1);
	}
}

void	map_maker(t_map *map, int i, int j)
{
	int	type;

	type = map->mapp[j / PXL][i / PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->window, map->img.e_img, i, j);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->window, map->img.c_img, i, j);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->window, map->img.player, i, j);
	else if (type == 'E')
		mlx_put_image_to_window(map->mlx, map->window, map->img.es_img, i, j);
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->window, map->img.w_img, i, j);
}

void	map_printer(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->columns)
	{
		j = -1;
		while (++j < map->rows)
			map_maker(map, i * PXL, j * PXL);
	}
}
