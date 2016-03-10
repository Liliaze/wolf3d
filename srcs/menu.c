/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:18:08 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 15:11:24 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf3d.h"

static void	draw_arc(t_all *all)
{
	int	y;
	int	x;
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

static void	draw_background(t_all *all)
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

static void	draw_str_menu(t_all *all)
{
	mlx_string_put(MLX, WIN, (WINW - 110) / 2,
			(WINH / 2) - 120, PINK, "WELCOME :D");
	mlx_string_put(MLX, WIN, (WINW - 132) / 2,
			WINH / 2 - 90, PINK, "IN MY WOLF3D");
	mlx_string_put(MLX, WIN, (WINW - 470) / 2, (int)(WINH / 2 - 30), RED,
			"=============== ENTER TO START ===============");
	mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - ft_strlen(AM->name)
					* 10) / 2), WINH / 2, YELLOW, AM->name);
	/*mlx_string_put(MLX, WIN, (WINW - 140) / 2, WINH / 2 + 60, GREEN,
			"ARROWS to move");
	mlx_string_put(MLX, WIN, (WINW - 380) / 2, WINH / 2 + 90, GREEN,
			"'-' or '+' of keypad or MOUSE to zoom");
	mlx_string_put(MLX, WIN, (WINW - 380) / 2, WINH / 2 + 120, GREEN,
			"'<' or '>' to change nb of iteration");
	mlx_string_put(MLX, WIN, (WINW - 230) / 2, WINH / 2 + 150, GREEN,
			"SPACE to active motion");
	mlx_string_put(MLX, WIN, (WINW - 290) / 2, WINH / 2 + 180, GREEN,
			"C to active my special mode");
	mlx_string_put(MLX, WIN, (WINW - 310) / 2, WINH / 2 + 210, GREEN,
			"'1', '2', '3' to change power");*/
}

void		draw_menu(t_all *all)
{
	AH->in_menu = 1;
	draw_background(all);
	draw_arc(all);
	draw_str_menu(all);
}
