/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 01:19:20 by lbento            #+#    #+#             */
/*   Updated: 2026/04/10 14:13:42 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

int		dotcub(char *map, t_gc **collector);
int		dotxpm(char *line, t_gc **collector);
int		isnt_digit(char *str);
int		skip_space_tab(char *path, int i);
void	check_permissions(t_file *file, t_gc **collector);

int	dotcub(char *map, t_gc **collector)
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
	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error(11, collector);
	close (fd);
	return (0);
}

int	dotxpm(char *line, t_gc **collector)
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

int	isnt_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (!str[i])
		return (1);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	skip_space_tab(char *path, int i)
{
	if (i != 0)
		i++;
	while (path[i] == ' ' || path[i] == '\t')
		i++;
	return (i);
}

void	check_permissions(t_file *file, t_gc **collector)
{
	int	fd;

	fd = open(file->no, O_RDONLY);
	if (fd < 0)
		print_error(11, collector);
	close (fd);
	fd = open(file->so, O_RDONLY);
	if (fd < 0)
		print_error(11, collector);
	close (fd);
	fd = open(file->we, O_RDONLY);
	if (fd < 0)
		print_error(11, collector);
	close (fd);
	fd = open(file->ea, O_RDONLY);
	if (fd < 0)
		print_error(11, collector);
	close (fd);
}
