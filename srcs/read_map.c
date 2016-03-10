/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:35:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 16:29:32 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		free_my_map(t_all *all)
{
	int i;
	int j;

	i = 0;
	ft_putstr ("\ndebut free ok\n");
	while (AM->map[i])
	{
		j = 0;
		while (AM->map[i][j])
		{
			ft_memdel((void **)&AM->map[i][j]);
			j++;
		}
		ft_memdel((void **)&AM->map[i]);
		i++;
	}
	free(AM->map);
	AM->map = NULL;
	ft_putstr ("\nfin free ok\n");
}
/*
void			zmin_and_zmax(t_all *all)
{
	int i;
	int j;

	i = 0;
	ZMAX = 0;
	ZMIN = 0;
	while (MAP[i])
	{
		j = 0;
		while (MAP[i][j])
		{
			if (ft_atoi(MAP[i][j]) * COEFZ > ZMAX)
				ZMAX = ft_atoi(MAP[i][j]) * COEFZ;
			if (ft_atoi(MAP[i][j]) * COEFZ < ZMIN)
				ZMIN = ft_atoi(MAP[i][j]) * COEFZ;
			j++;
		}
		i++;
	}
}
*/
static int		look_size_map(t_all *all)
{
	char	tmp[2];
	ssize_t	ret;
	int		fd;
	int		boucle;

	ret = 1;
	AM->map_y = 0;
	fd = 0;
	boucle = 0;
	if ((fd = open(AM->name, O_RDONLY)) == -1)
		display_error(all, "This map is empty or invalid", 1);
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, 1)) < 0)
			display_error(all, "Read of map failed", 1);
		if (*tmp == '\n' && ret != 0)
			AM->map_y++;
		else
			boucle++;
	}
	if (boucle == 1)
		display_error(all, "Map is empty", 1);
	close(fd);
	return (1);
}

static void		nb_x(t_map *map, char *line)
{
	int	i;

	i = 0;
	map->map_x = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] != ' ' && line[i])
			map->map_x++;
		while (line[i] != ' ' && line[i])
			i++;
	}
}

int				open_map(t_all *all)
{
	int		i;
	int		fd;
	char	*line;
	char	**values;

	i = -1;
	if (AM->map)
		free_my_map(all);
	if (!look_size_map(all))
		return (0);
	AM->map = (char***)malloc(sizeof(AM->map) * ((unsigned long)AM->map_y + 1));
	if ((fd = open(AM->name, O_RDONLY)) == -1)
		display_error(all, "Please join a correct map\n", 1);
	while (++i < AM->map_y)
	{
		if ((get_next_line(fd, &line)) == -1)
			display_error(all, "Read of map failed\n", 1);
		if (i == 0)
			nb_x(AM, line);
		values = ft_strsplit(line, ' ');
		AM->map[i] = values;
		free(line);
	}
	AM->map[i] = NULL;
	return (1);
}
