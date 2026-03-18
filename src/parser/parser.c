/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:12:00 by lbento            #+#    #+#             */
/*   Updated: 2026/03/17 23:08:47 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void  parsing(char *map, t_gc **collector);
int	dotcub(char *map);
void	parse_file(char *map, t_file **file, t_gc **collector);

void  parsing(char *map, t_gc **collector)
{
	t_file	*file;

	file = gc_malloc(collector, sizeof(t_file));
	file->content_line = NULL;
	file->next = NULL;
	if (dotcub(map))
		print_error (1, collector);
	parse_file(map, &file, collector);
}

int	dotcub(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len == 0)
		return (1);
	if (len < 5)
		return (1);
	if (ft_strcmp((map + len - 4), ".cub") != 0)
		return (1);
	return (0);
}

void	parse_file(char *map, t_file **file, t_gc **collector)
{
	int	fd;
	char *line;

	fd = open(map, __O_DIRECTORY);
	if (fd != -1)
		print_error(2, NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error(2, NULL);
	line = get_next_line(fd, collector);
	while (line)
	{
		if (ft_strlen (line) > 1)
			add_content (line, file, collector);
		gc_free(collector, line);
		line = get_next_line(fd, collector);
	}
	close (fd);
	if ((*file)->content_line == NULL)
		print_error(3, collector);
}
