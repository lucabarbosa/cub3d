/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture_color.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 22:27:10 by lbento            #+#    #+#             */
/*   Updated: 2026/04/06 01:38:32 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void			check_texture(char *line, t_file *file, t_gc **collector);
void			check_color(char *line, t_file *file, t_gc **collector);
static int		isnt_rgb(char *line, t_gc **collector);

void	check_texture(char *line, t_file *file, t_gc **collector)
{
	char	*path;
	int		i;

	path = ft_strtrim(line, "\n", collector);
	if (!path)
		print_error(10, collector);
	i = 0;
	i = skip_space_tab(path, i);
	if (!ft_strncmp(path + i, "NO", 2))
		file->no = ft_strdup(path + skip_space_tab(path, i + 1), collector);
	else if (!ft_strncmp(path + i, "SO", 2))
		file->so = ft_strdup(path + skip_space_tab(path, i + 1), collector);
	else if (!ft_strncmp(path + i, "WE", 2))
		file->we = ft_strdup(path + skip_space_tab(path, i + 1), collector);
	else if (!ft_strncmp(path + i, "EA", 2))
		file->ea = ft_strdup(path + skip_space_tab(path, i + 1), collector);
	else
	{
		gc_free(collector, path);
		return ;
	}
	if (dotxpm(path, collector))
		print_error(3, collector);
	gc_free(collector, path);
}

void	check_color(char *line, t_file *file, t_gc **collector)
{
	char	*path;
	int		i;
	char	identifier;

	path = ft_strtrim(line, "\n", collector);
	if (!path)
		print_error(10, collector);
	i = 0;
	i = skip_space_tab(path, i);
	identifier = path[i];
	i++;
	i = skip_space_tab(path, i);
	if (identifier == 'F')
	{
		file->floor_color = ft_strdup(path + i, collector);
		if (isnt_rgb(file->floor_color, collector))
			print_error(5, collector);
	}
	if (identifier == 'C')
	{
		file->sky_color = ft_strdup(path + i, collector);
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
		if (isnt_digit(rgb[i]))
		return (1);
		value = ft_atoi(rgb[i]);
		if (value < 0 || value > 255)
			return (1);
		i++;
	}
	return (0);
}
