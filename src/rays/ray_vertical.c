/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vertical.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 11:16:41 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/09 07:12:37 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_vert_step(t_ray *ray, t_step *step)
{
	step->x = TILE_SIZE;
	if (ray->is_facing_left)
		step->x = -TILE_SIZE;
	step->y = TILE_SIZE * tan(ray->ray_angle);
	if (ray->is_facing_up && step->y > 0)
		step->y *= -1;
	if (ray->is_facing_down && step->y < 0)
		step->y *= -1;
}

static void	vert_wall_loop(t_ray *ray, t_map *map, t_vert *v, t_step *step)
{
	while (v->hit_x >= 0 && v->hit_x <= map->cols * TILE_SIZE
		&& v->hit_y >= 0 && v->hit_y <= map->rows * TILE_SIZE)
	{
		if (ray->is_facing_left && map_has_wall(map, v->hit_x - 1, v->hit_y))
		{
			v->found = 1;
			return ;
		}
		if (!ray->is_facing_left && map_has_wall(map, v->hit_x, v->hit_y))
		{
			v->found = 1;
			return ;
		}
		v->hit_x += step->x;
		v->hit_y += step->y;
	}
}

void	cast_vertical(t_ray *ray, t_player *p, t_map *map, t_vert *v)
{
	t_step	step;

	v->found = 0;
	v->hit_x = floor(p->x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_right)
		v->hit_x += TILE_SIZE;
	v->hit_y = p->y + (v->hit_x - p->x) * tan(ray->ray_angle);
	get_vert_step(ray, &step);
	vert_wall_loop(ray, map, v, &step);
}

void	set_vert_result(t_player *p, t_vert *v, double *vd)
{
	if (v->found)
		*vd = dist_points(p->x, p->y, v->hit_x, v->hit_y);
	else
		*vd = DBL_MAX;
}
