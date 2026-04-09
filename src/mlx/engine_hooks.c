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

int	on_destroy(void *param)
{
	t_engine	*engine;

	engine = (t_engine *)param;
	engine_shutdown(engine);
	map_free(&engine->map);
	//TODO: colocar o free das texturas? 
	exit(0);
}

int	key_handler(int keysym, void *param)
{
	t_engine	*e;

	e = (t_engine *)param;
	if (keysym == XK_Escape)
		on_destroy(e);
	if (keysym == XK_Left)
		e->player.turn_direction = -1;
	if (keysym == XK_Right)
		e->player.turn_direction = 1;
	if (keysym == XK_w)
		e->player.walk_direction = 1;
	if (keysym == XK_s)
		e->player.walk_direction = -1;
	if (keysym == XK_a)
		e->player.strafe_direction = -1;
	if (keysym == XK_d)
		e->player.strafe_direction = 1;
	return (0);
}

int	key_release(int keysym, void *param)
{
	t_engine	*e;

	e = (t_engine *)param;
	if (keysym == XK_Left || keysym == XK_Right)
		e->player.turn_direction = 0;
	if (keysym == XK_w || keysym == XK_s)
		e->player.walk_direction = 0;
	if (keysym == XK_a || keysym == XK_d)
		e->player.strafe_direction = 0;
	return (0);
}

void	engine_register_hooks(t_engine *engine)
{
	mlx_hook(engine->win, DestroyNotify, StructureNotifyMask,
		on_destroy, engine);
	mlx_hook(engine->win, KeyPress, KeyPressMask,
		key_handler, engine);
	mlx_hook(engine->win, KeyRelease, KeyReleaseMask,
		key_release, engine);
}
