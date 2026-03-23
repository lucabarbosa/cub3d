/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:07:24 by fabialme          #+#    #+#             */
/*   Updated: 2026/03/23 15:07:29 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** game_loop — chamado pela MLX a cada frame (substitui draw() do p5.js)
**
** Ordem: limpa frame → update lógica → renderiza mapa → renderiza player
** → joga o buffer na janela.
*/
int	game_loop(void *param)
{
    t_engine	*e;

    e = (t_engine *)param;
    // 1. limpa o frame (fundo preto)
    draw_rect(&e->frame, 0, 0, WIN_W, WIN_H, 0x000000);
    // 2. update da lógica
    player_update(&e->player);
    // 3. render
    map_render(&e->frame);
    player_render(&e->frame, &e->player);
    // 4. joga o buffer na janela
    mlx_put_image_to_window(e->mlx, e->win, e->frame.img, 0, 0);
    return (0);
}
