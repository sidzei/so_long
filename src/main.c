/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:15:14 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/10 18:20:31 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, int **argv)
{
	t_map	map;

    check_filename(argv[1]);
    read_map(map, argv[1]);
    map_checker(map);
    map.mlx = mlx_init();
    map.window = mlx_new_window(map.mlx,map.rows,map.columns,"so_long");
    
}
