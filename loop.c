/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:49:49 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/17 11:44:39 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	refresh(t_all *all)
{
	mlx_clear_window(all->MLX, all->WIN);
	clear_image(all->DATA, all->LAST_P);
	ray_skybox(all);
	raycasting(all);
	mlx_put_image_to_window(all->MLX, all->WIN, all->aimg->id, 0, 0);
}

static	int key_press(int key, t_all *all)
{
	if (key == ECHAP)
		exit(0);
	else if (key == ENTER)
		draw_menu(AWIN, AM);
	else if (key == Q)
		raycasting(all);
	else if (key == UP)
		move_forward(AM, AP);
	else if (key == DOWN)
		move_backward(AM, AP);
	else if (key == LEFT)
		rotate_left(AC, AP);
	else if (key == RIGHT)
		rotate_right(AC, AP);
	refresh(all);
	return (0);
}

static int	mouse_motion(int x, int y, t_all *all)
{
	int right_side;
	int left_side;
	int old_x;

	right_side = all->WINW; //besoin ?
	left_side = all->WINW / 2;
	old_x = AH->mouse_x;
	AH->mouse_x = x;
	y = x; // utiliser y pour autre chose.
	if (AH->mouse_x > old_x)
		rotate_right(AC, AP);
	else
		rotate_left(AC, AP);
	refresh(all);
	return (0);
}

int		ft_loop(t_all *all)
{
	mlx_hook(all->WIN, 6, (1L << 8), mouse_motion, all);
	mlx_hook(all->WIN, 2, (1L << 0), key_press, all);
	mlx_loop(all->MLX);
	return (0);
}
