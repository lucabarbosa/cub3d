/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:51:48 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/06 10:51:55 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_horz_step(t_ray *ray, double *xstep, double *ystep)
{
	*ystep = TILE_SIZE;
	if (ray->is_facing_up)
		*ystep = -TILE_SIZE;
	*xstep = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_facing_left && *xstep > 0)
		*xstep *= -1;
	if (ray->is_facing_right && *xstep < 0)
		*xstep *= -1;
}

void	cast_horizontal(t_ray *ray, t_player *p, t_map *map, t_horz *h)
{
	double	x;
	double	y;
	double	xstep;
	double	ystep;

	y = floor(p->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		y += TILE_SIZE;
	x = p->x + (y - p->y) / tan(ray->ray_angle);
	get_horz_step(ray, &xstep, &ystep);
	h->found = 0;
	while (x >= 0 && x <= map->cols * TILE_SIZE
		&& y >= 0 && y <= map->rows * TILE_SIZE)
	{
		if (ray->is_facing_up && map_has_wall(map, x, y - 1))
		{
			h->found = 1;
			h->hit_x = x;
			h->hit_y = y;
			break ;
		}
		if (!ray->is_facing_up && map_has_wall(map, x, y))
		{
			h->found = 1;
			h->hit_x = x;
			h->hit_y = y;
			break ;
		}
		x += xstep;
		y += ystep;
	}
}

void	set_horz_result(t_player *p, t_horz *h, double *hd)
{
	if (h->found)
		*hd = dist_points(p->x, p->y, h->hit_x, h->hit_y);
	else
		*hd = DBL_MAX;
}
