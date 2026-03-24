/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:58:58 by lbento            #+#    #+#             */
/*   Updated: 2026/03/21 22:47:12 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_error(int num, t_gc **collector);

void	print_error(int num, t_gc **collector)
{
	if (num == 1)
		ft_putstr_fd("Invalid map. The map must be <.cub>.\n", 2);
	if (num == 2)
		ft_putstr_fd("The file can't be opened.\n", 2);
	if (num == 3)
		ft_putstr_fd("The file is empty.\n", 2);
	if (num == 4)
		ft_putstr_fd("Wrong map, missing textures.\n", 2);
	gc_clear(collector);
	exit (1);
}
