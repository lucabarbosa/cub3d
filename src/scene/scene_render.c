/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 09:26:38 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 09:26:40 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    scene_render(t_img *img, t_scene *s)
{
    // metade superior = céu
    draw_rect(img, 0, 0, WIN_W, WIN_H / 2, s->ceiling_color);
    // metade inferior = chão
    draw_rect(img, 0, WIN_H / 2, WIN_W, WIN_H / 2, s->floor_color);
}
