/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:14 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/11 15:48:54 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	if (argc != 2)
		ft_error(6);
	check_filename(argv[1]);
	read_map(&map, argv[1]);
	map_checker(&map);
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx, map.columns * PXL, map.rows * PXL,
			"so_long");
	image_initialzer(&map);
	map_printer(&map);
	mlx_loop(map.mlx);
}
