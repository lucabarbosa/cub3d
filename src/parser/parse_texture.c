/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:27:10 by lbento            #+#    #+#             */
/*   Updated: 2026/03/24 22:54:41 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

static int	dotxpm(char *file, t_gc **collector);

int	check_texture(char *line, t_file *file, t_gc **collector)
{
	char *path;
	
	path = ft_strtrim(line, "\n", collector);
	if (!path)
		print_error(10, collector);
	if (!ft_strncmp(path, "NO", 2))
		file->no = ft_strdup(path + 3, collector);
	else if (!ft_strncmp(path, "SO", 2))
		file->so = ft_strdup(path + 3, collector);
	else if (!ft_strncmp(path, "WE", 2))
		file->we = ft_strdup(path + 3, collector);
	else if (!ft_strncmp(path, "EA", 2))
		file->ea = ft_strdup(path + 3, collector);
	else
	{
		gc_free(collector, path);
		return (0);
	}
	if (dotxpm(path, collector))
		return (1);
	gc_free(collector, path);
	return (0);
}

static int	dotxpm(char *line, t_gc **collector)
{
	int	fd;
	int	len;

	len = ft_strlen(line);
	if (len == 0)
		return (1);
	if (ft_strncmp((line + len - 4), ".xpm", 4))
		return (1);
	fd = open(line, __O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("The texture can't be a directory.\n", 2);
		gc_clear(collector);
		exit (1);
	}
	return (0);
}
