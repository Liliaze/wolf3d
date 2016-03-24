/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pegasse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:05:46 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/23 18:14:30 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_load_texture(t_text *atext)
{
	int	i;

	i = -1;
	while (++i < 16)
	{
		if (!(atext->peg[i]))
			display_error(
					"Warning - one or more sprite of pegassus is missing");
	}
}

void		init_texture(t_win *awin, t_text *atext)
{
	int x;
	int y;

	x = 80;
	y = 80;
	atext->peg[0] = mlx_xpm_file_to_image(MLX, "./xpm/pegdos1.xpm", &x, &y);
	atext->peg[1] = mlx_xpm_file_to_image(MLX, "./xpm/pegdos2.xpm", &x, &y);
	atext->peg[2] = mlx_xpm_file_to_image(MLX, "./xpm/pegdos3.xpm", &x, &y);
	atext->peg[3] = mlx_xpm_file_to_image(MLX, "./xpm/pegdos4.xpm", &x, &y);
	atext->peg[4] = mlx_xpm_file_to_image(MLX, "./xpm/pegright1.xpm", &x, &y);
	atext->peg[5] = mlx_xpm_file_to_image(MLX, "./xpm/pegright2.xpm", &x, &y);
	atext->peg[6] = mlx_xpm_file_to_image(MLX, "./xpm/pegright3.xpm", &x, &y);
	atext->peg[7] = mlx_xpm_file_to_image(MLX, "./xpm/pegright4.xpm", &x, &y);
	atext->peg[8] = mlx_xpm_file_to_image(MLX, "./xpm/pegface1.xpm", &x, &y);
	atext->peg[9] = mlx_xpm_file_to_image(MLX, "./xpm/pegface2.xpm", &x, &y);
	atext->peg[10] = mlx_xpm_file_to_image(MLX, "./xpm/pegface3.xpm", &x, &y);
	atext->peg[11] = mlx_xpm_file_to_image(MLX, "./xpm/pegface4.xpm", &x, &y);
	atext->peg[12] = mlx_xpm_file_to_image(MLX, "./xpm/pegleft1.xpm", &x, &y);
	atext->peg[13] = mlx_xpm_file_to_image(MLX, "./xpm/pegleft2.xpm", &x, &y);
	atext->peg[14] = mlx_xpm_file_to_image(MLX, "./xpm/pegleft3.xpm", &x, &y);
	atext->peg[15] = mlx_xpm_file_to_image(MLX, "./xpm/pegleft4.xpm", &x, &y);
	check_load_texture(atext);
}

void		anim_pegasse(t_win *awin, t_text *atext)
{
	static int frame = 1;
	static int old_anim = 0;

	if (frame == 4 || atext->anim != old_anim)
		frame = 0;
	if (atext->anim == 1 && (old_anim = 1))
		mlx_put_image_to_window(MLX, WIN, atext->peg[frame],
				(WINW / 2 - 25), WINH - 100 );
	else if (atext->anim == 2 && (old_anim = 2))
		mlx_put_image_to_window(MLX, WIN, atext->peg[frame + 4],
				(WINW / 2 - 25), WINH - 100 );
	else if (atext->anim == 3 && (old_anim = 3))
		mlx_put_image_to_window(MLX, WIN, atext->peg[frame + 8],
				(WINW / 2 - 25), WINH - 100 );
	else if (atext->anim == 4 && (old_anim = 4))
		mlx_put_image_to_window(MLX, WIN, atext->peg[frame + 12],
				(WINW / 2 - 25), WINH - 100 );
	frame++;
}
