/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:05:15 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 10:06:45 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int mm(double v)
{
    return ((int)(v * MINIMAP_SCALE));
}
void    minimap_render(t_img *img, t_player *p)
{
    int i;
    int j;
    int tx;
    int ty;
    int nx; // posição do próximo tile
    int ny;
    int mw; // largura real até o próximo tile
    int mh;

    i = 0;
    while (i < MAP_NUM_ROWS)
    {
        j = 0;
        while (j < MAP_NUM_COLS)
        {
            tx = mm(j * TILE_SIZE);
            ty = mm(i * TILE_SIZE);
            nx = mm((j + 1) * TILE_SIZE);
            ny = mm((i + 1) * TILE_SIZE);
            mw = nx - tx; // sem gap de truncamento
            mh = ny - ty;
            if (g_grid[i][j] == 1)
            {
                draw_rect(img, tx, ty, mw, mh, color(34, 34, 34));
                draw_rect(img, tx, ty, mw, 1,  color(34, 34, 51));
                draw_rect(img, tx, ty, 1,  mh, color(34, 34, 51));
            }
            j++;
        }
        i++;
    }
    draw_circle(img, mm(p->x), mm(p->y),
        (int)(p->radius * MINIMAP_SCALE) + 1, color(0, 0, 255));
    draw_line(img,
        mm(p->x), mm(p->y),
        (int)(mm(p->x) + cos(p->rotation_angle) * 20 * MINIMAP_SCALE),
        (int)(mm(p->y) + sin(p->rotation_angle) * 20 * MINIMAP_SCALE),
        color(0, 0, 255));
}
