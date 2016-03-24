/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:18:08 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/18 16:38:11 by dboudy           ###   ########.fr       */
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
	mlx_string_put(MLX, WIN, (WINW - 110) / 2,
			(WINH / 2) - 120, PINK, "WELCOME :D");
	mlx_string_put(MLX, WIN, (WINW - 132) / 2,
			WINH / 2 - 90, PINK, "IN MY WOLF3D");
	mlx_string_put(MLX, WIN, (WINW - 460) / 2, (int)(WINH / 2 - 30), RED,
			"=============== ENTER TO START ===============");
	mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - ft_strlen(amap->name)
					* 10) / 2), WINH / 2, YELLOW, amap->name);
	mlx_string_put(MLX, WIN, (WINW - 220) / 2, WINH / 2 + 60, GREEN,
			"ARROWS or WASD to move");
	mlx_string_put(MLX, WIN, (WINW - 130) / 2, WINH / 2 + 90, GREEN,
			"ECHAP to quit");
}

void		draw_menu(t_win *awin, t_map *amap)
{
	awin->in_menu = 1;
	mlx_clear_window(MLX, WIN);
	draw_background(awin);
	draw_arc(awin);
	draw_str_menu(awin, amap);
}
