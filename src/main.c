/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:26 by lbento            #+#    #+#             */
/*   Updated: 2026/03/13 13:12:50 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_gc	*collector;

	collector = NULL;
	if (argc != 2)
	{
		if (argc < 2)
			ft_putendl_fd("The program expect some map.cub.", 2);
		if (argc > 2)
			ft_putendl_fd("The program only accept one map per time.", 2);
		return (1);
	}
	parsing(argv[1], &collector);
	return (0);
}
