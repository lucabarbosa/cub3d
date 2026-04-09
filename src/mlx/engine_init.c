/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:28:52 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/09 13:57:09 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** engine_init — inicializa toda a camada MLX
**
** Ordem obrigatória:
**   1. mlx_init()          → abre a conexão com o servidor X11
**   2. mlx_new_window()    → cria a janela visível na tela
**   3. mlx_new_image()     → cria o frame buffer (imagem off-screen)
**   4. mlx_get_data_addr() → expõe os bytes brutos do frame buffer
**
** O frame buffer é uma imagem do mesmo tamanho da janela que fica
** escondida. Desenhamos tudo nela e só ao final do tick jogamos
** ela inteira na janela com mlx_put_image_to_window().
** Isso evita flickering (tela piscando durante o desenho).
**
** Retorna 1 em sucesso, 0 em qualquer falha.
*/
int	engine_init(t_engine *e, int w, int h, t_gc **collect)
{
	e->mlx = mlx_init();
	if (!e->mlx)
		return (0);
	e->win = mlx_new_window(e->mlx, w, h, "cub3d");
	if (!e->win)
		return (0);
	e->frame.img = mlx_new_image(e->mlx, w, h);
	if (!e->frame.img)
		return (0);
	e->frame.addr = mlx_get_data_addr(
			e->frame.img,
			&e->frame.bits_per_pixel,
			&e->frame.line_length,
			&e->frame.endian);
	if (!e->frame.addr)
		return (0);
	e->win_w = w;
	e->win_h = h;
	e->frame.w = w;
	e->frame.h = h;
	e->running = true;
	e->collector = collect;
	return (1);
}
