/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:02:04 by lbento            #+#    #+#             */
/*   Updated: 2026/04/07 19:19:57 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

static int	check_chars(t_file *file);
static int	check_player(t_file *file, t_gc **collector);
static int	secure_map(t_file *file, t_gc **collector);
static int	flood_fill(char **map, int row, int col);

void	validate_map(t_file *file, t_gc **collector)
{
	if (!file->no || !file->so || !file->we || !file->ea)
		print_error(4, collector);
	if (!file->sky_color || !file->floor_color)
		print_error(6, collector);
	if (!check_chars(file))
		print_error(7, collector);
	if (!check_player(file, collector))
		print_error(8, collector);
	if (!secure_map(file, collector))
		print_error(9, collector);
}

static int	check_chars(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] != '0' && file->map[i][j] != '1'
				&& file->map[i][j] != 'N' && file->map[i][j] != 'S'
				&& file->map[i][j] != 'E' && file->map[i][j] != 'W'
				&& file->map[i][j] != ' ' && file->map[i][j] != '\t'
				&& file->map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_player(t_file *file, t_gc **collector)
{
	int	i;
	int	j;

	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] == 'N' || file->map[i][j] == 'S'
				|| file->map[i][j] == 'E' || file->map[i][j] == 'W')
			{
				if (file->player)
					return (0);
				file->player = ft_substr(file->map[i], j, 1, collector);
				file->player_row = i;
				file->player_col = j;
			}
			j++;
		}
		i++;
	}
	if (!file->player)
		return (0);
	return (1);
}

static int	secure_map(t_file *file, t_gc **collector)
{
	int		i;
	char	**copied_map;

	i = 0;
	while (file->map[i])
		i++;
	copied_map = gc_malloc(collector, sizeof(char *) * (i + 1));
	if (!copied_map)
		print_error(10, collector);
	i = 0;
	while (file->map[i])
	{
		copied_map[i] = ft_strdup(file->map[i], collector);
		if (!copied_map[i])
			print_error(10, collector);
		i++;
	}
	copied_map[i] = NULL;
	if (!flood_fill(copied_map, file->player_row, file->player_col))
		return (0);
	gc_free(collector, copied_map);
	return (1);
}

static int	flood_fill(char **map, int row, int col)
{
	int	len;
	int	len_line;

	len = 0;
	while (map[len])
	len++;
	if (row < 0 || row >= len)
		return (0);
	len_line = ft_strlen(map[row]);
	if (col < 0 || col >= len_line)
		return (0);
	if (map[row][col] == ' ' || map[row][col] == '\0' || map[row][col] == '\n')
		return (0);
	if (map[row][col] == '1' || map[row][col] == 'V')
		return (1);
	map[row][col] = 'V';
	if (!flood_fill(map, row - 1, col))
		return (0);
	if (!flood_fill(map, row + 1, col))
		return (0);
	if (!flood_fill(map, row, col - 1))
		return (0);
	if (!flood_fill(map, row, col + 1))
		return (0);
	return (1);
}
