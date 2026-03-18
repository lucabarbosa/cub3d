/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 21:47:41 by lbento            #+#    #+#             */
/*   Updated: 2026/03/17 23:03:19 by lbento           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"
#include "../../includes/cub3d.h"

void	add_content (char *line, t_file **file, t_gc **collector)
{
	t_file	*current;
	t_file	*new_node;

	if (!line)
		return ;
	current = *file;
	if (current ->content_line == NULL)
	{
		current->content_line = ft_strdup(line, collector);
		return ;
	}
	new_node = gc_malloc(collector, sizeof(t_file));
	while (current->next != NULL)
		current = current->next;
	new_node->content_line = ft_strdup(line, collector);
	new_node->next = NULL;
	current->next = new_node;
	return ;
}
