/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:16:41 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/06 11:18:02 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_vert_step(t_ray *ray, double *xstep, double *ystep)
{
	*xstep = TILE_SIZE;
	if (ray->is_facing_left)
		*xstep = -TILE_SIZE;
	*ystep = TILE_SIZE * tan(ray->ray_angle);
	if (ray->is_facing_up && *ystep > 0)
		*ystep *= -1;
	if (ray->is_facing_down && *ystep < 0)
		*ystep *= -1;
}

void	cast_vertical(t_ray *ray, t_player *p, t_map *map, t_vert *v)
{
	double	x;
	double	y;
	double	xstep;
	double	ystep;

	x = floor(p->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		x += TILE_SIZE;
	y = p->y + (x - p->x) * tan(ray->ray_angle);
	get_vert_step(ray, &xstep, &ystep);
	v->found = 0;
	while (x >= 0 && x <= map->cols * TILE_SIZE
		&& y >= 0 && y <= map->rows * TILE_SIZE)
	{
		if (ray->is_facing_left && map_has_wall(map, x - 1, y))
		{
			v->found = 1;
			v->hit_x = x;
			v->hit_y = y;
			break ;
		}
		if (!ray->is_facing_left && map_has_wall(map, x, y))
		{
			v->found = 1;
			v->hit_x = x;
			v->hit_y = y;
			break ;
		}
		x += xstep;
		y += ystep;
	}
}

void	set_vert_result(t_player *p, t_vert *v, double *vd)
{
	if (v->found)
		*vd = dist_points(p->x, p->y, v->hit_x, v->hit_y);
	else
		*vd = DBL_MAX;
}
