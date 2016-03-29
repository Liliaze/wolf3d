/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:18:08 by dboudy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/29 14:45:07 by dboudy           ###   ########.fr       */
=======
/*   Updated: 2016/03/26 19:58:30 by dboudy           ###   ########.fr       */
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_arc(t_win *awin)
{
	int		y;
	int		x;
	double	d;
	double	e;
	double	gap;

	d = WINW * 0.18;
	e = (WINW - 2 * d) / 2;
	y = (int)d;
	while (--y > 0)
	{
		x = (int)(d * 2);
		while (--x > 0)
		{
			gap = (d - x) * (d - x) + (d - y) * (d - y);
			if (gap < d * d * 0.5 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), BLUEF);
			else if (gap < d * d * 0.6 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), GREENF);
			else if (gap < d * d * 0.7 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), ORANGE);
			else if (gap < d * d * 0.8 && gap > d * d * 0.4)
				mlx_pixel_put(MLX, WIN, (int)(x + e), (int)(100 + y), RED);
		}
	}
}

static void	draw_background(t_win *awin)
{
	int		y;
	int		x;
	int		d;

	d = (int)(WINW / 8);
	y = -1;
	while (++y < WINH)
	{
		x = -1;
		while (++x < WINW)
		{
			if (((x < WINW / 12 || x > WINW - WINW / 12) || (y < WINH
							/ 12 || y > WINH - WINH / 12)) && y < WINH / 2)
				mlx_pixel_put(MLX, WIN, x, y, ((d - x) * (d - x) + (d - y)
							* (d - y)) * y / 2);
			else if (((x < WINW / 12 || x > WINW - WINW / 12) || (y < WINH
							/ 12 || y > WINH - WINH / 12)) && y > WINH / 2)
				mlx_pixel_put(MLX, WIN, x, y, ((d - x) * (d - x) + (d - y)
							* (d - y)) / y);
		}
	}
}

static void	draw_str_menu(t_win *awin, t_map *amap)
{
	mlx_string_put(MLX, WIN, (WINW - 100) / 2,
			(WINH / 2) - 120, PINK, "WELCOME :D");
	mlx_string_put(MLX, WIN, (WINW - 120) / 2,
			WINH / 2 - 90, PINK, "IN MY WOLF3D");
<<<<<<< HEAD
	mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - ft_strlen(amap->name)
					* 10) / 2), WINH / 2 - 30, ORANGE, amap->name);
	mlx_string_put(MLX, WIN, (WINW - 540) / 2, WINH / 2, RED,
			"================= * ENTER TO START * =================");
	mlx_string_put(MLX, WIN, (WINW - 220) / 2, WINH / 2 + 90, BLUE,
			"ARROWS or WASD to Move");
	mlx_string_put(MLX, WIN, (WINW - 350) / 2, WINH / 2 + 120, BLUE,
			"Use + or - of keypad to change SPEED");
	mlx_string_put(MLX, WIN, (WINW - 170) / 2, WINH / 2 + 150, BLUE,
			"SPACE to Fly Away");
	mlx_string_put(MLX, WIN, (WINW - 120) / 2, WINH / 2 + 180, BLUE,
			"Z to Go Down");
	mlx_string_put(MLX, WIN, (WINW - 280) / 2, WINH / 2 + 240, CYAN,
			"You can play with only MOUSE");
	mlx_string_put(MLX, WIN, (WINW - 130) / 2, WINH / 2 + 300, GREY,
			"ECHAP to Quit");
}

static void	draw_failed(t_win *awin)
{
	mlx_string_put(MLX, WIN, (WINW - 440) / 2, WINH / 2 - 30, RED,
			"*******************************************");
	mlx_string_put(MLX, WIN, (WINW - 440) / 2, WINH / 2, RED,
			"===========> *** YOU LOOSE  *** <==========");
	mlx_string_put(MLX, WIN, (WINW - 440) / 2, WINH / 2 + 30, RED,
			"*******************************************");
	mlx_string_put(MLX, WIN, (WINW - 230) / 2, (int)(WINH / 2 + 120), YELLOW,
			":( ENTER TO CONTINUE :(");
	mlx_string_put(MLX, WIN, (WINW - 130) / 2, WINH / 2 + 300, RED,
			"ECHAP to Quit");
}

static void	draw_succes(t_win *awin)
{
	mlx_string_put(MLX, WIN, (WINW - 420) / 2, WINH / 2 - 30, GREEN,
			"*****************************************");
	mlx_string_put(MLX, WIN, (WINW - 420) / 2, WINH / 2, GREEN,
			"===========> *** YOU WIN  *** <==========");
	mlx_string_put(MLX, WIN, (WINW - 420) / 2, WINH / 2 + 30, GREEN,
			"*****************************************");
	mlx_string_put(MLX, WIN, (WINW - 230) / 2, (int)(WINH / 2 + 120), YELLOW,
			":) ENTER TO CONTINUE :)");
	mlx_string_put(MLX, WIN, (WINW - 130) / 2, WINH / 2 + 300, GREY,
=======
	mlx_string_put(MLX, WIN, (WINW - 540) / 2, (int)(WINH / 2 - 30), RED,
			"================= * ENTER TO START * =================");
	mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - ft_strlen(amap->name)
					* 10) / 2), WINH / 2, ORANGE, amap->name);
	mlx_string_put(MLX, WIN, (WINW - 220) / 2, WINH / 2 + 60, GREEN,
			"ARROWS or WASD to Move");
	mlx_string_put(MLX, WIN, (WINW - 350) / 2, WINH / 2 + 90, GREEN,
			"Use + or - of keypad to change SPEED");
	mlx_string_put(MLX, WIN, (WINW - 170) / 2, WINH / 2 + 120, GREEN,
			"SPACE to Fly Away");
	mlx_string_put(MLX, WIN, (WINW - 120) / 2, WINH / 2 + 150, GREEN,
			"Z to Go Down");
	mlx_string_put(MLX, WIN, (WINW - 280) / 2, WINH / 2 + 210, YELLOW,
			"You can play with only MOUSE");
	mlx_string_put(MLX, WIN, (WINW - 130) / 2, WINH / 2 + 270, GREEN,
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
			"ECHAP to Quit");
}

void		draw_menu(t_win *awin, t_map *amap)
{
	awin->in_menu = 1;
	mlx_clear_window(MLX, WIN);
	draw_arc(awin);
	if (amap->goal != 2 && amap->goal != 3)
	{
		draw_background(awin);
		draw_str_menu(awin, amap);
		if (amap->goal)
			mlx_string_put(MLX, WIN, (WINW - 410) / 2, WINH / 2 + 30, YELLOW,
					"=======> Find the Black'Ol Block <=======");
	}
	else if (amap->goal == 2)
		draw_succes(awin);
	else if (amap->goal == 3)
		draw_failed(awin);
}
