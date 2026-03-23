/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:54:02 by fabialme          #+#    #+#             */
/*   Updated: 2026/03/23 15:06:32 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    player_init(t_player *p)
{
    p->x              = WIN_W / 2;
    p->y              = WIN_H / 2;
    p->radius         = 10;
    p->turn_direction = 0;
    p->walk_direction = 0;
    p->rotation_angle = 3.0 * M_PI / 2.0;
    p->move_speed     = 2.0;
    p->rotation_speed = 2.0 * (M_PI / 180.0);
}

/* Equivalente ao Player::update() do JS */
void    player_update(t_player *p)
{
    double  move_step;
    double  nx;
    double  ny;

    p->rotation_angle += p->rotation_speed * p->turn_direction;
    move_step = p->move_speed * p->walk_direction;
    nx = p->x + cos(p->rotation_angle) * move_step;
    ny = p->y + sin(p->rotation_angle) * move_step;
    if (!map_has_wall(nx, ny))
    {
        p->x = nx;
        p->y = ny;
    }
}

/* Equivalente ao Player::render() do JS */
void    player_render(t_img *img, t_player *p)
{
    int red;

    red = color(255, 0, 0);
    draw_circle(img, (int)p->x, (int)p->y, p->radius, red);
    draw_line(img,
        (int)p->x,
        (int)p->y,
        (int)(p->x + cos(p->rotation_angle) * 20),
        (int)(p->y + sin(p->rotation_angle) * 20),
        red);
}
