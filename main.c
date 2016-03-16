/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:22:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/15 20:22:42 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	print_box(t_box *abox) // A SUP
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (abox->box[i])
	{
		j = 0;
		while (abox->box[i][j])
		{
			j++;
		}
		i++;
	}
}

void	print_map(t_map *amap) // A SUP
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (amap->map[i])
	{
		j = 0;
		while (amap->map[i][j])
		{
			j++;
		}
		i++;
	}
}

static void	check_box(t_box *abox, t_win *awin) // A SUP
{
	int	y;
	int x;
	int tmp;

	y = 0;
	x = 0;
	tmp = 0;
	while (abox->box[y])
	{
		x = 0;
		while (abox->box[y][x])
		{
			tmp = ft_atoi(abox->box[y][x]);
			if ((y == 0 || y == abox->nb_y_box - 1 || x == 0 || x == abox->nb_x_box - 1) && tmp <= 0)
				display_error(awin, "Box invalid, need border", 1);
			else if (tmp != 0)
				display_error(awin, "Invalid data in box need only 0 in middle", 1);
			x++;
		}
		y++;
	}
}

static void	check_map(t_map *amap, t_win *awin) // A SUP
{
	int	y;
	int x;
	int tmp;

	y = 0;
	x = 0;
	tmp = 0;
	while (amap->map[y])
	{
		x = 0;
		while (amap->map[y][x])
		{
			tmp = ft_atoi(amap->map[y][x]);
			if ((y == 0 || y == amap->nb_y - 1 || x == 0 || x == amap->nb_x - 1) && tmp <= 0)
				display_error(awin, "Map invalid, need border", 1);
			//quand menu en place à appeler a la creation et changer code_error
			if (!(tmp >= 0 && tmp <= 10))
				display_error(awin, "Invalid data in map", 1);
			x++;
		}
		y++;
	}
}

inline static void	init_struct(t_all * all)
{
	AWIN = (t_win *)ft_memalloc(sizeof(t_win));
	AI = (t_image *)ft_memalloc(sizeof(t_image));
	AM = (t_map *)ft_memalloc(sizeof(t_map));
	AB = (t_box *)ft_memalloc(sizeof(t_box));
	AP = (t_play *)ft_memalloc(sizeof(t_play));
	AC = (t_cam *)ft_memalloc(sizeof(t_cam));
	AR = (t_ray *)ft_memalloc(sizeof(t_ray));
	AWALL = (t_wall *)ft_memalloc(sizeof(t_wall));
	AH = (t_hook *)ft_memalloc(sizeof(t_hook));
}

inline static void	init_windows(t_win *awin, t_image *aimg, t_box *abox)
{
	WINW = 1600;
	WINH = 1100;
	IMGW = 1600;
	IMGH = 1100;
	if ((MLX = mlx_init()) == NULL)
		display_error(awin, "mlx_init() don't turn", 1);
	if ((WIN = mlx_new_window(MLX, (int)WINW, (int)WINH,
				"Futur psychedelic world of wolf 3D")) == NULL)
		display_error(awin, "mlx_new_windows() don't turn", 1);
	if ((IMG = mlx_new_image(MLX, (int)IMGW, (int)IMGH)) == NULL)
		display_error(awin, "mlx_new_image fail", 1);
	if (!(DATA = mlx_get_data_addr(IMG, &BPP, &SIZE_L, &aimg->endian)))
		display_error(awin, "mlx_get_data_address fail", 1);
	if ((aimg->id_box = mlx_new_image(MLX, (int)IMGW, (int)IMGH)) == NULL)
		display_error(awin, "mlx_new_image box fail", 1);
	if (!(aimg->data_box = mlx_get_data_addr(aimg->id_box, &BPP, &SIZE_L, &aimg->endian)))
		display_error(awin, "mlx_get_data_address box fail", 1);
	BPP = (BPP / 8) / 4;
	SIZE_L = SIZE_L / 4;
	LAST_P = (IMGH * SIZE_L + IMGW * BPP);
}

inline static void init_pos_x_y(t_win *awin, t_map *amap, t_play *aplay)
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
		display_error(awin, "The map has to contains at least one '0'", 1);
	else if (amap->map[y + 1][x + 1] && (ft_atoi(amap->map[y + 1][x + 1])) == 0)
	{
		aplay->posx = x + 1;
		aplay->posy = y + 1;
	}
	else
	{
		aplay->posx = x;
		aplay->posy = y;
	}
}

inline static void	init_data_play(t_play *aplay, t_hook *ahook, t_cam *acam)
{
	aplay->dirx = -1;
	aplay->diry = 0;
	aplay->coef_rot = 5 * M_PI / 180;
	ahook->mouse_x = 0;
	acam->planex = 0;
	acam->planey = 0.66;
	acam->camx = 0;
}

int		main(int ac, char **av)
{
	t_all	*all;

	if (ac < 3)
		printf("Please join a skybox in first and a map in second\n");
	else
	{
		all = (t_all*)ft_memalloc(sizeof(t_all));
		init_struct(all);
		AM->name = ft_strdup(av[2]);
		AB->name_box = ft_strdup(av[1]);
		init_windows(AWIN, AI, AB); //avant ou apres read_map + box ?
		if (!(open_box(AB, AWIN))) // A LAISSER DANS MAIN ?
			display_error(AWIN,"open box failed", 1);
		print_box(AB); //A SUP
		if (!(open_map(AM, AWIN))) // A PLACER DANS CHOIX MAP
			display_error(AWIN,"open map failed", 1);
		print_map(AM); //A SUP
		init_data_play(AP, AH, AC);
		init_pos_x_y(AWIN, AM, AP);
		check_map(AM, AWIN);
		check_box(AB, AWIN);
		ft_loop(all);
	}
	return (0);
}
