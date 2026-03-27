/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:27:10 by lbento            #+#    #+#             */
/*   Updated: 2026/03/27 11:58:26 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void			check_texture(char *line, t_file *file, t_gc **collector);
void			check_color(char *line, t_file *file, t_gc **collector);
static int		isnt_rgb(char *line, t_gc **collector);
static int		dotxpm(char *file, t_gc **collector);

void	check_texture(char *line, t_file *file, t_gc **collector)
{
	char	*path;

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
		return ;
	}
	if (dotxpm(path, collector))
		print_error(3, collector);
	gc_free(collector, path);
}

static int	dotxpm(char *line, t_gc **collector)
{
	int	fd;
	int	len;

	len = ft_strlen(line);
	if (len < 5)
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

void	check_color(char *line, t_file *file, t_gc **collector)
{
	char	*path;

	path = ft_strtrim(line, "\n", collector);
	if (!path)
		print_error(10, collector);
	if (!ft_strncmp(path, "F ", 2))
	{
		file->floor_color = ft_strdup(path + 2, collector);
		if (isnt_rgb(file->floor_color, collector))
			print_error(42, collector);
	}
	else if (!ft_strncmp(path, "C ", 2))
	{
		file->sky_color = ft_strdup(path + 2, collector);
		if (isnt_rgb(file->sky_color, collector))
			print_error(5, collector);
	}
	gc_free(collector, path);
}

static int	isnt_rgb(char *line, t_gc **collector)
{
	int		value;
	char	**rgb;
	int		i;

	rgb = ft_split(line, ',', collector);
	if (!rgb)
		print_error(10, collector);
	i = 0;
	while (rgb[i])
		i++;
	if (i != 3)
		return (1);
	i = 0;
	while (rgb[i])
	{
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
			return (1);
		if (value == 0 && rgb [i][0] != '0')
			return (1);
		i++;
	}
	return (0);
}
