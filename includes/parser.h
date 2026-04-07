/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:21 by lbento            #+#    #+#             */
/*   Updated: 2026/04/06 01:24:30 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cub3d.h"

typedef struct s_file		t_file;

void	parsing(char *map, t_file *file, t_gc **collector);
void	parse_file(int fd, t_file *file, t_gc **collector);
void	check_map(char *line, t_file *file, t_gc **collector);

void	validate_map(t_file *file, t_gc **collector);

void	check_color(char *line, t_file *file, t_gc **collector);
void		check_map(char *line, t_file *file, t_gc **collector);
void		check_texture(char *line, t_file *file, t_gc **collector);

int	dotcub(char *map, t_gc **collector);
int	dotxpm(char *line, t_gc **collector);
int	isnt_digit(char *str);
int	skip_space_tab(char *path, int i);

#endif