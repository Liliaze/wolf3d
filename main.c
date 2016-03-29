/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:22:17 by dboudy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/29 13:10:33 by dboudy           ###   ########.fr       */
=======
/*   Updated: 2016/03/26 19:59:44 by dboudy           ###   ########.fr       */
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

inline static void	init_struct(t_all *all)
{
	AWIN = (t_win *)ft_memalloc(sizeof(t_win));
	AI = (t_image *)ft_memalloc(sizeof(t_image));
	AM = (t_map *)ft_memalloc(sizeof(t_map));
	AB = (t_box *)ft_memalloc(sizeof(t_box));
	AP = (t_play *)ft_memalloc(sizeof(t_play));
	AC = (t_cam *)ft_memalloc(sizeof(t_cam));
	AR = (t_ray *)ft_memalloc(sizeof(t_ray));
	AT = (t_text *)ft_memalloc(sizeof(t_text));
	AH = (t_hook *)ft_memalloc(sizeof(t_hook));
}

inline static void	init_windows(t_win *awin, t_image *aimg)
{
	WINW = 2200;
	WINH = 1200;
	IMGW = 2200;
	IMGH = 1200;
	if ((MLX = mlx_init()) == NULL)
		display_error("mlx_init() don't turn");
	if ((WIN = mlx_new_window(MLX, (int)WINW, (int)WINH,
				"Futur psychedelic world of Pegasse 3D")) == NULL)
		display_error("mlx_new_windows() don't turn");
	if ((IMG = mlx_new_image(MLX, (int)IMGW, (int)IMGH)) == NULL)
		display_error("mlx_new_image fail");
	if (!(DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_L, &aimg->endian)))
		display_error("mlx_get_data_address fail");
	BPP = (BPP / 8) / 4;
	SIZE_L = SIZE_L / 4;
	LAST_P = (IMGH * SIZE_L + IMGW * BPP);
}

inline static void	init_pos_x_y(t_map *amap, t_play *aplay)
{
	int	x;
	int	y;
	int tmp;

	y = -1;
	x = -1;
	tmp = 1;
	while (tmp != 0 && amap->map[++y])
	{
		x = -1;
		while (tmp != 0 && amap->map[y][++x])
			tmp = ft_atoi(amap->map[y][x]);
	}
	if (tmp != 0)
		display_error("The map has to contains at least one '0'");
	else if (amap->map[y + 2][x + 2] && (ft_atoi(amap->map[y + 2][x + 2])) == 0)
	{
		aplay->posx = x + 2;
		aplay->posy = y + 2;
	}
	else
	{
		aplay->posx = x;
		aplay->posy = y;
	}
}

inline static void	init_data_play(t_play *aplay, t_hook *ahook, t_cam *acam,
		t_ray *aray)
{
	aplay->dirx = -1;
	aplay->diry = 0;
	aplay->speed = 0.2;
	aplay->coef_rot = aplay->speed / 3;
	aplay->coef_motion = 1;
	aray->jump = 0;
	ahook->mouse_x = 0;
	acam->planex = 0;
	acam->planey = 0.66;
	acam->camx = 0;
}

int					main(int ac, char **av)
{
	t_all	*all;

	if (ac != 2)
		display_error("Please join a skybox in first and a map in second\n");
	else
	{
		all = (t_all*)ft_memalloc(sizeof(t_all));
		init_struct(all);
		AM->name = ft_strdup(av[1]);
		init_windows(AWIN, AI);
		if (!(open_map(AM)))
			display_error("open map failed");
		if (!(create_skybox(AB, AM)))
			display_error("open box failed");
		init_data_play(AP, AH, AC, AR);
		init_pos_x_y(AM, AP);
		init_texture(AWIN, AT);
		draw_menu(AWIN, AM);
		ft_loop(all);
	}
	return (0);
}
