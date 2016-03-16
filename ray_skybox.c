/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_skybox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/15 20:16:12 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_distance(t_ray *ray, t_play *player, t_box *abox)
{
	if (ray->ray_dirx < 0)
	{
		ray->stepx = -1;
		ray->side_dist_x = (player->posx - abox->boxx) * ray->delta_dist_x;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dist_x = (abox->boxx + 1.0 - player->posx) * ray->delta_dist_x;
	}
	if (ray->ray_diry < 0)
	{
		ray->stepy = -1;
		ray->side_dist_y = (player->posy - abox->boxy) * ray->delta_dist_y;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dist_y = (abox->boxy + 1.0 - player->posy) * ray->delta_dist_y;
	}
}
/*
static void	choose_color(t_image *aimg, t_box *abox, int *side)
{
	int tmp;

	tmp = ft_atoi(abox->box[abox->boxx][abox->boxy]);
	if (tmp == 6)
		COLOR = CYAN; //texture etoile a implementer
	else if (tmp == 7)
		COLOR = GREENF;
	else
		COLOR = YELLOW;
	if (*side == 1)
		COLOR = COLOR / 2;
}*/

static int	check_side(t_ray *aray, t_box *abox)
{
	int	hit;
	int	side;

	hit = 0;
	side = 0;
	while (hit == 0 && side != -1)
	{
		if (aray->side_dist_x < aray->side_dist_y)
		{
			aray->side_dist_x += aray->delta_dist_x;
			abox->boxx += aray->stepx;
			side = 0;
		}
		else
		{
			aray->side_dist_y += aray->delta_dist_y;
			abox->boxy += aray->stepy;
			side = 1;
		}
		if (ft_atoi(abox->box[abox->boxx][abox->boxy]) > 0)
			hit = 1;
	}
	return (side);
}

static void	draw_height(t_image *aimg, t_win *awin, t_ray *aray, int x)
{
	int draw_start;
	int draw_end;
	int	pixel;
	int *tmp;
	int y;

	draw_start = 0;
	draw_end = WINH - 1;
	x = x * BPP;
	y = -1;
	tmp = (int*)(void*)aimg->data_box;
	while (++y <= draw_end)
	{
		pixel = x + y * SIZE_L;
		if (y < draw_end / 2)
			tmp[pixel] = CYAN;
		else if (y <= draw_end)
			tmp[pixel] = GREENF;
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
		AR->ray_dirx = AP->dirx + AC->planex * AC->camx;
		AR->ray_diry = AP->diry + AC->planey * AC->camx;
		AB->boxx = (int)(AP->posx);
		AB->boxy = (int)(AP->posy);
		AR->delta_dist_x = sqrt(1 + (AR->ray_diry * AR->ray_diry) /
				(AR->ray_dirx * AR->ray_dirx));
		AR->delta_dist_y = sqrt(1 + (AR->ray_dirx * AR->ray_dirx) /
				(AR->ray_diry * AR->ray_diry));
		check_distance(AR, AP, AB);
		side = check_side(AR, AB);
//need choice?		choose_color(AI, AB, &side);
//need h?
/*		if (side == 0)
			AR->h_wall = fabs((AM->mapx - AP->posx + (1 - AR->stepx) / 2)
				/ AR->ray_dirx);
		else if (side == 1)
			AR->h_wall = fabs((AM->mapy - AP->posy + (1 - AR->stepy) / 2)
				/ AR->ray_diry);
	*/	draw_height(AI, AWIN, AR, x);
		x++;
	}
}
