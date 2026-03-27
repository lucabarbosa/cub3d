/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:12:00 by lbento            #+#    #+#             */
/*   Updated: 2026/03/27 11:58:39 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void		parsing(char *map, t_file *file, t_gc **collector);
void		parse_file(char *map, t_file *file, t_gc **collector);
static int	dotcub(char *map, t_gc **collector);

void	parsing(char *map, t_file *file, t_gc **collector)
{
	if (dotcub(map, collector))
		print_error (1, collector);
	parse_file(map, file, collector);
}

static int	dotcub(char *map, t_gc **collector)
{
	int	fd;
	int	len;

	len = ft_strlen(map);
	if (len == 0)
		return (1);
	if (len < 5)
		return (1);
	if (ft_strcmp((map + len - 4), ".cub") != 0)
		return (1);
	fd = open(map, __O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("The map can't be a directory.\n", 2);
		gc_clear(collector);
		exit (1);
	}
	return (0);
}

void	parse_file(char *map, t_file *file, t_gc **collector)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error(2, NULL);
	line = get_next_line(fd, collector);
	while (line)
	{
		if (ft_strlen (line) > 1)
		{
			check_texture(line, file, collector);
			check_color(line, file, collector);
			// if (check_map(line, file, collector))
			// 		print_error(3, collector);
		}
		gc_free(collector, line);
		line = get_next_line(fd, collector);
	}
	close (fd);
	if (!file->no || !file->so || !file->we || !file->ea)
		print_error(4, collector);
	if (!file->sky_color || !file->floor_color)
		print_error(6, collector);
}
