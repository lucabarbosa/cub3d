/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_grid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 17:19:18 by lbento            #+#    #+#             */
/*   Updated: 2026/04/08 18:47:17 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void	total_cols_lines(t_file *file);
int		**convert_grid_map(t_file *file, t_gc **collector);

int	**convert_grid_map(t_file *file, t_gc **collector)
{
	int		i;
	int		j;
	int		**grid;

	i = 0;
	grid = gc_malloc(collector, sizeof(int *) * file->total_lines);
	if (!grid)
		print_error(10, collector);
	while (i < file->total_lines)
	{
		grid[i] = gc_malloc(collector, sizeof(int) * file->total_cols);
		if (!grid)
			print_error(10, collector);
		j = 0;
		while (j < file->total_cols)
		{
			grid[i][j] = 0;
			if (file->map[i][j] == '1')
				grid[i][j] = 1;
			j++;
		}
		i++;
	}
	return (grid);
}

void	total_cols_lines(t_file *file)
{
	int		i;
	int		j;
	int		max_cols;
	char	**map;

	i = 0;
	max_cols = 0;
	map = file->map;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > max_cols)
				max_cols = j;
		i++;
	}
	file->total_cols = max_cols;
	file->total_lines = i;
}
