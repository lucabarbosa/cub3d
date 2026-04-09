/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:56:02 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/09 07:17:16 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	map_load(t_map *map, t_file file, t_gc **collector)
{
	map->grid = convert_grid_map(&file, collector);
	map->tile_size = 64;
	map->rows = file.total_lines;
	map->cols = file.total_cols;
	map->tex_no = file.no;
	map->tex_so = file.so;
	map->tex_ea = file.ea;
	map->tex_we = file.we;
	map->player_y = file.player_row;
	map->player_x = file.player_col;
	map->player_dir = *file.player;
	map->ceiling_color = color(file.sky_color->red, file.sky_color->green,
			file.sky_color->blue);
	map->floor_color = color(file.floor_color->red, file.floor_color->green,
			file.floor_color->blue);
}

void	map_free(t_map *map)
{
	int	i;

	if (!map->grid)
		return ;
	i = 0;
	while (i < map->rows)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

int	map_has_wall(t_map *map, double x, double y)
{
	int	map_x;
	int	map_y;
	int	win_w;
	int	win_h;

	win_w = map->cols * map->tile_size;
	win_h = map->rows * map->tile_size;
	if (x < 0 || x >= win_w || y < 0 || y >= win_h)
		return (0);
	map_x = (int)(x / map->tile_size);
	map_y = (int)(y / map->tile_size);
	return (map->grid[map_y][map_x] != 0);
}
