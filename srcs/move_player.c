/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 17:01:18 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 17:27:37 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_forward(t_map *amap, t_play *play, t_cam *cam)
{
	if (amap->map[(int)(play->posx + play->dirx *
				play->move_speed)][(int)(play->posy)] == 0)
		play->posx += play->dirx * play->move_speed;
	if (amap->map[(int)(play->posx)][(int)(play->posy
				+ play->diry * play->move_speed)] == 0)
		play->posy += play->diry * play->move_speed;
}

void	move_backward(t_map *amap, t_play *play, t_cam *cam)
{
		if (amap->map[(int)(play->posx - play->dirx *
					play->move_speed)][(int)(play->posy)] == 0)
			play->posx -= play->dirx * play->move_speed;
		if (amap->map[(int)(play->posx)][(int)(play->posy -
					play->diry * play->move_speed)] == 0)
			play->posy -= play->diry * play->move_speed;
}

void	rotate_left(t_map *amap, t_play *play, t_cam *cam)
{
		double old_dirx;
		double old_planex;

		old_dirx = play->dirx;
		old_planex = cam->planex;
		play->dirx = play->dirx * cos(play->rot_speed) -
			play->diry * sin(play->rot_speed);
		play->diry = old_dirx * sin(play->rot_speed) +
			play->diry * cos(play->rot_speed);
		cam->planex = cam->planex * cos(play->rot_speed) -
			cam->planey * sin(play->rot_speed);
		cam->planey = old_planex * sin(play->rot_speed) +
			cam->planey * cos(play->rot_speed);
}

void	rotate_right(t_map *amap, t_play *play, t_cam *cam)
{
		double old_dirx;
		double old_planex;

		old_dirx = play->dirx;
		old_planex = cam->planex;
		play->dirx = play->dirx * cos(-play->rot_speed) -
			play->diry * sin(-play->rot_speed);
		play->diry = old_dirx * sin(-play->rot_speed) +
			play->diry * cos(-play->rot_speed);
		cam->planex = cam->planex * cos(-play->rot_speed) -
			cam->planey * sin(-play->rot_speed);
		cam->planey = old_planex * sin(-play->rot_speed) +
			cam->planey * cos(-play->rot_speed);
}
