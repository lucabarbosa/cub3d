/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_shutdown.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:00:00 by lbento            #+#    #+#             */
/*   Updated: 2026/03/16 00:00:00 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** engine_shutdown — libera todos os recursos alocados pela MLX
**
** A ordem de destruição é o inverso da criação em engine_init():
**   1. frame buffer (imagem off-screen)
**   2. janela visível
**   3. conexão com o servidor X (display + free do ponteiro mlx)
**
** Cada recurso é checado antes de destruir e zerado depois,
** tornando a função segura para chamar mais de uma vez.
**
** Nota: mlx_init() aloca o ponteiro mlx internamente com malloc,
** por isso precisamos dar free() nele após mlx_destroy_display().
*/
void	engine_shutdown(t_engine *e)
{
	if (!e)
		return ;
	if (e->mlx && e->frame.img)
	{
		mlx_destroy_image(e->mlx, e->frame.img);
		e->frame.img = NULL;
	}
	if (e->mlx && e->win)
	{
		mlx_destroy_window(e->mlx, e->win);
		e->win = NULL;
	}
	if (e->mlx)
	{
		mlx_destroy_display(e->mlx);
		free(e->mlx);
		e->mlx = NULL;
	}
}