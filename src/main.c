/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/03/24 17:05:14 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_cub3d(t_file *file, t_gc **collector);

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
	init_cub3d(&file, &collector);
	parsing(argv[1], &file, &collector);
	gc_clear(&collector);
	return (EXIT_SUCCESS);
}

static void	init_cub3d(t_file *file, t_gc **collector)
{
	file = gc_malloc(collector, sizeof(t_file));
	file->no = NULL;
	file->so = NULL;
	file->we = NULL;
	file->ea = NULL;
	file->map = NULL;
}

