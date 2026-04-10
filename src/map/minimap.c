/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:05:15 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/09 07:16:42 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	mm(double v)
{
	return ((int)(v * MINIMAP_SCALE));
}

static void	draw_tile(t_img *img, t_rect rect)
{
	rect.color = color(0, 0, 0);
	draw_rect(img, rect);
}

void	minimap_render(t_img *img, t_player *p, t_map *map)
{
	t_rect	rect;
	int		i;
	int		j;

	(void)p;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			rect.x = mm(j * TILE_SIZE);
			rect.y = mm(i * TILE_SIZE);
			rect.w = mm((j + 1) * TILE_SIZE) - rect.x;
			rect.h = mm((i + 1) * TILE_SIZE) - rect.y;
			if (map->grid[i][j] == 1)
				draw_tile(img, rect);
			j++;
		}
		i++;
	}
}
