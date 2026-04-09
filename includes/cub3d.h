/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbento <lbento@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 19:36:21 by lbento            #+#    #+#             */
/*   Updated: 2026/04/09 13:46:12 by lbento           ###   ########.fr       */
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
# include <float.h>
# include "parser.h"

# define WIN_W		1024
# define WIN_H		720

#define TILE_SIZE     64
#define MAP_NUM_ROWS  11
#define MAP_NUM_COLS  15
#define FOV_ANGLE 66
#define WALL_STRIP_WIDTH 1
#define NUM_RAYS (WIN_W / WALL_STRIP_WIDTH)
#define MINIMAP_SCALE  0.2f

typedef struct s_map
{
	int	**grid;
	int	rows;
	int	cols;
	int	tile_size;
	int	floor_color;
	int	ceiling_color;
	int	player_x;
	int	player_y;
	char	player_dir;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
}	t_map;

typedef struct s_step
{
    double  x;
    double  y;
}   t_step;

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

typedef struct s_rect
{
  int	x;
  int	y;
  int	w;
  int	h;
  int	color;
}	t_rect;

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
	double strafe_direction;
}   t_player;

typedef struct s_ray
{
	double  ray_angle;

	int     is_facing_right;
	int     is_facing_left;
	int     is_facing_up;
	int     is_facing_down;

	double  wall_hit_x;
	double  wall_hit_y;
	double  distance;
	double  wall_x;
	int     was_hit_vertical;
}   t_ray;

typedef struct s_wall_strip
{
	int     col;
	int     draw_start;
	int     draw_end;
	int     wall_height;
	t_ray   *ray;
}   t_wall_strip;

typedef struct s_engine
{
	t_gc	**collector;
	void	*mlx;
	void	*win;
	t_img	frame;
	int		win_w;
	int		win_h;
	bool	running;
	t_scene	scene;
	t_map	map;
	t_ray	rays[NUM_RAYS];
	t_img	tex_no;
	t_img	tex_so;
	t_img	tex_we;
	t_img	tex_ea;
	t_player	player;
}	t_engine;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_file
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	*sky_color;
	t_rgb	*floor_color;
	char	*player;
	int		player_row;
	int		player_col;
	int		total_lines;
	int		total_cols;
	char	**map;
}	t_file;

void	print_error(int num, t_gc **collector);

typedef struct s_horz
{
	double	hit_x;
	double	hit_y;
	int		found;
}	t_horz;

typedef struct s_vert
{
	double	hit_x;
	double	hit_y;
	int		found;
}	t_vert;

double	normalize_angle(double angle);
double	dist_points(double x1, double y1, double x2, double y2);
void	get_horz_step(t_ray *ray, t_step *step);
void	cast_horizontal(t_ray *ray, t_player *p, t_map *map, t_horz *h);
void	set_horz_result(t_player *p, t_horz *h, double *hd);
void	get_vert_step(t_ray *ray, t_step *step);
void	cast_vertical(t_ray *ray, t_player *p, t_map *map, t_vert *v);
void	set_vert_result(t_player *p, t_vert *v, double *vd);
void	init_ray(t_ray *ray, double ray_angle);
void	cast_ray(t_ray *ray, t_player *p, t_map *map);
void	cast_all_rays(t_engine *e);
void	rays_render(t_img *img, t_engine *e);

int		engine_init(t_engine *e, int w, int h, t_gc **collector);

void	engine_shutdown(t_engine *e);

void	engine_register_hooks(t_engine *engine);
int		on_destroy(void *param);

void	player_init(t_player *p, t_map *map);
void	player_render(t_img *img, t_player *p);
void	player_update(t_player *p, t_map *map);

int		map_has_wall(t_map *map, double x, double y);
void	map_render(t_img *img, t_map *map);
void	map_load(t_map *map, t_file file, t_gc **collector);
void	map_free(t_map *map);

int	game_loop(void *param);

void	put_pixel(t_img *img, int x, int y, int color);

void	draw_rect(t_img *img, t_rect rect);
void	draw_circle_red(t_img *img, int cx, int cy, int r);
void	draw_line(t_img *img, t_line *l, int color);
int	color(int r, int g, int b);
void    minimap_render(t_img *img, t_player *p, t_map *map);

void    scene_render(t_img *img, t_map *map);
int color(int r, int g, int b);
void    render_walls(t_engine *e);

int     get_tex_color(t_img *tex, int x, int y);
int     load_texture(t_engine *e, t_img *tex, char *path);
t_img   *get_texture(t_engine *e, t_ray *ray);

void load_all_textures(t_engine *engine);
void	free_all_textures(t_engine *e);
int     has_wall_near(t_map *map, double x, double y);

#endif
