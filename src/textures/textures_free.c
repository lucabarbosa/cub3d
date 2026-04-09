/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 06:22:45 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/09 06:24:07 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_texture(t_engine *e, t_img *tex)
{
	if (tex->img)
	{
		mlx_destroy_image(e->mlx, tex->img);
		tex->img = NULL;
		tex->addr = NULL;
	}
}

void	free_all_textures(t_engine *e)
{
	free_texture(e, &e->tex_no);
	free_texture(e, &e->tex_so);
	free_texture(e, &e->tex_we);
	free_texture(e, &e->tex_ea);
}
