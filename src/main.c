/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/04/01 10:03:51 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int main(void)
// {
//     t_engine engine;
//
//     if (!engine_init(&engine, WIN_W, WIN_H, WIN_TITLE))
//     {
//         ft_putendl_fd("Error\nFailed to initialize MLX.", 2);
//         return (1);
//     }
//     map_load_hardcoded(&engine.map);
//     engine.scene.ceiling_color = color(50, 50, 80);
//     engine.scene.floor_color   = color(80, 60, 40);
//     player_init(&engine.player, &engine.map);
//     engine_register_hooks(&engine);
//     mlx_loop_hook(engine.mlx, game_loop, &engine);
//     mlx_loop(engine.mlx);
//     map_free(&engine.map);
//     return (0);
// }
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
    engine.map.ceiling_color = color(0, 255, 0);
    engine.map.floor_color   = color(255, 0, 0);
    player_init(&engine.player, &engine.map);
    engine_register_hooks(&engine);
    mlx_loop_hook(engine.mlx, game_loop, &engine);
    mlx_loop(engine.mlx);
    map_free(&engine.map);
    return (0);
}
