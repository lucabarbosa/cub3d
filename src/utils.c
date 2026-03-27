/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:58:58 by lbento            #+#    #+#             */
/*   Updated: 2026/03/27 12:01:07 by lbento           ###   ########.fr       */
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
		ft_putstr_fd("The map need have textures for NO, SO, WE, and EA.\n", 2);
	if (num == 5)
		ft_putendl_fd("Wrong RGB: put range between 0-255, divided by <,>.", 2);
	if (num == 6)
		ft_putstr_fd("The map need have color for sky and floor.\n", 2);
	if (num == 7)
		ft_putstr_fd("Map isn't solvable.\n", 2);
	if (num == 10)
		perror("Error: ");
	gc_clear(collector);
	exit (1);
}
