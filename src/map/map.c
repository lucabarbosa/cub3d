/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:56:02 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 09:10:23 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/cub3d.h"

int g_grid[MAP_NUM_ROWS][MAP_NUM_COLS] = {
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

/* Equivalente ao Map::hasWall() do JS */
int     map_has_wall(double x, double y)
{
    int map_x;
    int map_y;

    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
        return (0);
    map_x = (int)(x / TILE_SIZE);
    map_y = (int)(y / TILE_SIZE);
    return (g_grid[map_y][map_x] != 0);
}

/* Equivalente ao Map::render() do JS */
void    map_render(t_img *img)
{
    int tile_color;
    int tx;
    int ty;
    int i;
    int j;

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
