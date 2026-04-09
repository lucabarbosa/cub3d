/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_horizontal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 10:51:48 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/09 07:11:07 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_horz_step(t_ray *ray, t_step *step)
{
	step->y = TILE_SIZE;
	if (ray->is_facing_up)
		step->y = -TILE_SIZE;
	step->x = TILE_SIZE / tan(ray->ray_angle);
	if (ray->is_facing_left && step->x > 0)
		step->x *= -1;
	if (ray->is_facing_right && step->x < 0)
		step->x *= -1;
}

static void	horz_wall_loop(t_ray *ray, t_map *map, t_horz *h, t_step *step)
{
	while (h->hit_x >= 0 && h->hit_x <= map->cols * TILE_SIZE
		&& h->hit_y >= 0 && h->hit_y <= map->rows * TILE_SIZE)
	{
		if (ray->is_facing_up && map_has_wall(map, h->hit_x, h->hit_y - 1))
		{
			h->found = 1;
			return ;
		}
		if (!ray->is_facing_up && map_has_wall(map, h->hit_x, h->hit_y))
		{
			h->found = 1;
			return ;
		}
		h->hit_x += step->x;
		h->hit_y += step->y;
	}
}

void	cast_horizontal(t_ray *ray, t_player *p, t_map *map, t_horz *h)
{
	t_step	step;

	h->found = 0;
	h->hit_y = floor(p->y / TILE_SIZE) * TILE_SIZE;
	if (ray->is_facing_down)
		h->hit_y += TILE_SIZE;
	h->hit_x = p->x + (h->hit_y - p->y) / tan(ray->ray_angle);
	get_horz_step(ray, &step);
	horz_wall_loop(ray, map, h, &step);
}

void	set_horz_result(t_player *p, t_horz *h, double *hd)
{
	if (h->found)
		*hd = dist_points(p->x, p->y, h->hit_x, h->hit_y);
	else
		*hd = DBL_MAX;
}
