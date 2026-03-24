/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:27:10 by lbento            #+#    #+#             */
/*   Updated: 2026/03/24 19:23:39 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

static int	dotxpm(char *file, t_gc **collector);
//static char	*add_texture(char *line, t_gc **collector);

int	check_texture(char *line, t_file *file, t_gc **collector)
{
	if (dotxpm(line, collector))
		return (0);
	if (ft_strncmp(line, "NO", 2) == 0)
		file->no = ft_strdup(line + 3, collector);
	else if (ft_strncmp(line, "SO", 2) == 0)
		file->so = ft_strdup(line + 3, collector);
	else if (ft_strncmp(line, "WE", 2) == 0)
		file->we = ft_strdup(line + 3, collector);
	else if (ft_strncmp(line, "EA", 2) == 0)
		file->ea = ft_strdup(line + 3, collector);
	return (0);
}

static int	dotxpm(char *line, t_gc **collector)
{
	int	fd;
	int	len;

	len = ft_strlen(line);
	if (len == 0)
		return (1);
	if (ft_strncmp((line + len - 5), ".xpm", 4) != 0)
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

// static char	*add_texture(char *line, t_gc **collector)
// {
// 	int	len;

// 	len = ft_strlen(line);
	
// }
