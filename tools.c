/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:12:19 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/17 11:39:56 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf3d.h"

void	clear_image(char *img, int last_pixel)
{
	int	i;
	int	*tmp;

	i = -1;
	tmp = (int*)(void*)img; //previous is DATA.
	while (++i <= last_pixel / 2)
		tmp[i] = PINK;
	while (++i < last_pixel)
		tmp[i] = YELLOW;
}

void	display_error(t_win *awin, char *str, int code_error)
{
	if (code_error == -1)
	{
		awin->in_menu = -1;
		mlx_clear_window(MLX, WIN);
		mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - ft_strlen(str)
						* 11) * 0.5), (int)(WINH * 0.5), RED, str);
		mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - 308) * 0.5),
				(int)(WINH * 0.5), RED, " === Enter to return menu ===");
	}
	else if (code_error)
	{
		ft_trace_str("31", str);
		ft_putstr("\n");
		exit(0);
	}
}
