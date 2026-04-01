/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:58:54 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/01 12:10:52 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//REFACTOR: remove this file
#include "../../includes/cub3d.h"
/* Escreve um pixel diretamente no buffer da imagem */
void    put_pixel(t_img *img, int x, int y, int color)
{
    char    *dst;

    if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
        return ;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}
//
// /* Preenche um retângulo de cor sólida */
// void    draw_rect(t_img *img, int x, int y, int w, int h, int color)
// {
//     int i, j;
//     i = 0;
//     while (i < h)
//     {
//         j = 0;
//         while (j < w)
//         {
//             put_pixel(img, x + j, y + i, color);
//             j++;
//         }
//         i++;
//     }
// }
//
// /* Desenha um círculo (algoritmo do ponto médio) */
// void    draw_circle(t_img *img, int cx, int cy, int r, int color)
// {
//     int x, y;
//
//     y = -r;
//     while (y <= r)
//     {
//         x = -r;
//         while (x <= r)
//         {
//             if (x * x + y * y <= r * r)
//                 put_pixel(img, cx + x, cy + y, color);
//             x++;
//         }
//         y++;
//     }
// }
//
// /* Linha de Bresenham — substitui stroke/line do p5.js */
// void    draw_line(t_img *img, int x0, int y0, int x1, int y1, int color)
// {
//     int dx  =  abs(x1 - x0);
//     int dy  = -abs(y1 - y0);
//     int sx  = x0 < x1 ? 1 : -1;
//     int sy  = y0 < y1 ? 1 : -1;
//     int err = dx + dy;
//     int e2;
//
//     while (1)
//     {
//         put_pixel(img, x0, y0, color);
//         if (x0 == x1 && y0 == y1)
//             break ;
//         e2 = 2 * err;
//         if (e2 >= dy) { err += dy; x0 += sx; }
//         if (e2 <= dx) { err += dx; y0 += sy; }
//     }
// }
//
// /* ─── Cor ────────────────────────────────────────────────── */
