/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 14:46:52 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/04 14:47:26 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    render_wall_strip(t_engine *e, int col, int draw_start,
            int draw_end, int wall_height)
{
    t_img   *tex;
    int     tex_x;
    int     tex_y;
    int     y;

    tex = get_texture(e, &e->rays[col]);
    tex_x = (int)(e->rays[col].wall_x * tex->w);
    y = draw_start;
    while (y < draw_end)
    {
        tex_y = (y - draw_start) * tex->h / wall_height;
        put_pixel(&e->frame, col, y, get_tex_color(tex, tex_x, tex_y));
        y++;
    }
}

void    render_walls(t_engine *e)
{
    double  dist_proj_plane;
    double  corrected;
    double  wall_height;
    int     draw_start;
    int     draw_end;
    int     i;

    dist_proj_plane = (WIN_W / 2.0) / tan(FOV_ANGLE * M_PI / 180.0 / 2.0);
    i = 0;
    while (i < NUM_RAYS)
    {
        corrected = e->rays[i].distance
            * cos(e->rays[i].ray_angle - e->player.rotation_angle);
        wall_height = (TILE_SIZE * dist_proj_plane) / corrected;
        draw_start = (WIN_H / 2) - (wall_height / 2);
        draw_end = draw_start + (int)wall_height;
				//REFACTOR: criar uma struct para render wll strip
        render_wall_strip(e, i, draw_start, draw_end, (int)wall_height);
        i++;
    }
}
