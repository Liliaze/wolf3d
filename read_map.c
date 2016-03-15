/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:35:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/15 16:36:44 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		free_my_map(t_map *amap)
{
	int i;
	int j;

	i = 0;
	ft_putstr("\ndebut free ok\n"); // a sup
	while (amap->map[i])
	{
		j = 0;
		while (amap->map[i][j])
		{
			ft_memdel((void **)&amap->map[i][j]);
			j++;
		}
		ft_memdel((void **)&amap->map[i]);
		i++;
	}
	free(amap->map);
	amap->map = NULL;
	ft_putstr ("\nfin free ok\n"); // a sup
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
static int		look_size_map(t_map *amap, t_win *awin)
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
		display_error(awin, "This map is empty or invalid", 1);
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, 1)) < 0)
			display_error(awin, "Read of map failed", 1);
		if (*tmp == '\n' && ret != 0)
			amap->nb_y++;
		else
			boucle++;
	}
	if (boucle == 1)
		display_error(awin, "Map is empty", 1);
	close(fd);
	return (1);
}

static void		nb_x(t_map *amap, char *line)
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

int			open_map(t_map *amap, t_win *awin)
{
	int		i;
	int		fd;
	char	*line;
	char	**values;

	i = -1;
	if (amap->map)
		free_my_map(amap);
	if (!look_size_map(amap, awin))
		return (0);
	amap->map = (char***)malloc(sizeof(amap->map) * ((unsigned long)amap->nb_y + 1));
	if ((fd = open(amap->name, O_RDONLY)) == -1)
		display_error(awin, "Please join a correct map\n", 1);
	while (++i < amap->nb_y)
	{
		if ((get_next_line(fd, &line)) == -1)
			display_error(awin, "Read of map failed\n", 1);
		if (i == 0)
			nb_x(amap, line);
		values = ft_strsplit(line, ' ');
		amap->map[i] = values;
		free(line);
	}
	amap->map[i] = NULL;
	return (1);
}
