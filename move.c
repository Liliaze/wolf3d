/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:22:13 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/15 19:37:48 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void move_forward(t_map *amap, t_play *aplay)
{
	double	speed_test;

	speed_test = 0.4;
	if (ft_atoi(amap->map[(int)(aplay->posx + aplay->dirx
					* speed_test)][(int)(aplay->posy)]) == 0)
			aplay->posx += aplay->dirx * speed_test;
	if (ft_atoi(amap->map[(int)(aplay->posx)][(int)(aplay->posy +
					aplay->diry * speed_test)]) == 0)
			aplay->posy += aplay->diry * speed_test;
}

void move_backward(t_map *amap, t_play *aplay)
{
	double	speed_test;

	speed_test = 0.4;
	if (ft_atoi(amap->map[(int)(aplay->posx - aplay->dirx
					* speed_test)][(int)(aplay->posy)]) == 0)
		aplay->posx -= aplay->dirx * speed_test;
	if (ft_atoi(amap->map[(int)(aplay->posx)][(int)(aplay->posy -
					aplay->diry * speed_test)]) == 0)
		aplay->posy -= aplay->diry * speed_test;
}

void	rotate_right(t_cam *acam, t_play *aplay)
{
	double old_dirx;
	double old_planex;
	double cos_rot;
	double sin_rot;

	cos_rot = cos(-aplay->coef_rot); //-0.996802;
	sin_rot = sin(-aplay->coef_rot); //-0.079915;
	old_dirx = aplay->dirx;
	old_planex = acam->planex;
	aplay->dirx = aplay->dirx * cos_rot - aplay->diry * sin_rot;
	aplay->diry = old_dirx * sin_rot + aplay->diry * cos_rot;
	acam->planex = acam->planex * cos_rot - acam->planey * sin_rot;
	acam->planey = old_planex * sin_rot + acam->planey * cos_rot;
}

void	rotate_left(t_cam *acam, t_play *aplay)
{
	double old_dirx;
	double old_planex;
	double cos_rot;
	double sin_rot;

	cos_rot = cos(aplay->coef_rot); //0.996802;
	sin_rot = sin(aplay->coef_rot); //0.079915;
	old_dirx = aplay->dirx;
	old_planex = acam->planex;
	aplay->dirx = aplay->dirx * cos_rot - aplay->diry * sin_rot;
	aplay->diry = old_dirx * sin_rot + aplay->diry * cos_rot;
	acam->planex = acam->planex * cos_rot - acam->planey * sin_rot;
	acam->planey = old_planex * sin_rot + acam->planey * cos_rot;
}
