/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:11:57 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/10 17:58:52 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(void)
{
}

void	table_counter(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error();
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_error();
	}
	map->columns = ft_strlen(line);
	free(line);
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		map->rows++;
	}
	close(fd);
}

void	read_map(t_map *map, char *filename)
{
	int	fd;
	int	i;

	table_counter(map, filename);
	fd = open(filename, O_RDONLY);
	map->mapp = malloc(sizeof(char *) * map->rows);
	if (!map->mapp)
		ft_error();
	i = 0;
	while (i < map->rows)
	{
		map->mapp[i++] = get_next_line(fd);
	}
	close(fd);
}
