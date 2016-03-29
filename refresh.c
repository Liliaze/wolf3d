/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 14:34:01 by dboudy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/29 14:45:09 by dboudy           ###   ########.fr       */
=======
/*   Updated: 2016/03/26 19:44:18 by dboudy           ###   ########.fr       */
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	refresh_classic(t_all *all, double *old_time)
{
	double new_time;

	new_time = clock();
	if (AH->event == 1)
	{
		mlx_clear_window(all->MLX, all->WIN);
		ray_skybox(all);
		raycasting(all);
		mlx_put_image_to_window(all->MLX, all->WIN, all->aimg->id, 0, 0);
		anim_pegasse(AWIN, AT);
	}
	if (!AH->button1 || AH->event == 2)
		AH->event = 0;
	*old_time = new_time;
}

static void	refresh_motion(t_all *all, double *old_time)
{
	double new_time;
	double delta;

	new_time = clock();
	delta = new_time - *old_time;
	if (delta >= 30000)
	{
		if (AH->button1)
			move_player(all, UP);
		else if (AR->jump > 0)
			AT->anim = 1;
		mlx_clear_window(all->MLX, all->WIN);
		ray_skybox(all);
		raycasting(all);
		mlx_put_image_to_window(all->MLX, all->WIN, all->aimg->id, 0, 0);
		anim_pegasse(AWIN, AT);
		if (!(AH->button1) && !(AR->jump > 0))
			AH->event = 0;
		*old_time = new_time;
	}
}

int			refresh(t_all *all)
{
	static double old_time = 1;

<<<<<<< HEAD
	if (AM->goal == 2 || AM->goal == 3)
	{
		draw_menu(AWIN, AM);
		AM->goal = 0;
	}
=======
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
	if (all->awin->in_menu == 0)
	{
		if (AH->event == 1)
			refresh_classic(all, &old_time);
		else if (AH->event == 2 || AR->jump > 0)
			refresh_motion(all, &old_time);
	}
	return (0);
}

void		display_error(char *str)
{
	ft_trace_str("31", str);
	ft_putstr("\n");
	exit(0);
}
