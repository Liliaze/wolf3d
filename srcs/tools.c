/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:12:19 by dboudy            #+#    #+#             */
/*   Updated: 2016/03/10 13:47:05 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf3d.h"

void	display_error(t_all *all, char *str, int code_error)
{
	if (code_error == -1)
	{
		AH->in_menu = -1;
		mlx_clear_window(MLX, WIN);
		mlx_string_put(MLX, WIN, (int)(((unsigned long)WINW - ft_strlen(str) * 11) * 0.5),
				(int)(WINH * 0.5), RED, str);
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
