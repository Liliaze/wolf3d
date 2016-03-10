/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 15:01:12 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 15:19:14 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


static	void draw_wall(t_all *all)
{
	
}

static	calcul_is_in_screen(t_all *all)
{
	AH->in_menu =AH->in_menu;
	return (1);
}

void	draw_screen(t_all *all)
{
	int i;
	int	j;
	while (AM->map[i])
	{
		j = 0;
		while (AM->map[i][j])
		{
			if (calcul_is_in_screen())
				draw_wall(all);
			j++;
		}
		i++;
	}
}
