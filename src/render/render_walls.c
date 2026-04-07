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

void	render_wall_strip(t_engine *e, t_wall_strip *ws)
{
	t_img	*tex;
	int		tex_x;
	int		tex_y;
	int		y;

	tex = get_texture(e, ws->ray);
	tex_x = (int)(ws->ray->wall_x * tex->w);
	y = ws->draw_start;
	while (y < ws->draw_end)
	{
		tex_y = (y - ws->draw_start) * tex->h / ws->wall_height;
		put_pixel(&e->frame, ws->col, y,
			get_tex_color(tex, tex_x, tex_y));
		y++;
	}
}

void	render_walls(t_engine *e)
{
	double			dist_proj_plane;
	double			corrected;
	double			wall_height;
	t_wall_strip	ws;
	int				i;

	dist_proj_plane = (WIN_W / 2.0) / tan(FOV_ANGLE * M_PI / 180.0 / 2.0);
	i = 0;
	while (i < NUM_RAYS)
	{
		corrected = e->rays[i].distance * cos
			(e->rays[i].ray_angle - e->player.rotation_angle);
		wall_height = (TILE_SIZE * dist_proj_plane) / corrected;
		ws.col = i;
		ws.wall_height = (int)wall_height;
		ws.draw_start = (WIN_H / 2) - (ws.wall_height / 2);
		ws.draw_end = ws.draw_start + ws.wall_height;
		ws.ray = &e->rays[i];
		render_wall_strip(e, &ws);
		i++;
	}
}
