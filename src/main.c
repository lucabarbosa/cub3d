/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/03/23 15:08:47 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(void)
{
    t_engine	engine;

    if (!engine_init(&engine, WIN_W, WIN_H, WIN_TITLE))
    {
        ft_putendl_fd("Error\nFailed to initialize MLX.", 2);
        return (1);
    }
    player_init(&engine.player);          // <-- inicializa o player
    engine_register_hooks(&engine);
    mlx_loop_hook(engine.mlx, game_loop, &engine);  // <-- loop do jogo
    mlx_loop(engine.mlx);
    return (0);
}
