/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:33:53 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 11:52:56 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_line(t_line *l)
{
	l->dx = abs(l->x1 - l->x0);
	l->dy = -abs(l->y1 - l->y0);
	if (l->x0 < l->x1)
		l->sx = 1;
	else
		l->sx = -1;
	if (l->y0 < l->y1)
		l->sy = 1;
	else
		l->sy = -1;
	l->err = l->dx + l->dy;
}

static void	update_line(t_line *l)
{
	int	e2;

	e2 = 2 * l->err;
	if (e2 >= l->dy)
	{
		l->err = l->err + l->dy;
		l->x0 = l->x0 + l->sx;
	}
	if (e2 <= l->dx)
	{
		l->err = l->err + l->dx;
		l->y0 = l->y0 + l->sy;
	}
}

void	draw_line(t_img *img, t_line *l, int color)
{
	init_line(l);
	while (1)
	{
		put_pixel(img, l->x0, l->y0, color);
		if (l->x0 == l->x1 && l->y0 == l->y1)
			break ;
		update_line(l);
	}
}
