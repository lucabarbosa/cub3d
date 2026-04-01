/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:36:49 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 11:43:15 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_circle_red(t_img *img, int cx, int cy, int r)
{
	int	red;
	int	x;
	int	y;

	red = color(255,0,0);
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y <= r * r)
				put_pixel(img, cx + x, cy + y, red);
			x++;
		}
		y++;
	}
}
