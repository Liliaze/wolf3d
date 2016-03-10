/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 12:22:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 16:32:44 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
void	print_map(t_all *all) // A SUP
{
	int	i;
	int j;

	i = 0;
	while (AM->map[i])
	{
		j = 0;
		while (AM->map[i][j])
		{
			printf("%s", AM->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

inline static void	init_struct(t_all * all)
{
	all->awin = (t_win *)ft_memalloc(sizeof(t_win));
	AI = (t_image *)ft_memalloc(sizeof(t_image));
	AM = (t_map *)ft_memalloc(sizeof(t_map));
	AP = (t_play *)ft_memalloc(sizeof(t_play));
	AC = (t_cam *)ft_memalloc(sizeof(t_cam));
	AB = (t_bres *)ft_memalloc(sizeof(t_bres));
	AW = (t_wall *)ft_memalloc(sizeof(t_wall));
	AH = (t_hook *)ft_memalloc(sizeof(t_hook));
}

inline static int	init_windows(t_all *all)
{
	WINW = 1600;
	WINH = 1100;
	IMGW = 1600;
	IMGH = 1100;
	if ((MLX = mlx_init()) == NULL)
		display_error(all, "mlx_init() don't turn\n", 1);
	if ((WIN = mlx_new_window(MLX, (int)WINW, (int)WINH,
					"Psychedelic world of wolf 3D")) == NULL)
		display_error(all, "mlx_new_windows() don't turn\n", 1);
	if ((IMG = mlx_new_image(MLX, (int)IMGW, (int)IMGH)) == NULL)
		display_error(all, "mlx_new_image fail\n", 1);
	if (!(AI->data = mlx_get_data_addr(IMG, &AI->bpp, &AI->size_line,
					&AI->endian)))
		display_error(all, "mlx_get_data_address fail\n", 1);
	AI->bpp = (AI->bpp / 8) / 4;
	AI->size_line = AI->size_line / 4;
	AI->last_pixel = (IMGH * AI->size_line + IMGW * AI->bpp);
	return (1);
}

int		main(int ac, char **av)
{
	t_all	*all;

	if (ac < 2)
		printf("Please join a map\n");
	else
	{
		all = (t_all*)ft_memalloc(sizeof(t_all));
		init_struct(all);
		AM->name = ft_strdup(av[1]);
		if ((open_map(all)) == 0) // A PLACER DANS CHOIX MAP
			display_error(all, "open map failed", 1);
		init_windows(all);
		print_map(all); //A SUP
		ft_loop(all);
	}
	return (0);
}
