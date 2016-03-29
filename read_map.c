/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:02:06 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/29 13:14:19 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	check_map(t_map *amap)
{
	int	y;
	int x;
	int tmp;

	y = -1;
	x = 0;
	tmp = 0;
	while (amap->map[++y])
	{
		x = -1;
		while (amap->map[y][++x])
		{
			tmp = ft_atoi(amap->map[y][x]);
			if ((y == 0 || x == 0) && tmp <= 0)
				display_error("Map invalid, to need border");
			if (!(tmp >= 0 && tmp <= 10))
				display_error("Invalid data in map");
			if (tmp == 5)
				amap->goal = 1;
		}
		if (tmp <= 0)
			display_error("Map invalid, to need border");
		if (x != amap->nb_x)
			display_error("Map invalid, lines need to be same widht");
	}
}

static int	look_size_map(t_map *amap)
{
	char	tmp[2];
	ssize_t	ret;
	int		fd;
	int		boucle;

	ret = 1;
	amap->nb_y = 0;
	fd = 0;
	boucle = 0;
	if ((fd = open(amap->name, O_RDONLY)) == -1)
		display_error("This map is empty or invalid");
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, 1)) < 0)
			display_error("Read of map failed");
		if (*tmp == '\n' && ret != 0)
			amap->nb_y++;
		else
			boucle++;
	}
	if (boucle == 1)
		display_error("Map is empty");
	close(fd);
	return (1);
}

static void	nb_x(t_map *amap, char *line)
{
	int	i;

	i = 0;
	amap->nb_x = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] != ' ' && line[i])
			amap->nb_x++;
		while (line[i] != ' ' && line[i])
			i++;
	}
}

int			open_map(t_map *amap)
{
	int		i;
	int		fd;
	char	*line;
	char	**values;

	i = -1;
	if (!look_size_map(amap))
		return (0);
	amap->map = (char***)malloc(sizeof(amap->map) *
			((unsigned long)amap->nb_y + 1));
	if ((fd = open(amap->name, O_RDONLY)) == -1)
		display_error("Please join a correct map\n");
	while (++i < amap->nb_y)
	{
		if ((get_next_line(fd, &line)) == -1)
			display_error("Read of map failed\n");
		if (i == 0)
			nb_x(amap, line);
		values = ft_strsplit(line, ' ');
		amap->map[i] = values;
		free(line);
	}
	amap->map[i] = NULL;
	check_map(amap);
	return (1);
}
