/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:02:04 by lbento            #+#    #+#             */
/*   Updated: 2026/04/06 00:09:33 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void	validate_map(t_file *file, t_gc **collector)
{
   if (!file->no || !file->so || !file->we || !file->ea)
		print_error(4, collector);
	if (!file->sky_color || !file->floor_color)
		print_error(6, collector);
	// if (!check_chars(file, collector))   // só '0','1','N','S','E','W',' ','\n'
	// 	print_error(7, collector);
	// if (!check_player(file, collector))  // exatamente 1 jogador
	// 	print_error(8, collector);
	// if (!secure_map(file, collector))    // mapa fechado
	// 	print_error(9, collector);
}
