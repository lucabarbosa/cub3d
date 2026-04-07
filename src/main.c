/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/04/07 17:04:02 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_file(int argc);
static void	init_cub3d(t_file *file);

int	main(int argc, char **argv)
{
	t_file	file;
	t_gc		*collector;
	t_engine		engine;

	if (check_file(argc))
		return (1);
	init_cub3d(&file);
	parsing(argv[1], &file, &collector);
	ft_memset(&engine, 0, sizeof(t_engine));
	map_load_hardcoded(&engine.map);
	if (!engine_init(&engine, WIN_W, WIN_H, WIN_TITLE))
	{
		ft_putendl_fd("Error\nFailed to initialize MLX.", 2);
		map_free(&engine.map);
		return (1);
	}
	load_all_textures(&engine);
	player_init(&engine.player, &engine.map);
	engine_register_hooks(&engine);
	mlx_loop_hook(engine.mlx, game_loop, &engine);
	mlx_loop(engine.mlx);
	map_free(&engine.map);
	gc_clear(&collector);
	return (EXIT_SUCCESS);
}

static int	check_file(int argc)
{
	if (argc < 2)
	{
		ft_putendl_fd("The program expect some map.cub.", 2);
		return (1);
	}
	if (argc > 2)
	{
		ft_putendl_fd("The program only accept one map per time.", 2);
		return (1);
	}
	return (0);
}

static void	init_cub3d(t_file *file)
{
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;
	file->sky_color = NULL;
	file->floor_color = NULL;
	file->player = NULL;
	file->player_row = 0;
	file->player_col = 0;
	file->map = NULL;
}

