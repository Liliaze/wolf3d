/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/23 18:14:50 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_distance(t_ray *ray, t_play *player, t_map *map)
{
	if (ray->rdx < 0)
	{
		ray->stepx = -1;
		ray->side_dx = (player->posx - map->mapx) * ray->delta_dx;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dx = (map->mapx + 1.0 - player->posx) * ray->delta_dx;
	}
	if (ray->rdy < 0)
	{
		ray->stepy = -1;
		ray->side_dy = (player->posy - map->mapy) * ray->delta_dy;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dy = (map->mapy + 1.0 - player->posy) * ray->delta_dy;
	}
}

static void	choose_color(t_image *aimg, t_map *map, int *side)
{
	int tmp;

	tmp = ft_atoi(map->map[map->mapx][map->mapy]);
	if (tmp == 1)
		COLOR = PINK;
	else if (tmp == 2)
		COLOR = RED;
	else if (tmp == 3)
		COLOR = PURPLE;
	else if (tmp == 4)
		COLOR = ORANGE;
	else
		COLOR = YELLOW;
	if (*side == 1)
		COLOR = (int)(COLOR * 0.75);
}

static int	check_side(t_ray *aray, t_map *map)
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
			map->mapx += aray->stepx;
			side = 0;
		}
		else
		{
			aray->side_dy += aray->delta_dy;
			map->mapy += aray->stepy;
			side = 1;
		}
		if (ft_atoi(map->map[map->mapx][map->mapy]) > 0)
			hit = 1;
	}
	return (side);
}

static void	draw_height(t_image *aimg, t_win *awin, t_ray *aray, int x)
{
	int draw_end;
	int draw_start;
	int line_height;
	int	pixel;
	int *tmp;

	line_height = abs((int)(WINH / aray->h_wall));
	draw_start = (int)(aray->jump + ((-line_height / 2 + WINH / 2) - 1));
	draw_end = (int)(aray->jump + (line_height / 2 + WINH / 2));
	if (draw_start < 0)
		draw_start = -1;
	if (draw_end >= WINH - 4)
		draw_end = (WINH - 4);
	x = x * BPP;
	tmp = (int*)(void*)DATA;
	while (++draw_start < WINH)
	{
		pixel = x + draw_start * SIZE_L;
		if (draw_start <= draw_end)
			tmp[pixel] = COLOR;
		else
			tmp[pixel] = GREENF;
	}
}

void		raycasting(t_all *all)
{
	int x;
	int side;

	x = -1;
	side = 0;
	while (++x < all->WINW)
	{
		AC->camx = (2 * x / (double)(all->WINW)) - 1;
		AR->rdx = AP->dirx + AC->planex * AC->camx;
		AR->rdy = AP->diry + AC->planey * AC->camx;
		AM->mapx = (int)(AP->posx);
		AM->mapy = (int)(AP->posy);
		AR->delta_dx = sqrt(1 + (AR->rdy * AR->rdy) / (AR->rdx * AR->rdx));
		AR->delta_dy = sqrt(1 + (AR->rdx * AR->rdx) / (AR->rdy * AR->rdy));
		check_distance(AR, AP, AM);
		side = check_side(AR, AM);
		choose_color(AI, AM, &side);
		if (side == 0)
			AR->h_wall = fabs((AM->mapx - AP->posx + (1 - AR->stepx) / 2)
				/ AR->rdx);
		else if (side == 1)
			AR->h_wall = fabs((AM->mapy - AP->posy + (1 - AR->stepy) / 2)
				/ AR->rdy);
		draw_height(AI, AWIN, AR, x);
	}
}
