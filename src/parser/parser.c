/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:12:00 by lbento            #+#    #+#             */
/*   Updated: 2026/03/16 20:09:55 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void  parsing(char *map, t_file *file, t_gc **collector);
int	dotcub(char *map);
void	parse_file(char *map, t_file *file, t_gc **collector);

void  parsing(char *map, t_file *file, t_gc **collector)
{
	if (dotcub(map))
		print_error (1, collector);
	parse_file(map, file, collector);
}

int	dotcub(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len == 0)
		return (1);
	if (len < 5)
		return (1);
	if (ft_strcmp((map + len - 4), ".cub") != 0)
		return (1);
	return (0);
}

void	parse_file(char *map, t_file *file, t_gc **collector)
{
	int	fd;
	int	run;
	char	*cont;

	fd = open(map, __O_DIRECTORY);
	if (fd != -1)
		print_error(2, NULL);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		print_error(2, NULL);
	run = 1;
	while (run)
	{
		cont = get_next_line(fd, collector);
		if (!cont)
			run = 0;
	}
	close (fd);
}
