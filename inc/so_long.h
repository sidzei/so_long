/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:19:58 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/11 17:33:53 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PXL 100

# include "../ft_print/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_img
{
	void		*es_img;
	void		*w_img;
	void		*c_img;
	void		*c_collected_img;
	void		*e_img;
	void		*e_open_img;
	void		*player;
}				t_img;

typedef struct s_map
{
	int			es;
	int			w;
	int			c;
	int			c_collected;
	int			e;
	int			e_open;
	int			p;
	int			rows;
	int			columns;
	char		**mapp;
	void		*mlx;
	void		*window;
	t_player	player;
	t_img		img;

}				t_map;

void			ft_close(t_map *map);
int				moves(int keycode, t_map *map);
void			image_initialzer(t_map *map);
void			map_maker(t_map *map, int x, int y);
void			map_printer(t_map *map);
void			ft_error(int error, t_map *map);
void			read_map(t_map *map, char *filename);
void			table_counter(t_map *map, char *filename);
void			check_filename(char *filename, t_map *map);
void			map_border(t_map *map);
void			map_check(t_map *map);
void			map_checker(t_map *map);

#endif