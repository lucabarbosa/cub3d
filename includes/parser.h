/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:21 by lbento            #+#    #+#             */
/*   Updated: 2026/03/24 23:08:11 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

typedef struct s_file		t_file;

void	parsing(char *map, t_file *file, t_gc **collector);
void	parse_file(char *map, t_file *file, t_gc **collector);
void		check_texture(char *line, t_file *file, t_gc **collector);
void	check_color(char *line, t_file *file, t_gc **collector);

#endif