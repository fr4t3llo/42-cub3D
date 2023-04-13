/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skasmi <skasmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:41:59 by aelyakou          #+#    #+#             */
/*   Updated: 2023/02/10 06:01:07 by skasmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# include "../Parssing/cub3d.h"
# include "mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define STDERR 2
# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define UNIT 64
# define P_W 320
# define P_H 200
# define PI 3.14159265358979323846
# define MVS 10
# define TRS 2
# define SSCL 4
# define MSCL 8

typedef struct s_mlx
{
	void		*mp;
	void		*w3;
	int			w_h;
	int			w_w;
}				t_mlx;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			len;
	int			endn;
	t_mlx		t;
}				t_img;

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_ply
{
	t_pos		*p_pos;
	double		fov;
	double		p_alt;
	double		pa;
	int			mv_dir;
	int			mh_dir;
	int			r_dir;
	int			d_dir;

}				t_ply;

typedef struct s_ray
{
	double		ra;
	double		dist;
	t_pos		wall_pos;
	int			is_v;
	char		orient;
}				t_ray;

typedef struct s_data
{
	t_ply		*ply;
	t_mlx		*mlx;
	double		abr;
	double		dsp;
	t_ray		*rays;
	t_img		*wrld;
	t_map		*lvl;
	void		*no;
	void		*so;
	void		*ea;
	void		*we;

}				t_data;

//--------------level parsing functions----------------
void			ft_init_data(t_data **data, t_map *map);
t_data			*get_data(t_map *map);

//-----------free fucntions
void			free_tab(char **tab);

//--------------level drawing functions----------------
int				get_texel(t_data *data, int x, int y, int slice);
//--------------math funcs-------------------

double			limit_angles(double ra);
double			rad_to_deg(double x);
double			deg_to_rad(double x);
double			normalize_ray(double rl, double ra, t_data *data);

//--------------raycasting funcs------------------------

double			cast_ray(t_data *data, int i, double ra);
int				check_bounds(t_data *data, t_pos *wpos, double xa, double ya);
t_pos			check_wall_v(double *res, double ra, t_data *data);
double			get_vwx(t_data *data, int dir);
int				get_dir_v(double ra);
int				get_dir_h(double ra);

//-------------mlx_mods---------------------------------

void			pixel_put_img(t_img *img, int x, int y, unsigned int color);
int				create_rgb(int r, int g, int b);
void			mlx_get_color_at(void *img, int x, int y, unsigned int *color);

//-------------norm function-------------------
void			is_collided(double x, double y, t_data *data);
void			render_floor(t_data *data, t_img *img);
void			render_sky(t_data *data, t_img *img);
void			loop_rays(t_data *data);
int				ft_quit(t_data *data);
void			diag_move(t_data *data);
void			p_move(t_data *data);
void			p_rotate(t_data *data);
void			render_wall2d(int x, int y, t_data *data);
void			render_level2d(t_data *data);
void			render_slice(t_data *data, int slice, int x);
void			render_walls3d(t_data *data);
int				keyup(int keycode, t_data *data);
int				keydown(int keycode, t_data *data);
void			get_m_dir(int keycode, t_data *data);
void			get_r_dir(int keycode, t_data *data);
int				keydown(int keycode, t_data *data);
#endif