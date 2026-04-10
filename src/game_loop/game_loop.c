/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 15:07:24 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/10 14:22:07 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	game_loop(void *param)
{
	t_engine	*e;

	e = (t_engine *)param;
	cast_all_rays(e);
	scene_render(&e->frame, &e->map);
	player_update(&e->player, &e->map);
	render_walls(e);
	minimap_render(&e->frame, &e->player, &e->map);
	rays_render(&e->frame, e);
	mlx_put_image_to_window(e->mlx, e->win, e->frame.img, 0, 0);
	return (0);
}
