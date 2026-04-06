/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:26:38 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 09:26:40 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    scene_render(t_img *img, t_map *map)
{

	t_rect floor;
	t_rect ceiling;

	floor.x = 0;
	floor.y = 0;
	floor.w = WIN_W;
	floor.h = WIN_H;
	floor.color = map->floor_color;

	ceiling.x = 0;
	ceiling.y = WIN_W / 2;
	ceiling.w = WIN_W;
	ceiling.h = WIN_H / 2;
	ceiling.color = map->floor_color;
	// draw_rect(img,ceiling);
	// draw_rect(img,floor);
    draw_rect(img, 0, 0, WIN_W, WIN_H / 2, map->ceiling_color);
    draw_rect(img, 0, WIN_H / 2, WIN_W, WIN_H / 2, map->floor_color);
}
