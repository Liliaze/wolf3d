/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:49:49 by dboudy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/29 16:15:14 by dboudy           ###   ########.fr       */
=======
/*   Updated: 2016/03/26 19:43:12 by dboudy           ###   ########.fr       */
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	key_press(int key, t_all *all)
{
	if (key == ECHAP)
		exit(0);
	else if (all->awin->in_menu == 0)
	{
		if ((key == UP || key == W || key == DOWN || key == S || key == LEFT
					|| key == A || key == RIGHT || key == D) && (AH->event = 1))
			move_player(all, key);
		else if (key == SPACE && AR->jump < 500 && (AH->event = 1))
			AR->jump += 10;
		else if (key == 6 && AR->jump > 0 && (AH->event = 1))
			AR->jump -= 10;
		else if (key == ENTER)
			draw_menu(AWIN, AM);
		else if (key == MORE || key == LESS)
		{
			if (key == MORE && AP->speed < 1.0)
				AP->speed *= 1.2;
			else if (key == LESS && AP->speed > 0.01)
				AP->speed *= 0.8;
			AP->coef_rot = AP->speed / 3;
		}
	}
	else if (key == ENTER && (move_player(all, DOWN)) && (AH->event = 1))
		all->awin->in_menu = 0;
	return (0);
}

static int	mouse_release(int button, int x, int y, t_all *all)
{
	if (all->awin->in_menu == 0)
	{
		x = y;
		if (button == 1)
			AH->button1 = 0;
	}
	return (0);
}

static int	mouse_clic(int button, int x, int y, t_all *all)
{
	if (all->awin->in_menu == 0)
	{
		x = y;
		if (button == 1 && (AH->event = 2))
			AH->button1 = 1;
	}
	return (0);
}

static int	mouse_motion(int x, int y, t_all *all)
{
	int delta;

	AH->mouse_y = y;
	if (all->awin->in_menu == 0)
	{
		AH->event = 2;
		delta = x - AH->mouse_x;
		if (delta > 150 || delta < -150)
			AP->coef_motion = 1.5;
		else if (delta > 60 || delta < -60)
			AP->coef_motion = 1.3;
		else if (delta > 30 || delta < -30)
			AP->coef_motion = 1.1;
		if (delta > 0)
			move_player(all, RIGHT);
		else if (delta < 0)
			move_player(all, LEFT);
		else if (delta == 0)
			AT->anim = 1;
		AP->coef_motion = 1;
		AH->mouse_x = x;
	}
	return (0);
}

int			ft_loop(t_all *all)
{
	mlx_loop_hook(all->MLX, refresh, all);
	mlx_hook(all->WIN, 2, (1L << 0), key_press, all);
	mlx_hook(all->WIN, 4, (1L << 2), mouse_clic, all);
	mlx_hook(all->WIN, 5, (1L << 3), mouse_release, all);
	mlx_hook(all->WIN, 6, (1L << 8), mouse_motion, all);
	mlx_loop(all->MLX);
	return (0);
}
