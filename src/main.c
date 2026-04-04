/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/04/04 14:24:01 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(void)
{
    t_engine engine;

    ft_memset(&engine, 0, sizeof(t_engine));
    map_load_hardcoded(&engine.map);
    if (!engine_init(&engine, WIN_W, WIN_H, WIN_TITLE))
    {
        ft_putendl_fd("Error\nFailed to initialize MLX.", 2);
        map_free(&engine.map);
        return (1);
    }
		//TEST: hardcoded map floor color
    engine.map.ceiling_color = color(0, 255, 0);
    engine.map.floor_color   = color(255, 0, 0);
		// load_texture(&engine, &engine.tex_no, "./textures/north.xpm");
		// load_texture(&engine, &engine.tex_so, "./textures/south.xpm");
		// load_texture(&engine, &engine.tex_we, "./textures/west.xpm");
		// load_texture(&engine, &engine.tex_ea, "./textures/east.xpm");
		//REFACTOR:
    player_init(&engine.player, &engine.map);
    engine_register_hooks(&engine);
    mlx_loop_hook(engine.mlx, game_loop, &engine);
    mlx_loop(engine.mlx);
    map_free(&engine.map);
    return (0);
}
