/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_skybox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/26 19:59:00 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_distance(t_ray *ray, t_play *player, t_box *abox)
{
	if (ray->rdx < 0)
	{
		ray->stepx = -1;
		ray->side_dx = (player->posx - abox->boxx) * ray->delta_dx;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dx = (abox->boxx + 1.0 - player->posx)
			* ray->delta_dx;
	}
	if (ray->rdy < 0)
	{
		ray->stepy = -1;
		ray->side_dy = (player->posy - abox->boxy) * ray->delta_dy;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dy = (abox->boxy + 1.0 - player->posy)
			* ray->delta_dy;
	}
}

static int	check_side(t_ray *aray, t_box *abox)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0 && side != -1)
	{
		if (aray->side_dx < aray->side_dy)
		{
			aray->side_dx += aray->delta_dx;
			abox->boxx += aray->stepx;
			side = 0;
		}
		else
		{
			aray->side_dy += aray->delta_dy;
			abox->boxy += aray->stepy;
			side = 1;
		}
		if (abox->box[abox->boxx][abox->boxy] > '0')
			hit = 1;
	}
	return (side);
}

static void	draw_height(t_ray *aray, t_image *aimg, t_box *abox, int x)
{
	int draw_end;
	int	pixel;
	int plop;
	int *tmp;
	int y;

	plop = abox->box[abox->boxx][abox->boxy];
	if (plop == '1')
		COLOR = BLUEF;
	else if (plop == '2')
		COLOR = BLUEF / 2;
	draw_end = 650 + (int)aray->jump;
	x = x * BPP;
	y = -1;
	tmp = (int*)(void*)DATA;
	while (++y <= draw_end)
	{
		pixel = x + y * SIZE_L;
		tmp[pixel] = COLOR;
	}
}

void		ray_skybox(t_all *all)
{
	int x;
	int side;

	x = 0;
	side = 0;
	while (x < all->WINW)
	{
		AC->camx = (2 * x / (double)(all->WINW)) - 1;
		AR->rdx = AP->dirx + AC->planex * AC->camx;
		AR->rdy = AP->diry + AC->planey * AC->camx;
		AB->boxx = (int)(AP->posx);
		AB->boxy = (int)(AP->posy);
		AR->delta_dx = sqrt(1 + (AR->rdy * AR->rdy) / (AR->rdx * AR->rdx));
		AR->delta_dy = sqrt(1 + (AR->rdx * AR->rdx) / (AR->rdy * AR->rdy));
		check_distance(AR, AP, AB);
		side = check_side(AR, AB);
		draw_height(AR, AI, AB, x);
		x++;
	}
}
