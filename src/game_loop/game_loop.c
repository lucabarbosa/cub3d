/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:07:24 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/04 11:49:48 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** game_loop — chamado pela MLX a cada frame (substitui draw() do p5.js)
**
** Ordem: limpa frame → update lógica → renderiza mapa → renderiza player
** → joga o buffer na janela.
*/
#include "../../includes/cub3d.h"

int game_loop(void *param)
{
    t_engine *e;

    e = (t_engine *)param;
		
		cast_all_rays(e);
    scene_render(&e->frame, &e->map);
    player_update(&e->player, &e->map);
		render_walls(e);
    minimap_render(&e->frame, &e->player);
		rays_render(&e->frame, e);
    mlx_put_image_to_window(e->mlx, e->win, e->frame.img, 0, 0);

    return (0);
}
