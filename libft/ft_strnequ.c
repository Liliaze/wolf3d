/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboudy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 10:21:16 by dboudy            #+#    #+#             */
/*   Updated: 2015/12/11 15:05:41 by dboudy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	while (s1[i] && n--)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
