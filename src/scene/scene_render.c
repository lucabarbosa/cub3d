/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:26:38 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/07 16:32:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	scene_render(t_img *img, t_map *map)
{
	t_rect	floor;
	t_rect	ceiling;

	ceiling.x = 0;
	ceiling.y = 0;
	ceiling.w = WIN_W;
	ceiling.h = WIN_H / 2;
	ceiling.color = map->ceiling_color;
	floor.x = 0;
	floor.y = WIN_H / 2;
	floor.w = WIN_W;
	floor.h = WIN_H / 2;
	floor.color = map->floor_color;
	draw_rect(img, ceiling);
	draw_rect(img, floor);
}
