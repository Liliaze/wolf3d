/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 17:20:14 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 17:27:12 by dboudy           ###   ########.fr       */
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

# define WIN	all->awin->win
# define MLX	all->awin->mlx
# define WINW	all->awin->w_width
# define WINH	all->awin->w_height
# define IMG	all->aimage->id
# define IMGW	all->aimage->i_width
# define IMGH	all->aimage->i_height
# define AI		all->aimage
# define AM		all->amap
# define AP		all->aplay
# define AC		all->acam
# define AB		all->abres
# define AW		all->awall
# define AH		all->ahook

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	int			w_width;
	int			w_height;
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
}				t_image;

typedef struct	s_map
{
	char		***map;
	char		*name;
	int			map_y;
	int			map_x;
}				t_map;

typedef struct	s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		speed;
	double		move_speed;
	double		rot_speed;
}				t_play;

typedef struct	s_camera
{
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
}				t_cam;

typedef struct	s_bres
{
	int			dx;
	int			dy;
	int			incx;
	int			incy;
}				t_bres;

typedef struct	s_wall
{
	int			xpm;
	int			color;
	int			pitch;
}				t_wall;

typedef struct	s_hook
{
	int			turn;
	int			in_menu;
}				t_hook;

typedef struct	s_all
{
	t_win		*awin;
	t_image		*aimage;
	t_map		*amap;
	t_play		*aplay;
	t_cam		*acam;
	t_bres		*abres;
	t_wall		*awall;
	t_hook		*ahook;
}				t_all;

int		ft_loop(t_all *all);
int		open_map(t_all * all);
void	init_data(t_cam *cam, t_play *player);
void	draw_menu(t_all *all);
void	display_error(t_all *all, char *str, int code_error);
void	print_map(t_all *all); // A SUPP
void	move_forward(t_map *amap, t_play *play, t_cam *cam);
void	move_backward(t_map *amap, t_play *play, t_cam *cam);
void	rotate_left(t_map *amap, t_play *play, t_cam *cam);
void	rotate_right(t_map *amap, t_play *play, t_cam *cam);
#endif
