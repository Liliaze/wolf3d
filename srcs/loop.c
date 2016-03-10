/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:49:49 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 17:31:55 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	int key_press(int key, t_all *all)
{
	if (key == ECHAP)
		exit(0);
	else if (key == ENTER)
		draw_menu(all);
	else if (key == UP)
		move_forward(AM, AP, AC)
	else if (key == DOWN)
		move_backward(AM, AP, AC)
	else if (key == LEFT)
		rotate_left(AM, AP, AC)
	else if (key == RIGHT)
		rotate_right(AM, AP, AC)
	return (0);
}

int		ft_loop(t_all *all)
{
	mlx_hook(WIN, 2, (1L << 0), key_press, all);
	mlx_loop(MLX);
	return (0);
}
