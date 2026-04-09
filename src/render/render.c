/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:48:07 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/04 11:48:17 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void    render_walls(t_engine *e)
// {
//     double  dist_proj_plane;
//     double  corrected;
//     double  wall_height;
//     int     draw_start;
//     int     draw_end;
//     int     i;
//     int     y;
//
//     dist_proj_plane = (WIN_W / 2.0) / tan(FOV_ANGLE * M_PI / 180.0 / 2.0);
//     i = 0;
//     while (i < NUM_RAYS)
//     {
//         corrected = e->rays[i].distance
//             * cos(e->rays[i].ray_angle - e->player.rotation_angle);
//         wall_height = (TILE_SIZE * dist_proj_plane) / corrected;
//         draw_start = (WIN_H / 2) - (wall_height / 2);
//         draw_end = draw_start + (int)wall_height;
//         y = draw_start;
//         while (y < draw_end)
//         {
//             put_pixel(&e->frame, i, y, 0x00FFFFFF);
//             y++;
//         }
//         i++;
//     }
// }
