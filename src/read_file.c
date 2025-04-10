/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:11:57 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/10 20:15:38 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(int error)
{
	if (error == 1)
		write(2, "Error1\n", 6);
	if (error == 2)
		write(2, "Error2\n", 6);
	if (error == 3)
		write(2, "Error3\n", 6);
	if (error == 4)
		write(2, "Error4\n", 6);
	if (error == 5)
		write(2, "Error5\n", 6);
	if (error == 6)
		write(2, "Error6\n", 6);
	if (error == 7)
		write(2, "Error7\n", 6);
	exit(1);
}

void	table_counter(t_map *map, char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_error(1);
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
		ft_error(2);
	i = 0;
	while (i < map->rows)
	{
		map->mapp[i++] = get_next_line(fd);
	}
	close(fd);
}
