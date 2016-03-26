/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:35:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/26 19:21:57 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	check_box(t_box *abox)
{
	int	y;
	int x;
	int tmp;

	y = 0;
	x = 0;
	tmp = 0;
	while (abox->box[y])
	{
		x = 0;
		while (abox->box[y][x])
		{
			tmp = abox->box[y][x];
			if ((y == 0 || y == abox->nb_y_box - 1 || x == 0
						|| x == abox->nb_x_box - 1) && tmp <= '0')
				display_error("Box invalid, need border");
			else if (!(y == 0 || y == abox->nb_y_box - 1 || x == 0
						|| x == abox->nb_x_box - 1) && tmp != '0')
				display_error("Invalid data in box need only 0 in middle");
			x++;
		}
		y++;
	}
	return (1);
}

static int	fill_box(t_box *abox)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < abox->nb_x_box)
		abox->box[i][j] = '1';
	while (++i < abox->nb_y_box - 1)
	{
		j = 0;
		abox->box[i][j] = '2';
		while (++j < (abox->nb_x_box - 1))
			abox->box[i][j] = '0';
		abox->box[i][j] = '2';
		j++;
		abox->box[i][j] = '\0';
	}
	j = -1;
	while (++j < abox->nb_x_box)
		abox->box[i][j] = '1';
	return (1);
}

static int	search_size_box(t_box *abox, t_map *amap)
{
	int	i;

	i = 0;
	abox->nb_x_box = amap->nb_x + 20;
	abox->nb_y_box = amap->nb_y + 20;
	if (!(abox->box = (char **)malloc(sizeof(abox->box) *
					((unsigned long)abox->nb_y_box + 1))))
		return (0);
	while (i < abox->nb_y_box)
	{
		abox->box[i] = ft_strnew((size_t)abox->nb_x_box);
		if (!(abox->box[i]))
			return (0);
		i++;
	}
	abox->box[i] = NULL;
	return (1);
}

int			create_skybox(t_box *abox, t_map *amap)
{
	if (!search_size_box(abox, amap))
		display_error("Failed malloc skybox");
	if (!(fill_box(abox)))
		display_error("Failed fill skybox");
	if (!(check_box(abox)))
		display_error("Failed fill skybox");
	return (1);
}
