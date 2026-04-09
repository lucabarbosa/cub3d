/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:37:24 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 11:37:35 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
