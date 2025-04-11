/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjesione < sjesione@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:11:57 by sjesione          #+#    #+#             */
/*   Updated: 2025/04/11 18:58:07 by sjesione         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(int error, t_map *map)
{
	int	i;

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
	if (error == 7)
		write(2, "Error7\n", 6);
	if (map)
	{
		i = -1;
		while (++i < map->rows)
			free(map->mapp[i]);
		free(map->mapp);
		free(map->mlx);
	}
	exit(1);
}

void	table_counter(t_map *map, char *filename)
{
	int		fd;
	char	*line;
	int		empty_line_found;

	empty_line_found = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(1, map);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		ft_error(1, map);
	}
	map->columns = ft_strlen(line);
	if (line[map->columns - 1] == '\n')
		map->columns--;
	free(line);
	map->rows = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (*line == '\n' && *(line + 1) == '\0')
		{
			empty_line_found = 1;
			free(line);
			continue ;
		}
		else if (*line == '\0')
		{
			free(line);
			break ;
		}
		if (!empty_line_found)
			map->rows++;
		free(line);
	}
	close(fd);
}

void	read_map(t_map *map, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	int		len;

	i = 0;
	table_counter(map, filename);
	fd = open(filename, O_RDONLY);
	if (!(map->mapp = malloc(sizeof(char *) * map->rows)))
		ft_error(2, map);
	while (i < map->rows && (line = get_next_line(fd)))
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (*line || i < map->rows - 1)
			map->mapp[i++] = line;
		else
			free(line);
	}
	if (i < map->rows)
		ft_error(1, map);
	while ((line = get_next_line(fd)))
		free(line);
	close(fd);
}
