/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 00:00:00 by lbento            #+#    #+#             */
/*   Updated: 2026/03/16 00:00:00 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*
** on_destroy — chamado quando o usuário clica no X da janela
**
** Evento 17 = DestroyNotify (X11).
** Chama engine_shutdown para liberar os recursos e sai do programa.
*/
int	on_destroy(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	engine_shutdown(engine);
	exit(0);
}

/*
** engine_register_hooks — registra os callbacks de evento na MLX
**
** mlx_hook(win, event_type, event_mask, handler, param):
**   evento 17 (DestroyNotify) | mask 0 → on_destroy (clique no X)
*/
void	engine_register_hooks(t_engine *engine)
{
	mlx_hook(engine->win, 17, 0, on_destroy, engine);
}