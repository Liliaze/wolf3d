/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:38:17 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/17 11:15:30 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_distance(t_ray *ray, t_play *player, t_map *map)
{
	if (ray->ray_dirx < 0)
	{
		ray->stepx = -1;
		ray->side_dist_x = (player->posx - map->mapx) * ray->delta_dist_x;
	}
	else
	{
		ray->stepx = 1;
		ray->side_dist_x = (map->mapx + 1.0 - player->posx) * ray->delta_dist_x;
	}
	if (ray->ray_diry < 0)
	{
		ray->stepy = -1;
		ray->side_dist_y = (player->posy - map->mapy) * ray->delta_dist_y;
	}
	else
	{
		ray->stepy = 1;
		ray->side_dist_y = (map->mapy + 1.0 - player->posy) * ray->delta_dist_y;
	}
}

static void	choose_color(t_image *aimg, t_map *map, int *side)
{
	int tmp;

	tmp = ft_atoi(map->map[map->mapx][map->mapy]);
	if (tmp == 1)
		COLOR = PINK;
	else if (tmp == 2)
		COLOR = BROWN;
	else if (tmp == 3)
		COLOR = PURPLE;
	else if (tmp == 4)
		COLOR = WHITE;
	else
		COLOR = YELLOW;
	if (*side == 1)
		COLOR = COLOR / 2;
}

static int	check_side(t_ray *aray, t_map *map)
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
			map->mapx += aray->stepx;
			side = 0;
		}
		else
		{
			aray->side_dist_y += aray->delta_dist_y;
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
	int draw_start;
	int draw_end;
	int line_height;
	int	pixel;
	int *tmp;
	int y;

	line_height = abs((int)(WINH / aray->h_wall));
	draw_start = (int)((-line_height / 2 + WINH / 2) - 1);
	draw_end = (int)(line_height / 2 + WINH / 2);
	if (draw_start < 0)
		draw_start = -1;
	if (draw_end >= WINH)
		draw_end = (WINH - 1);
	x = x * BPP;
	y = -1;
	tmp = (int*)(void*)DATA;
	while (++y < WINH)
	{
		pixel = x + y * SIZE_L;
//		if (y < draw_start)
//			tmp[pixel] = CYAN * 2;
/*		else */if (y <= draw_end && y >= draw_start)
			tmp[pixel] = COLOR;
//		else if (y < WINH)
//			tmp[pixel] = GREENF;
	}
}

void		raycasting(t_all *all)
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
		AM->mapx = (int)(AP->posx);
		AM->mapy = (int)(AP->posy);
		AR->delta_dist_x = sqrt(1 + (AR->ray_diry * AR->ray_diry) /
				(AR->ray_dirx * AR->ray_dirx));
		AR->delta_dist_y = sqrt(1 + (AR->ray_dirx * AR->ray_dirx) /
				(AR->ray_diry * AR->ray_diry));
		check_distance(AR, AP, AM);
		side = check_side(AR, AM);
		choose_color(AI, AM, &side);
		if (side == 0)
			AR->h_wall = fabs((AM->mapx - AP->posx + (1 - AR->stepx) / 2)
				/ AR->ray_dirx);
		else if (side == 1)
			AR->h_wall = fabs((AM->mapy - AP->posy + (1 - AR->stepy) / 2)
				/ AR->ray_diry);
		draw_height(AI, AWIN, AR, x);
		x++;
	}
}
