/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:23:38 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/11 18:48:03 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	void	bres_dx_sup(t_all *all)
{
	int	i;
	int e;
	int inc1;
	int inc2;

	i = 0;
	mlx_pixel_put(all->MLX, all->WIN, all->abres->x1, all->abres->y1, COLOR);
	e = 2 * all->abres->dy - all->abres->dx;
	inc1 = 2 * (all->abres->dy - all->abres->dx);
	inc2 = 2 * all->abres->dy;
	while (i < all->abres->dx)
	{
		if (e >= 0)
		{
			all->abres->y1 += all->abres->incy;
			e += inc1;
		}
		else
			e += inc2;
		all->abres->x1 += all->abres->incx;
		mlx_pixel_put(all->MLX, all->WIN, all->abres->x1, all->abres->y1, COLOR);
		i++;
	}
}

static void		bres_else(t_all *all)
{
	int	i;
	int	e;
	int inc1;
	int inc2;

	i = 0;
	mlx_pixel_put(all->MLX, all->WIN, all->abres->x1, all->abres->y1, COLOR);
	e = 2 * all->abres->dx - all->abres->dy;
	inc1 = 2 * (all->abres->dx - all->abres->dy);
	inc2 = 2 * all->abres->dx;
	while (i < all->abres->dy)
	{
		if (e >= 0)
		{
			all->abres->x1 += all->abres->incx;
			e += inc1;
		}
		else
			e += inc2;
		all->abres->y1 += all->abres->incy;
		mlx_pixel_put(all->MLX, all->WIN, all->abres->x1, all->abres->y1, COLOR);
		i++;
	}
}

int				bres(t_all *all)
{
	all->abres->dx = all->abres->x2 - all->abres->x1;
	all->abres->dy = all->abres->y2 - all->abres->y1;
	if (all->abres->dx < 0)
		all->abres->dx = -all->abres->dx;
	if (all->abres->dy < 0)
		all->abres->dy = -all->abres->dy;
	all->abres->incx = 1;
	if (all->abres->x2 < all->abres->x1)
		all->abres->incx = -1;
	all->abres->incy = 1;
	if (all->abres->y2 < all->abres->y1)
		all->abres->incy = -1;
	if (all->abres->dx > all->abres->dy)
		bres_dx_sup(all);
	else
		bres_else(all);
	return (0);
}
