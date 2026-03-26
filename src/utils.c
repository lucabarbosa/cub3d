/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:58:58 by lbento            #+#    #+#             */
/*   Updated: 2026/03/24 22:59:36 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_error(int num, t_gc **collector);

void	print_error(int num, t_gc **collector)
{
	if (num == 1)
		ft_putstr_fd("Invalid map. The map must be <.cub>.\n", 2);
	if (num == 2)
		ft_putstr_fd("The file is empty.\n", 2);
	if (num == 3)
		ft_putstr_fd("Wrong texture, it must be <.xpm>.\n", 2);
	if (num == 4)
		ft_putstr_fd("The map must have one texture for NO, SO, WE and EA.\n", 2);
	if (num == 10)
		perror("Error: ");
	gc_clear(collector);
	exit (1);
}
