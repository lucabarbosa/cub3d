/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:05:15 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/08 19:02:06 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int  mm(double v)
{
    return ((int)(v * MINIMAP_SCALE));
}

static void draw_tile(t_img *img, int tx, int ty, int mw, int mh)
{
    t_rect  rect;

    rect.x = tx;
    rect.y = ty;
    rect.w = mw;
    rect.h = mh;
    rect.color = color(0, 0, 0);
    draw_rect(img, rect);
}

void    minimap_render(t_img *img, t_player *p, t_map *map)
{
    int i;
    int j;
    int tx;
    int ty;

    (void)p;
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            tx = mm(j * TILE_SIZE);
            ty = mm(i * TILE_SIZE);
            if (map->grid[i][j] == 1)
                draw_tile(img, tx, ty,
                    mm((j + 1) * TILE_SIZE) - tx,
                    mm((i + 1) * TILE_SIZE) - ty);
            j++;
        }
        i++;
    }
}
