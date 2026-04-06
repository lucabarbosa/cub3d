/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:12:00 by lbento            #+#    #+#             */
/*   Updated: 2026/04/06 01:58:03 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void		parsing(char *map, t_file *file, t_gc **collector);
void		parse_file(int fd, t_file *file, t_gc **collector);
void		check_map(char *line, t_file *file, t_gc **collector);
static int	is_map_line(char *line);

void	parsing(char *map, t_file *file, t_gc **collector)
{
	int	fd;

	if (dotcub(map, collector))
		print_error (1, collector);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error(2, NULL);
	parse_file(fd, file, collector);
	close(fd);
	validate_map(file, collector);
}

void	parse_file(int fd, t_file *file, t_gc **collector)
{
	char	*line;
	int		is_map;

	is_map = 0;
	line = get_next_line(fd, collector);
	while (line)
	{
		if (is_map == 0)
		{
			if (ft_strlen(line) > 1)
			{
				check_texture(line, file, collector);
				check_color(line, file, collector);
			}
			if (is_map_line(line))
				is_map = 1;
		}
		if (is_map == 1)
			check_map(line, file, collector);
		gc_free(collector, line);
		line = get_next_line(fd, collector);
	}
}

static int	is_map_line(char *line)
{
	int	i;

	i = 0;
	i = skip_space_tab(line, i);
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

void	check_map(char *line, t_file *file, t_gc **collector)
{
	int		i;
	char	**new_map;
	char	**old_map;

	i = 0;
	old_map = file->map;
	if (old_map)
		while (old_map[i])
			i++;
	new_map = gc_malloc(collector, sizeof(char *) * (i + 2));
	if (!new_map)
		print_error(10, collector);
	i = 0;
	if (old_map)
		while (old_map[i])
		{
			new_map[i] = old_map[i];
			i++;
		}
	new_map[i] = ft_strdup(line, collector);
	new_map[i + 1] = NULL;
	if (old_map)
		gc_free(collector, old_map);
	file->map = new_map;
}
