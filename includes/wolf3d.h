/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:20:14 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/15 16:33:30 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "./color_and_key.h"
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <sys/types.h>
# include <stdio.h> // A SUPPRIMER !!!!!

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
# define AI		all->aimage
# define AM		all->amap
# define AP		all->aplay
# define AB		all->abox
# define AC		all->acam
# define AR		all->aray
# define AWALL	all->awall
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
	void		*id_box;
	char		*data_box;
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
	int			nb_x;
	int			nb_y;
	int			mapy;
	int			mapx;
}				t_map;

typedef struct	s_skybox
{
	char		***box;
	char		*name_box;
	int		nb_x_box;
	int		nb_y_box;
	int		boxy;
	int		boxx;
}		t_box;

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
//	double		speed;
	double		coef_rot;
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
	double		ray_dirx;
	double		ray_diry;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		h_wall;
	int			stepx;
	int			stepy;
}				t_ray;

typedef struct	s_wall //if texture
{
	int			xpm;
	int			pitch;
}				t_wall;

typedef struct	s_hook
{
	int			turn;
	int			mouse_x;
}				t_hook;

typedef struct	s_all
{
	t_win		*awin;
	t_image		*aimage;
	t_map		*amap;
	t_box		*abox;
	t_play		*aplay;
	t_cam		*acam;
	t_ray		*aray;
	t_wall		*awall;
	t_hook		*ahook;
}				t_all;

int		ft_loop(t_all *all);
int		open_map(t_map *amap, t_win *awin);
int		open_box(t_box *abox, t_win *awin);
void	draw_menu(t_win *awin, t_map *amap);
void	display_error(t_win *awin, char *str, int code_error);
void	print_map(t_map *amap); // A SUPP
void	ray_skybox(t_all *all);
void	raycasting(t_all *all);
void	clear_image(char *img, int last_pixel);
void	move_forward(t_map *amap, t_play *aplay);
void	move_backward(t_map *amap, t_play *aplay);
void	rotate_left(t_cam *acam, t_play *aplay);
void	rotate_right(t_cam *acam, t_play *aplay);
#endif
