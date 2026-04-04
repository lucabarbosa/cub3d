/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 10:37:49 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/04 11:34:16 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double   normalize_angle(double angle)
{
    angle = fmod(angle, 2 * M_PI);
    if (angle < 0)
        angle += 2 * M_PI;
    return (angle);
}

static double   dist_points(double x1, double y1, double x2, double y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void    init_ray(t_ray *ray, double ray_angle)
{
    ray->ray_angle = normalize_angle(ray_angle);
    ray->wall_hit_x = 0;
    ray->wall_hit_y = 0;
    ray->distance = 0;
    ray->was_hit_vertical = 0;
    ray->wall_x = 0;
    ray->is_facing_down = ray->ray_angle > 0 && ray->ray_angle < M_PI;
    ray->is_facing_up = !ray->is_facing_down;
    ray->is_facing_right = ray->ray_angle < M_PI / 2
        || ray->ray_angle > (3 * M_PI) / 2;
    ray->is_facing_left = !ray->is_facing_right;
}

static void get_horz_step(t_ray *ray, double *xstep, double *ystep)
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

static void cast_horizontal(t_ray *ray, t_player *p, t_map *map, t_horz *h)
{
    double  x;
    double  y;
    double  xstep;
    double  ystep;

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

static void get_vert_step(t_ray *ray, double *xstep, double *ystep)
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

static void cast_vertical(t_ray *ray, t_player *p, t_map *map, t_vert *v)
{
    double  x;
    double  y;
    double  xstep;
    double  ystep;

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
static void set_horz_result(t_player *p, t_horz *h, double *hd)
{
    if (h->found)
        *hd = dist_points(p->x, p->y, h->hit_x, h->hit_y);
    else
        *hd = DBL_MAX;
}

static void set_vert_result(t_player *p, t_vert *v, double *vd)
{
    if (v->found)
        *vd = dist_points(p->x, p->y, v->hit_x, v->hit_y);
    else
        *vd = DBL_MAX;
}

static void set_ray_result(t_ray *ray, t_player *p, t_horz *h, t_vert *v)
{
    double  hd;
    double  vd;

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

void    cast_ray(t_ray *ray, t_player *p, t_map *map)
{
    t_horz  h;
    t_vert  v;

    cast_horizontal(ray, p, map, &h);
    cast_vertical(ray, p, map, &v);
    set_ray_result(ray, p, &h, &v);
}

void    cast_all_rays(t_engine *e)
{
    double  ray_angle;
    int     i;

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

void    rays_render(t_img *img, t_engine *e)
{
    int     i;
    t_line  line;

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
