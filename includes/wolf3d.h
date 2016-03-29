/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:20:14 by dboudy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/29 14:52:38 by dboudy           ###   ########.fr       */
=======
/*   Updated: 2016/03/26 19:33:51 by dboudy           ###   ########.fr       */
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "./color_and_key.h"
# include <mlx.h>
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>

# define WIN	awin->win
# define MLX	awin->mlx
# define WINW	awin->w_width
# define WINH	awin->w_height
# define IMG	aimg->id
# define IMGW	aimg->i_width
# define IMGH	aimg->i_height
# define DATA	aimg->data
# define BPP	aimg->bpp
# define SIZE_L	aimg->size_line
# define LAST_P	aimg->last_pixel
# define COLOR	aimg->color
# define AWIN	all->awin
# define AI		all->aimg
# define AM		all->amap
# define AP		all->aplay
# define AB		all->abox
# define AC		all->acam
# define AR		all->aray
# define AT		all->atext
# define AH		all->ahook

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	int			padding;
	int			w_width;
	int			w_height;
	int			in_menu;
}				t_win;

typedef struct	s_image
{
	void		*id;
	char		*data;
	int			i_width;
	int			i_height;
	int			bpp;
	int			size_line;
	int			endian;
	int			last_pixel;
	int			padding;
	int			color;
}				t_image;

typedef struct	s_map
{
	char		***map;
	char		*name;
	int			goal;
	int			lave;
	int			nb_x;
	int			nb_y;
	int			mapy;
	int			mapx;
}				t_map;

typedef struct	s_skybox
{
	char		**box;
	int			nb_x_box;
	int			nb_y_box;
	int			boxy;
	int			boxx;
}				t_box;

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		speed;
	double		coef_rot;
	double		coef_motion;
}				t_play;

typedef struct	s_camera
{
	double		planex;
	double		planey;
	double		camx;
	double		camy;
}				t_cam;

typedef struct	s_ray
{
	double		rdx;
	double		rdy;
	double		side_dx;
	double		side_dy;
	double		delta_dx;
	double		delta_dy;
	double		h_wall;
	double		jump;
	int			stepx;
	int			stepy;
}				t_ray;

typedef struct	s_texture
{
	void		*peg[16];
	int			padtext;
	int			anim;
}				t_text;

typedef struct	s_hook
{
	int			event;
	int			button1;
	int			mouse_x;
	int			mouse_y;
}				t_hook;

typedef struct	s_all
{
	t_win		*awin;
	t_image		*aimg;
	t_map		*amap;
	t_box		*abox;
	t_play		*aplay;
	t_cam		*acam;
	t_ray		*aray;
	t_text		*atext;
	t_hook		*ahook;
}				t_all;

int				ft_loop(t_all *all);
int				open_map(t_map *amap);
int				create_skybox(t_box *abox, t_map *amap);
int				refresh(t_all *all);
int				move_player(t_all *all, int key);
void			draw_menu(t_win *awin, t_map *amap);
void			display_error(char *str) __attribute__((noreturn));
void			ray_skybox(t_all *all);
void			raycasting(t_all *all);
void			init_texture(t_win *awin, t_text *atext);
void			anim_pegasse(t_win *awin, t_text *atext);
void			clear_image(char *img, int last_pixel);
#endif
