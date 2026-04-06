/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/04/06 02:27:00 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_cub3d(t_file *file);

int	main(int argc, char **argv)
{
	t_file	file;
	t_gc	*collector;

	collector = NULL;
	if (argc != 2)
	{
		if (argc < 2)
			ft_putendl_fd("The program expect some map.cub.", 2);
		if (argc > 2)
			ft_putendl_fd("The program only accept one map per time.", 2);
		return (EXIT_SUCCESS);
	}
	init_cub3d(&file);
	parsing(argv[1], &file, &collector);
	gc_clear(&collector);
	return (EXIT_SUCCESS);
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

