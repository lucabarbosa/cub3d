/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:21 by lbento            #+#    #+#             */
/*   Updated: 2026/04/01 12:08:45 by fabialme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdint.h>

# define WIN_W		1024
# define WIN_H		720
# define WIN_TITLE	"cub3D"

#define TILE_SIZE     64
#define MAP_NUM_ROWS  11
#define MAP_NUM_COLS  15
#define FOV_ANGLE 66
#define WALL_STRIP_WIDTH 1
#define NUM_RAYS (WIN_W / WALL_STRIP_WIDTH)
#define MINIMAP_SCALE  0.2f
// no header

//TEST:
extern int g_grid[MAP_NUM_ROWS][MAP_NUM_COLS];

typedef struct s_map
{
    int **grid;        // alocado dinamicamente
    int rows;
    int cols;
    int tile_size;
    int floor_color;
    int ceiling_color;
}   t_map;

typedef struct s_line
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_line;

typedef struct s_scene
{
    int ceiling_color;
    int floor_color;
}   t_scene;
/*
** t_img — representa uma imagem MLX (frame buffer ou textura)
**
** img          : handle opaco retornado por mlx_new_image()
** addr         : ponteiro para os bytes brutos dos pixels
** bits_per_pixel: profundidade de cor (normalmente 32)
** line_length  : bytes por linha (pode ser maior que w * bpp/8)
** endian       : ordem dos bytes de cor (0 = little-endian)
** w / h        : largura e altura em pixels
*/
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}	t_img;

/*
** t_engine — camada MLX: conexão, janela e frame buffer
**
** mlx     : ponteiro de conexão com o servidor X (retorno de mlx_init)
** win     : ponteiro da janela visível (retorno de mlx_new_window)
** frame   : imagem off-screen onde desenhamos antes de jogar na janela
** win_w/h : dimensões da janela em pixels
** running : quando false, o loop encerra e libera os recursos
*/

typedef struct s_player
{
    double  x;
    double  y;
    int     radius;
    int     turn_direction;
    int     walk_direction;
    double  rotation_angle;
    double  move_speed;
    double  rotation_speed;
}   t_player;

typedef struct s_engine
{
	void	*mlx;
	void	*win;
	t_img	frame;
	int		win_w;
	int		win_h;
	bool	running;
  t_player	player;
  t_scene	scene;
  t_map map;
}	t_engine;

typedef struct s_ray
{
    double ray_angle;

    double xintercept;
    double yintercept;

    double xstep;
    double ystep;

    int    is_facing_right;
    int    is_facing_left;
    int    is_facing_up;
    int    is_facing_down;

    int    found_horz_wall_hit;
    double horz_wall_hit_x;
    double horz_wall_hit_y;

} t_ray;

/* mlx/engine_init.c */
int		engine_init(t_engine *e, int w, int h, const char *title);

/* mlx/engine_shutdown.c */
void	engine_shutdown(t_engine *e);

/* mlx/engine_hooks.c */
void	engine_register_hooks(t_engine *engine);
int		on_destroy(void *param);


/* player/player.c */
void    player_init(t_player *p, t_map *map);
void    player_render(t_img *img, t_player *p);
void    player_update(t_player *p, t_map *map);

/* map/map.c */
int     map_has_wall(t_map *map, double x, double y);
void    map_render(t_img *img);
void    map_load_hardcoded(t_map *map);
void    map_free(t_map *map);

/* game_loop.c */
int     game_loop(void *param);

/* mlx/draw.c */
void    put_pixel(t_img *img, int x, int y, int color);
// void    draw_rect(t_img *img, int x, int y, int w, int h, int color);

void	draw_rect(t_img *img, int x, int y, int w, int h, int color);
void	draw_circle_red(t_img *img, int cx, int cy, int r);
// void    draw_circle(t_img *img, int cx, int cy, int r, int color);
void	draw_line(t_img *img, t_line *l, int color);
int     color(int r, int g, int b);
// map/map.c
void    minimap_render(t_img *img, t_player *p);
// void    scene_render(t_img *img, t_scene *scene);

void    scene_render(t_img *img, t_map *map);
// utils
int color(int r, int g, int b);
#endif
