/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:56:02 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 12:00:31 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"
//REFACTOR: be a malloct array of ints

int g_grid[11][15] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,0,0,1,0,1},
    {1,1,1,1,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,1,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void    map_load_hardcoded(t_map *map)
{
    int i;

    map->rows      = 11;
    map->cols      = 15;
    map->tile_size = 64;
    map->grid      = malloc(sizeof(int *) * map->rows);
    if (!map->grid)
        return ;
    i = 0;
    while (i < map->rows)
    {
        map->grid[i] = malloc(sizeof(int) * map->cols);
        if (!map->grid[i])
            return ;
        ft_memcpy(map->grid[i], g_grid[i], sizeof(int) * map->cols);
        i++;
    }
		map->tex_no = "assets/textures/north.xpm";
		map->tex_so = "assets/textures/south.xpm";
		map->tex_ea = "assets/textures/east.xpm";
		map->tex_we = "assets/textures/west.xpm";
}

void    map_free(t_map *map)
{
    int i;

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

int     map_has_wall(t_map *map, double x, double y)
{
    int map_x;
    int map_y;
    int win_w;
    int win_h;

    win_w = map->cols * map->tile_size;
    win_h = map->rows * map->tile_size;
    if (x < 0 || x >= win_w || y < 0 || y >= win_h)
        return (0);
    map_x = (int)(x / map->tile_size);
    map_y = (int)(y / map->tile_size);
    return (map->grid[map_y][map_x] != 0);
}

void	map_render(t_img *img)
{
	int	tile_color;
	int	tx;
	int	ty;
	int	i;
	int	j;

	i = 0;
	while (i < MAP_NUM_ROWS)
	{
		j = 0;
		while (j < MAP_NUM_COLS)
		{
			tx = j * TILE_SIZE;
			ty = i * TILE_SIZE;
			if (g_grid[i][j] == 1)
				tile_color = color(34, 34, 34);
			else
				tile_color = color(255, 255, 255);
			draw_rect(img, tx, ty, TILE_SIZE, TILE_SIZE, tile_color);
			draw_rect(img, tx, ty, TILE_SIZE, 1, color(34, 34, 51));
			draw_rect(img, tx, ty, 1, TILE_SIZE, color(34, 34, 51));
			j++;
		}
		i++;
	}
}
