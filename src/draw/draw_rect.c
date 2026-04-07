/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:35:57 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 11:36:07 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//REFACTOR: usar a struct aqui
void	draw_rect(t_img *img, int x, int y, int w, int h, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			put_pixel(img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

// void	draw_rect(t_img *img, t_rect rect)
// {
// 	int	i;
// 	int	j;
//
// 	i = 0;
// 	while (i < rect.h)
// 	{
// 		j = 0;
// 		while (j < rect.w)
// 		{
// 			put_pixel(img, rect.x + j, rect.y + i, rect.color);
// 			j++;
// 		}
// 		i++;
// 	}
// }
