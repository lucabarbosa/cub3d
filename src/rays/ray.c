/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 10:37:49 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/10 14:18:20 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_ray *ray, double ray_angle)
{
	double	angle;

	angle = normalize_angle(ray_angle);
	ray->ray_angle = angle;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->was_hit_vertical = 0;
	ray->wall_x = 0;
	ray->is_facing_down = (angle > 0 && angle < M_PI);
	ray->is_facing_up = !ray->is_facing_down;
	ray->is_facing_right = (angle < M_PI / 2 || angle > (3 * M_PI) / 2);
	ray->is_facing_left = !ray->is_facing_right;
}

static void	set_ray_result(t_ray *ray, t_player *p, t_horz *h, t_vert *v)
{
	double	hd;
	double	vd;

	set_horz_result(p, h, &hd);
	set_vert_result(p, v, &vd);
	if (hd < vd)
	{
		ray->wall_hit_x = h->hit_x;
		ray->wall_hit_y = h->hit_y;
		ray->distance = hd;
		ray->was_hit_vertical = 0;
		ray->wall_x = fmod(h->hit_x, TILE_SIZE) / TILE_SIZE;
	}
	else
	{
		ray->wall_hit_x = v->hit_x;
		ray->wall_hit_y = v->hit_y;
		ray->distance = vd;
		ray->was_hit_vertical = 1;
		ray->wall_x = fmod(v->hit_y, TILE_SIZE) / TILE_SIZE;
	}
}

void	cast_ray(t_ray *ray, t_player *p, t_map *map)
{
	t_horz	h;
	t_vert	v;

	cast_horizontal(ray, p, map, &h);
	cast_vertical(ray, p, map, &v);
	set_ray_result(ray, p, &h, &v);
}

void	cast_all_rays(t_engine *e)
{
	double	ray_angle;
	int		i;

	ray_angle = e->player.rotation_angle - (FOV_ANGLE * M_PI / 180.0) / 2;
	i = 0;
	while (i < NUM_RAYS)
	{
		init_ray(&e->rays[i], ray_angle);
		cast_ray(&e->rays[i], &e->player, &e->map);
		ray_angle += (FOV_ANGLE * M_PI / 180.0) / NUM_RAYS;
		i++;
	}
}

void	rays_render(t_img *img, t_engine *e)
{
	int		i;
	t_line	line;

	i = 0;
	while (i < NUM_RAYS)
	{
		line.x0 = MINIMAP_SCALE * e->player.x;
		line.y0 = MINIMAP_SCALE * e->player.y;
		line.x1 = MINIMAP_SCALE * e->rays[i].wall_hit_x;
		line.y1 = MINIMAP_SCALE * e->rays[i].wall_hit_y;
		draw_line(img, &line, 0x00FF0000);
		i++;
	}
}
