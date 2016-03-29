/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:13 by dboudy            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/03/29 16:15:47 by dboudy           ###   ########.fr       */
=======
/*   Updated: 2016/03/26 19:19:00 by dboudy           ###   ########.fr       */
>>>>>>> 68fcb7eeb39e033ad1f9630a5fbef56c9a42ae90
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	move_forward(t_map *amap, t_play *aplay, int jump)
{
	int tmp;

	tmp = 0;
	if ((tmp = ft_atoi(amap->map[(int)(aplay->posx + aplay->dirx
					* aplay->speed)][(int)(aplay->posy)])) == 0 || (tmp == 6 && jump > 20))
		aplay->posx += aplay->dirx * aplay->speed;
	if (tmp == 5)
		amap->goal = 2;
	else if (tmp == 6 && jump <= 20)
		amap->goal = 3;
	if ((tmp = ft_atoi(amap->map[(int)(aplay->posx)][(int)(aplay->posy +
					aplay->diry * aplay->speed)])) == 0 || (tmp == 6 && jump > 20))
		aplay->posy += aplay->diry * aplay->speed;
	if (tmp == 5)
		amap->goal = 2;
	else if (tmp == 6 && jump <= 20)
		amap->goal = 3;
}

static void	move_backward(t_map *amap, t_play *aplay, int jump)
{
	int tmp;

	tmp = 0;
	if ((tmp = ft_atoi(amap->map[(int)(aplay->posx - aplay->dirx
					* aplay->speed)][(int)(aplay->posy)])) == 0 || (tmp == 6 && jump > 20))
		aplay->posx -= aplay->dirx * aplay->speed;
	if (tmp == 5)
		amap->goal = 2;
	else if (tmp == 6 && jump <= 20)
		amap->goal = 3;
	if ((tmp = ft_atoi(amap->map[(int)(aplay->posx)][(int)(aplay->posy -
					aplay->diry * aplay->speed)])) == 0 || (tmp == 6 && jump > 20))
		aplay->posy -= aplay->diry * aplay->speed;
	if (tmp == 5)
		amap->goal = 2;
	else if (tmp == 6 && jump <= 20)
		amap->goal = 3;
}

static void	rotate_right(t_cam *acam, t_play *aplay)
{
	double old_dirx;
	double old_planex;
	double cos_rot;
	double sin_rot;

	cos_rot = cos(-aplay->coef_rot * aplay->coef_motion);
	sin_rot = sin(-aplay->coef_rot * aplay->coef_motion);
	old_dirx = aplay->dirx;
	old_planex = acam->planex;
	aplay->dirx = aplay->dirx * cos_rot - aplay->diry * sin_rot;
	aplay->diry = old_dirx * sin_rot + aplay->diry * cos_rot;
	acam->planex = acam->planex * cos_rot - acam->planey * sin_rot;
	acam->planey = old_planex * sin_rot + acam->planey * cos_rot;
}

static void	rotate_left(t_cam *acam, t_play *aplay)
{
	double old_dirx;
	double old_planex;
	double cos_rot;
	double sin_rot;

	cos_rot = cos(aplay->coef_rot * aplay->coef_motion);
	sin_rot = sin(aplay->coef_rot * aplay->coef_motion);
	old_dirx = aplay->dirx;
	old_planex = acam->planex;
	aplay->dirx = aplay->dirx * cos_rot - aplay->diry * sin_rot;
	aplay->diry = old_dirx * sin_rot + aplay->diry * cos_rot;
	acam->planex = acam->planex * cos_rot - acam->planey * sin_rot;
	acam->planey = old_planex * sin_rot + acam->planey * cos_rot;
}

int			move_player(t_all *all, int key)
{
	if (key == UP || key == W)
	{
		all->atext->anim = 1;
		move_forward(AM, AP, (int)AR->jump);
	}
	if (key == RIGHT || key == D)
	{
		all->atext->anim = 2;
		rotate_right(AC, AP);
	}
	if (key == DOWN || key == S)
	{
		all->atext->anim = 3;
		move_backward(AM, AP, (int)AR->jump);
	}
	if (key == LEFT || key == A)
	{
		all->atext->anim = 4;
		rotate_left(AC, AP);
	}
	return (1);
}
