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

static int mm(double v)
{
    return ((int)(v * MINIMAP_SCALE));
}

void    minimap_render(t_img *img, t_player *p, t_map *map)
{
	(void) p;
    int i;
    int j;
    int tx;
    int ty;
    int nx; // posição do próximo tile
    int ny;
    int mw; // largura real até o próximo tile
    int mh;

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            tx = mm(j * TILE_SIZE);
            ty = mm(i * TILE_SIZE);
            nx = mm((j + 1) * TILE_SIZE);
            ny = mm((i + 1) * TILE_SIZE);
            mw = nx - tx; // sem gap de truncamento
            mh = ny - ty;
            if (map->grid[i][j] == 1)
                draw_rect(img, tx, ty, mw, mh, color(0, 0, 0));
            j++;
        }
        i++;
    }
    // draw_circle_red(img, mm(p->x), mm(p->y),
    //     (int)(p->radius * MINIMAP_SCALE) + 1);
}
