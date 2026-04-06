/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:47 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/06 12:04:05 by fabialme         ###   ########.fr       */
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
	//REFACTOR: possivelmente terei que mudar isso 
	map_free(&engine->map);
	exit(0);
}
//TODO: aqui vai ser o register dos movimentos mais tarde
//
// int	key_handler(int keysym, void *param)
// {
//     t_engine *e = (t_engine *)param;
//
//     if (keysym == XK_Escape)
//         on_destroy(e);
//     if (keysym == XK_Left)  e->player.turn_direction = -1;
//     if (keysym == XK_Right) e->player.turn_direction =  1;
//     if (keysym == XK_Up)    e->player.walk_direction =  1;
//     if (keysym == XK_Down)  e->player.walk_direction = -1;
//     return (0);
// }

int key_handler(int keysym, void *param)
{
	t_engine *e = (t_engine *)param;

	if (keysym == XK_Escape)
		on_destroy(e);
	if (keysym == XK_Left)  e->player.turn_direction = -1;
	if (keysym == XK_Right) e->player.turn_direction =  1;
	if (keysym == XK_w) e->player.walk_direction =  1;
	if (keysym == XK_s) e->player.walk_direction = -1;
	if (keysym == XK_a) e->player.strafe_direction = -1;
	if (keysym == XK_d) e->player.strafe_direction =  1;
	return (0);
}

int key_release(int keysym, void *param)
{
    t_engine *e = (t_engine *)param;

    if (keysym == XK_Left || keysym == XK_Right)
        e->player.turn_direction = 0;

    if (keysym == XK_w || keysym == XK_s)
        e->player.walk_direction = 0;

    if (keysym == XK_a || keysym == XK_d)
        e->player.strafe_direction = 0;

    return (0);
}
// int	key_release(int keysym, void *param)
// {
//     t_engine *e = (t_engine *)param;
//
//     if (keysym == XK_Left  || keysym == XK_Right) e->player.turn_direction = 0;
//     if (keysym == XK_Up    || keysym == XK_Down)  e->player.walk_direction = 0;
//     return (0);
// }
/*
** engine_register_hooks — registra os callbacks de evento na MLX
**
** mlx_hook(win, event_type, event_mask, handler, param):
**   evento 17 (DestroyNotify) | mask 0 → on_destroy (clique no X)
*/
void	engine_register_hooks(t_engine *engine)
{
	mlx_hook(engine->win, DestroyNotify, StructureNotifyMask, on_destroy, engine);
	// mlx_hook(engine->win, 17, 0, on_destroy, engine);
	mlx_hook(engine->win, KeyPress, KeyPressMask, key_handler, engine);
	mlx_hook(engine->win, KeyRelease, KeyReleaseMask, key_release, engine);
}
