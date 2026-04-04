/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabialme <fabialme@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 14:32:04 by fabialme          #+#    #+#             */
/*   Updated: 2026/04/04 14:44:23 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
int load_texture(t_engine *e, t_img *tex, char *path)
{
    if (!e || !tex || !path)
        return (0);
		int fd = open(path, O_RDONLY);
		if (fd < 0)
		{
				perror("open");
				printf("failed path: %s\n", path);
		}
		else
			close(fd);
    tex->img = mlx_xpm_file_to_image(e->mlx, path, &tex->w, &tex->h);
    if (!tex->img)
    {
        ft_putendl_fd("Error\nFailed to load texture.", 2);
        return (0);
    }

    tex->addr = mlx_get_data_addr(tex->img,
            &tex->bits_per_pixel,
            &tex->line_length,
            &tex->endian);
    if (!tex->addr)
    {
        ft_putendl_fd("Error\nFailed to get texture addr.", 2);
        mlx_destroy_image(e->mlx, tex->img);
        return (0);
    }

    return (1);
}
// int     load_texture(t_engine *e, t_img *tex, char *path)
// {
//     tex->img = mlx_xpm_file_to_image(e->mlx, path, &tex->w, &tex->h);
// 		printf("\n img str = %s\n", e->map.tex_no);
//     if (!tex->img)
//     {
//         ft_putendl_fd("Error\nFailed to load texture.", 2);
//         return (0);
//     }
//     tex->addr = mlx_get_data_addr(tex->img,
//             &tex->bits_per_pixel,
//             &tex->line_length,
//             &tex->endian);
//     if (!tex->addr)
//     {
//         ft_putendl_fd("Error\nFailed to get texture addr.", 2);
//         return (0);
//     }
//     return (1);
// }
// void    load_texture(t_engine *e, t_img *tex, char *path)
// {
//     tex->img = mlx_xpm_file_to_image(e->mlx, path, &tex->w, &tex->h);
//     tex->addr = mlx_get_data_addr(tex->img,
//             &tex->bits_per_pixel,
//             &tex->line_length,
//             &tex->endian);
// }

int     get_tex_color(t_img *tex, int x, int y)
{
    char    *pixel;

    pixel = tex->addr
        + y * tex->line_length
        + x * (tex->bits_per_pixel / 8);
    return (*(int *)pixel);
}

t_img   *get_texture(t_engine *e, t_ray *ray)
{
    if (ray->was_hit_vertical && ray->is_facing_left)
        return (&e->tex_we);
    if (ray->was_hit_vertical && !ray->is_facing_left)
        return (&e->tex_ea);
    if (!ray->was_hit_vertical && ray->is_facing_up)
        return (&e->tex_no);
    return (&e->tex_so);
}
