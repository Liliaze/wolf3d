/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:35:50 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/17 10:37:24 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		free_my_box(t_box *abox)
{
	int i;
	int j;

	i = 0;
	while (abox->box[i])
	{
		j = 0;
		while (abox->box[i][j])
		{
			ft_memdel((void **)&abox->box[i][j]);
			j++;
		}
		ft_memdel((void **)&abox->box[i]);
		i++;
	}
	free(abox->box);
	abox->box = NULL;
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
static int		look_size_box(t_box *abox, t_win *awin)
{
	char	tmp[2];
	ssize_t	ret;
	int		fd;
	int		boucle;

	ret = 1;
	abox->nb_y_box = 0;
	fd = 0;
	boucle = 0;
	if ((fd = open(abox->name_box, O_RDONLY)) == -1)
		display_error(awin, "This skybox is empty or invalid", 1);
	while (ret > 0)
	{
		if ((ret = read(fd, tmp, 1)) < 0)
			display_error(awin, "Read of skybox failed", 1);
		if (*tmp == '\n' && ret != 0)
			abox->nb_y_box++;
		else
			boucle++;
	}
	if (boucle == 1)
		display_error(awin, "Skybox file is empty", 1);
	close(fd);
	return (1);
}

static void		nb_x_box(t_box *abox, char *line)
{
	int	i;

	i = 0;
	abox->nb_x_box = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i] != ' ' && line[i])
			abox->nb_x_box++;
		while (line[i] != ' ' && line[i])
			i++;
	}
}

int			open_box(t_box *abox, t_win *awin)
{
	int		i;
	int		fd;
	char	*line;
	char	**values;

	i = -1;
	if (abox->box)
		free_my_box(abox);
	if (!look_size_box(abox, awin))
		return (0);
	abox->box = (char***)malloc(sizeof(abox->box) * ((unsigned long)abox->nb_y_box + 1));
	if ((fd = open(abox->name_box, O_RDONLY)) == -1)
		display_error(awin, "Please join a correct skybox\n", 1);
	while (++i < abox->nb_y_box)
	{
		if ((get_next_line(fd, &line)) == -1)
			display_error(awin, "Read of box failed\n", 1);
		if (i == 0)
			nb_x_box(abox, line);
		values = ft_strsplit(line, ' ');
		abox->box[i] = values;
		free(line);
	}
	abox->box[i] = NULL;
	return (1);
}
