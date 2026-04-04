/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:54:02 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/04 11:44:37 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    player_init(t_player *p, t_map *map)
{
	//REFACTOR: x e y vai ser de acordo com a coordenada passada no mapa;
    p->x              = (map->cols / 2) * map->tile_size + map->tile_size / 2;
    p->y              = (map->rows / 2) * map->tile_size + map->tile_size / 2;
    p->radius         = 5;
    p->turn_direction = 0;
    p->walk_direction = 0;
		//REFACTOR: aqui vai ser de acordo com a letra do mapa
    p->rotation_angle = 3.0 * M_PI / 2.0;
    p->move_speed     = 2.0;
    p->rotation_speed = 2.0 * (M_PI / 180.0);
}

void    player_update(t_player *p, t_map *map)
{
    double  move_step;
    double  nx;
    double  ny;

    p->rotation_angle += p->rotation_speed * p->turn_direction;
    move_step = p->move_speed * p->walk_direction;
    nx = p->x + cos(p->rotation_angle) * move_step;
    ny = p->y + sin(p->rotation_angle) * move_step;
    if (!map_has_wall(map, nx, ny))
    {
        p->x = nx;
        p->y = ny;
    }
}

void	player_render(t_img *img, t_player *p)
{
	int		red;
	t_line	line;

	red = color(255, 0, 0);
	draw_circle_red(img, (int)p->x, (int)p->y, p->radius);
	line.x0 = (int)p->x;
	line.y0 = (int)p->y;
	line.x1 = (int)(p->x + cos(p->rotation_angle) * 20);
	line.y1 = (int)(p->y + sin(p->rotation_angle) * 20);
	draw_line(img, &line, red);
}
