/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:02:04 by lbento            #+#    #+#             */
/*   Updated: 2026/04/06 02:41:03 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

static int	check_chars(t_file *file);
static int	check_player(t_file *file, t_gc **collector);

void	validate_map(t_file *file, t_gc **collector)
{
   if (!file->no || !file->so || !file->we || !file->ea)
		print_error(4, collector);
	if (!file->sky_color || !file->floor_color)
		print_error(6, collector);
	if (!check_chars(file))
		print_error(7, collector);
	if (!check_player(file, collector))
		print_error(8, collector);
	// if (!secure_map(file, collector))
	// 	print_error(9, collector);
}

static int	check_chars(t_file *file)
{
	int	i;
	int	j;

	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] != '0' && file->map[i][j] != '1'
				&& file->map[i][j] != 'N' && file->map[i][j] != 'S'
				&& file->map[i][j] != 'E' && file->map[i][j] != 'W'
				&& file->map[i][j] != ' ' && file->map[i][j] != '\t'
				&& file->map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_player(t_file *file, t_gc **collector)
{
	int	i;
	int	j;

	i = 0;
	while (file->map[i])
	{
		j = 0;
		while (file->map[i][j])
		{
			if (file->map[i][j] == 'N' || file->map[i][j] == 'S'
				|| file->map[i][j] == 'E' || file->map[i][j] == 'W')
			{
				if (file->player)
					return (0);
				file->player = ft_substr(file->map[i], j, 1, collector);
				file->player_row = i;
				file->player_col = j;
			}
			j++;
		}
		i++;
	}
	if (!file->player)
		return (0);
	return (1);
}
